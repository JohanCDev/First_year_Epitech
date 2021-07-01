/*
** EPITECH PROJECT, 2021
** REDstumper
** File description:
** print_infos_emp
*/

#include "my.h"
#include "calendar.h"

void display_emp_in_meet(meeting_t *current_meet, employee_t *actual_emp, \
employee_t *emp)
{
    if (find_int_in_int_array(current_meet->emp_id, \
    actual_emp->id) == 1) {
        my_printf("meeting on %s, %s, with ", current_meet->day, \
        current_meet->place);
        print_other_emp_in_meet(actual_emp, current_meet, emp);
        if (is_in_other_meet(current_meet, actual_emp->id))
            my_printf("\n");
    }
}

void loop_display_emp(meeting_t *current_meet, employee_t *actual_emp, \
employee_t *emp)
{
    int size = count_int_tab(current_meet->emp_id);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            swap_emp_id_ids_if_needed(emp, current_meet->emp_id[j], \
            current_meet->emp_id[j + 1]);
        }
    }
    while (current_meet) {
        if (current_meet->emp_id && !current_meet->cancel)
            display_emp_in_meet(current_meet, actual_emp, emp);
        current_meet = current_meet->next;
    }
}

int print_infos_employees(employee_t *actual_emp, meeting_t *meet, \
employee_t *emp)
{
    meeting_t *current_meet = meet;

    swap_for_meetings_info(meet);
    if (actual_emp->last_name && actual_emp->first_name && \
    actual_emp->position && actual_emp->zip) {
        for (int i = 0; i < 30; i++)
            my_printf("*");
        my_printf("\n");
        my_printf("%s %s\n", actual_emp->first_name, actual_emp->last_name);
        my_printf("position: %s\n", actual_emp->position);
        my_printf("city: %s\n", actual_emp->zip);
        loop_display_emp(current_meet->next, actual_emp, emp);
    }
    return 0;
}

void check_print_emp(employee_t *current, meeting_t *meet, \
employee_t *emp, char **array)
{
    int size = get_size_array((void **)array) - 1;

    if (size == 2) {
        print_infos_employees(current, meet, emp);
        return;
    }
    for (int i = 2; i <= size; i++) {
        if (current->id == my_getnbr(array[i]) && !current->fired)
            print_infos_employees(current, meet, emp);
    }
}

int display_info_employees(char **array, employee_t *emp, meeting_t *meet)
{
    employee_t *current = emp;
    int size = get_size_array((void **)array);

    if (size < 2)
        return 0;
    if (!my_strcmp(array[1], "sortByName") || \
    !my_strcmp(array[1], "sortByForename") || \
    !my_strcmp(array[1], "sortByJob") || \
    !my_strcmp(array[1], "sortById") || !my_strcmp(array[1], "sortByZip")) {
        swap_emp_with_condition(emp, array[1]);
        while (current) {
            check_print_emp(current, meet, emp, array);
            current = current->next;
        }
    }
    return 0;
}