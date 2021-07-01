/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-redemption-guillaume.terriere
** File description:
** sort_by_name
*/

#include "my.h"
#include "calendar.h"

employee_t *sort_node_emps_by_name_and_then(employee_t *before, \
employee_t *emp1, employee_t *emp2)
{
    if (my_strcmp(emp1->first_name, emp2->first_name) == 0 && \
    emp1->id > emp2->id) {
        swap_emp_nodes(before, emp1, emp2);
    }
    return (emp1);
}

employee_t *sort_node_emps_by_name(employee_t *before, \
employee_t *emp1, employee_t *emp2)
{
    if (my_strcmp(emp1->last_name, emp2->last_name) > 0) {
        swap_emp_nodes(before, emp1, emp2);
    } else if (my_strcmp(emp1->last_name, emp2->last_name) == 0 && \
    my_strcmp(emp1->first_name, emp2->first_name) > 0) {
        swap_emp_nodes(before, emp1, emp2);
    }
    else
        sort_node_emps_by_name_and_then(before, emp1, emp2);
    return emp1;
}