/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** cancel_and_exclude_meet
*/

#include "calendar.h"
#include <stdlib.h>
#include "my.h"

void adjust_meeting_for_nb_emps(meeting_t *meet)
{
    if (count_int_tab(meet->emp_id) < 2)
        meet->cancel = 1;
    else
        meet->cancel = 0;
}

employee_t *remove_id_from_meeting(employee_t *emp, meeting_t *meet, \
char *emp_to_remove, int remove_from_meeting)
{
    employee_t *current = emp->next;
    meeting_t *from_which_remove = 0;
    char *itoa = my_itoa(remove_from_meeting);

    from_which_remove = my_find_meeting_with_meet_id(meet, itoa, &my_strcmp);
    while (current) {
        if (my_getnbr(emp_to_remove) == current->id) {
            from_which_remove->emp_id = \
            remove_id_from_array_emp_id(from_which_remove->emp_id, \
            my_getnbr(emp_to_remove));
            adjust_meeting_for_nb_emps(from_which_remove);
        }
        current = current->next;
    }
    free(itoa);
    return current;
}

int exclude_of_meeting(char **array, employee_t *emp, meeting_t *meet)
{
    int size = get_size_array((void **)array) - 1;
    int meeting_id = 0;

    if (size < 3)
        return 0;
    meeting_id = my_getnbr(array[1]);
    if (my_find_meeting_with_meet_id(meet, array[1], &my_strcmp) == NULL)
        return 0;
    for (int i = 2; i < size; i++)
        remove_id_from_meeting(emp, meet, array[i], meeting_id);
    return 0;
}

meeting_t *set_cancel_value(meeting_t *current, char **array, int size)
{
    for (int i = 1; i <= size; i++) {
        if (my_getnbr(array[i]) == current->id)
            current->cancel = true;
    }
    return current;
}

int cancel_meeting(char **array, employee_t *emp, meeting_t *meet)
{
    meeting_t *current = meet;
    int size = get_size_array((void **)array) - 1;

    if (size < 2)
        return 0;
    while (current) {
        set_cancel_value(current, array, size);
        current = current->next;
    }
    (void) emp;
    return 0;
}