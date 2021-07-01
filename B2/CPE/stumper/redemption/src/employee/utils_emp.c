/*
** EPITECH PROJECT, 2021
** REDstumper
** File description:
** utils_emp
*/

#include "my.h"
#include "calendar.h"

int find_int_in_int_array(int *array, int to_find)
{
    for (int i = 0; array[i] != -1; i++)
        if (array[i] == to_find)
            return (1);
    return (0);
}

int check_all_meetings(meeting_t *meet, int id)
{
    meeting_t *current = meet;
    int size = 0;

    while (current) {
        cancel_meeting_if_needed(current, id, size);
        current = current->next;
    }
    return 0;
}

int is_in_other_meet(meeting_t *meet, int emp_id)
{
    meeting_t *actual_meet = meet;

    while (actual_meet) {
        if (find_int_in_int_array(actual_meet->emp_id, emp_id) == 1)
            return 1;
        actual_meet = actual_meet->next;
    }
    return 0;
}

void print_other_emp_in_meet(employee_t *actual_emp, meeting_t *actual_meet, \
employee_t *emp)
{
    employee_t *current = emp;
    int end = count_int_tab(actual_meet->emp_id) - 1;
    int cnt = 0;

    while (current) {
        if (current != actual_emp && \
        find_int_in_int_array(actual_meet->emp_id, current->id)) {
            my_printf("%s %s", current->first_name, current->last_name);
            cnt++;
            cnt < end ? my_printf(", ") : 0;
        }
        current = current->next;
    }
}