/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-redemption-guillaume.terriere
** File description:
** sorting
*/

#include "my.h"
#include "calendar.h"
#include <stdlib.h>

void swap_emp_nodes(employee_t *before, employee_t *emp1, employee_t *emp2)
{
    employee_t *tmp_before_next = before->next;

    if (!emp2 || !emp1)
        return;
    before->next = emp1->next;
    emp1->next = emp2->next;
    emp2->next = tmp_before_next;
}

int get_size_list_emp(employee_t *emp)
{
    employee_t *current = emp;
    int size = 0;

    while (current) {
        size++;
        current = current->next;
    }
    return size - 1;
}

void my_sort_emp(employee_t *emp, \
employee_t *(*sort)(employee_t *, employee_t *, employee_t *))
{
    int size = get_size_list_emp(emp);
    employee_t *current_sort = emp;

    if (size < 2)
        return;
    for (int i = 0; i < size; i++) {
        current_sort = emp;
        for (int j = 0; j < size - i - 1; j++) {
            sort(current_sort, current_sort->next, current_sort->next->next);
            current_sort = current_sort->next;
        }
    }
}

employee_t *swap_emp_with_condition(employee_t *emp, char *data_ref)
{
    switch (get_sum_string(data_ref)) {
    case SORTBYNAME:
        my_sort_emp(emp, &sort_node_emps_by_name);
        break;
    case SORTBYFORENAME:
        my_sort_emp(emp, &sort_node_emps_by_forename);
        break;
    case SORTBYJOB:
        my_sort_emp(emp, &sort_node_emps_by_job);
        break;
    case SORTBYZIP:
        my_sort_emp(emp, &sort_node_emps_by_zip);
        break;
    case SORTBYID:
        my_sort_emp(emp, &sort_node_emps_by_id);
        break;
    default:
        break;
    }
    return (emp);
}