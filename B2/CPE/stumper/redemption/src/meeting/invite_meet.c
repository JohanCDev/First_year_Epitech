/*
** EPITECH PROJECT, 2021
** REDstumper
** File description:
** invite_meet
*/

#include "calendar.h"
#include <stdlib.h>
#include "my.h"

employee_t *invite_id_in_meeting(employee_t *emp, meeting_t *meet, \
char *emp_to_add, int add_in_meeting)
{
    employee_t *current = emp->next;
    meeting_t *from_which_add = 0;
    char *itoa = my_itoa(add_in_meeting);

    from_which_add = my_find_meeting_with_meet_id(meet, itoa, &my_strcmp);
    while (current) {
        if (!from_which_add)
            return (NULL);
        if (my_getnbr(emp_to_add) == current->id) {
            from_which_add->emp_id = \
            add_id_from_array_emp_id(from_which_add->emp_id, \
            my_getnbr(emp_to_add));
            adjust_meeting_for_nb_emps(from_which_add);
        }
        current = current->next;
    }
    free(itoa);
    return current;
}

int invite_in_meeting(char **array, employee_t *emp, meeting_t *meet)
{
    int size = get_size_array((void **)array) - 1;
    int meeting_id = 0;

    if (size < 3)
        return 0;
    meeting_id = my_getnbr(array[1]);
    for (int i = 2; i < size; i++)
        invite_id_in_meeting(emp, meet, array[i], meeting_id);
    return 0;
}

char *check_date(char *date)
{
    char **array = my_str_to_word_array(date, "/");

    if (array == NULL)
        return (NULL);
    if (my_strlen(date) != 10 || get_size_array((void **)array) != 3) {
        my_free_array(array);
        return (NULL);
    }
    for (int i = 0; i < 2; i++) {
        if (my_strlen(array[i]) != 2 || my_str_isnum(array[i]) == 0) {
            my_free_array(array);
            return (NULL);
        }
    }
    if (my_strlen(array[2]) != 4 || my_str_isnum(array[2]) == 0 ||
    my_getnbr(array[0]) > 31 || my_getnbr(array[1]) > 12) {
        my_free_array(array);
        return (NULL);
    }
    my_free_array(array);
    return date;
}