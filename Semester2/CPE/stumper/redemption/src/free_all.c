/*
** EPITECH PROJECT, 2021
** Prepa_stumper
** File description:
** free_all
*/

#include "calendar.h"
#include "my.h"
#include <stdlib.h>

// int my_free_all(s_stumper *stumper)
// {
//     my_free(stumper->file_content);
//     return 0;
// }
void free_emp(employee_t *emp)
{
    my_free(emp->first_name);
    my_free(emp->last_name);
    my_free(emp->position);
    my_free(emp->zip);
}

void free_meet(meeting_t *meet)
{
    my_free(meet->day);
    my_free(meet->emp_id);
    my_free(meet->place);
}

void free_all(meeting_t *meet, employee_t *emp)
{
    employee_t *tmp;
    meeting_t *tmp2;

    while (emp) {
        tmp = emp;
        emp = emp->next;
        free_emp(tmp);
        free(tmp);
    }
    while (meet) {
        tmp2 = meet;
        meet = meet->next;
        free_meet(tmp2);
        free(tmp2);
    }
}