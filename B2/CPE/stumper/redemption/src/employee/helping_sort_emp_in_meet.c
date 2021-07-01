/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-redemption-guillaume.terriere
** File description:
** helping_sort_emp_in_meet
*/

#include "my.h"
#include "calendar.h"

void swap_emp_id_ids_if_needed_then(employee_t *emp, int first, int second)
{
    if (my_strcmp(my_find_emp_with_emp_id(emp, my_itoa(first), \
        &my_strcmp)->first_name, \
        my_find_emp_with_emp_id(emp, my_itoa(second), &my_strcmp)->first_name) \
        == 0 && my_find_emp_with_emp_id(emp, my_itoa(first), \
        &my_strcmp)->id > \
        my_find_emp_with_emp_id(emp, my_itoa(second), &my_strcmp)->id)
        my_swap_int(&first, &second);
}

void swap_emp_id_ids_if_needed(employee_t *emp, int first, int second)
{
    if (my_strcmp(my_find_emp_with_emp_id(emp, my_itoa(first), \
        &my_strcmp)->last_name, \
        my_find_emp_with_emp_id(emp, my_itoa(second), &my_strcmp)->last_name) \
        > 0)
        my_swap_int(&first, &second);
    else if (my_strcmp(my_find_emp_with_emp_id(emp, my_itoa(first), \
        &my_strcmp)->last_name, \
        my_find_emp_with_emp_id(emp, my_itoa(second), &my_strcmp)->last_name) \
        == 0 && my_strcmp(my_find_emp_with_emp_id(emp, my_itoa(first), \
        &my_strcmp)->first_name, \
        my_find_emp_with_emp_id(emp, my_itoa(second), &my_strcmp)->first_name) \
        > 0)
        my_swap_int(&first, &second);
    else
        swap_emp_id_ids_if_needed_then(emp, first, second);
}