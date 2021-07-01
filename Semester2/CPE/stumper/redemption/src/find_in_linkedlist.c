/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** find_in_linkedlist
*/

#include "calendar.h"
#include "my.h"
#include <stdlib.h>

meeting_t *my_find_meeting_with_meet_id(meeting_t *begin, void *data_ref, \
int (*cmp)(const char *, const char *))
{
    meeting_t *current = begin;
    char *itoa = NULL;

    while (current != NULL) {
        itoa = my_itoa(current->id);
        if (cmp(data_ref, itoa) == 0) {
            free(itoa);
            return (current);
        }
        free(itoa);
        current = current->next;
    }
    return (NULL);
}

employee_t *my_find_emp_with_emp_id(employee_t *begin, void *data_ref, \
int (*cmp)(const char *, const char *))
{
    employee_t *current = begin;
    char *itoa = NULL;

    while (current != NULL) {
        itoa = my_itoa(current->id);
        if ((cmp(data_ref, itoa)) == 0) {
            free(itoa);
            return (current);
        }
        free(itoa);
        current = current->next;
    }
    return (NULL);
}

employee_t *my_find_emp_in_meeting_with_id(employee_t *begin, void *meet_id, \
int (*cmp)(const char *, const char *), int i)
{
    employee_t *current = begin;
    int j = 0;

    while (current) {
        if (cmp(meet_id, my_itoa(current->id)) && \
            my_getnbr(meet_id) != current->id && j != i)
            return (current);
        current = current->next;
        j++;
    }
    return (NULL);
}