/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** employee
*/

#include "calendar.h"
#include "my.h"

int create_new_employee(char **array, employee_t *emp, meeting_t *meet)
{
    (void) meet;
    employee_t *new = initialize_employee();
    employee_t *current = emp;
    int size = get_size_array((void **)array) - 1;

    if (new == NULL)
        return -1;
    if (size != 6)
        return 0;
    new->last_name = my_strdup(array[1]);
    new->first_name = my_strdup(array[2]);
    new->position = my_strdup(array[3]);
    new->zip = my_strdup(array[4]);
    if (!new->last_name || !new->first_name || !new->position || !new->zip)
        return -1;
    new->id = my_getnbr(array[5]);
    while (current->next)
        current = current->next;
    current->next = new;
    return 0;
}

meeting_t *rm_id(meeting_t *current, int id)
{
    for (int i = 0; current->emp_id[i]; i++) {
        if (current->emp_id[i] == id)
            current->emp_id = remove_id_from_array_emp_id(\
            current->emp_id, id);
    }
    return current;
}

meeting_t *cancel_meeting_if_needed(meeting_t *current, int id, int size)
{
    if (current->emp_id && current->emp_id[0] != -1) {
        current->emp_id = remove_id_from_array_emp_id(current->emp_id, id);
        size = count_int_tab(current->emp_id);
        if (size >= 2)
            current->cancel = 0;
        else
            current->cancel = 1;
    }
    return current;
}

employee_t *set_employee_fired(employee_t *emp, meeting_t *meet, \
char *str)
{
    employee_t *current = emp->next;

    while (current) {
        if (my_find_emp_with_emp_id(current, str, &my_strcmp) == NULL) {
            return NULL;
        }
        if (my_getnbr(str) == current->id) {
            current->fired = true;
            check_all_meetings(meet, current->id);
        }
        current = current->next;
    }
    return current;
}

int fire_employee(char **array, employee_t *emp, meeting_t *meet)
{
    int size = get_size_array((void **)array) - 1;

    if (size < 2)
        return 0;
    for (int i = 1; i < size; i++)
        set_employee_fired(emp, meet, array[i]);
    return 0;
}