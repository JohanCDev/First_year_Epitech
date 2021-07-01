/*
** EPITECH PROJECT, 2021
** Prepa_stumper
** File description:
** initialize_structure
*/

#include "calendar.h"
#include <stdlib.h>
#include "my.h"

employee_t *initialize_employee(void)
{
    employee_t *emp = malloc(sizeof(employee_t));

    if (emp == NULL)
        return (NULL);
    emp->first_name = NULL;
    emp->id = 0;
    emp->last_name = NULL;
    emp->next = NULL;
    emp->position = NULL;
    emp->zip = NULL;
    emp->fired = false;
    return emp;
}

meeting_t *initialize_meeting(void)
{
    meeting_t *meet = malloc(sizeof(meeting_t));

    if (meet == NULL)
        return (NULL);
    meet->cancel = false;
    meet->day = NULL;
    meet->emp_id = NULL;
    meet->id = 0;
    meet->next = NULL;
    meet->place = NULL;
    return meet;
}