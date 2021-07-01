/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-redemption-guillaume.terriere
** File description:
** all_verifying_sort_funct
*/

#include "calendar.h"
#include "my.h"

employee_t *sort_node_emps_by_id(employee_t *before, \
employee_t *emp1, employee_t *emp2)
{
    if (emp1->id > emp2->id) {
        swap_emp_nodes(before, emp1, emp2);
    }
    return emp1;
}