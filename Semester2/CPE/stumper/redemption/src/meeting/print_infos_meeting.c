/*
** EPITECH PROJECT, 2021
** Prepa_stumper
** File description:
** print_infos
*/

#include "my.h"
#include "calendar.h"
#include <stdlib.h>

void print_emp_in_meeting(meeting_t *meet, employee_t *emp, \
employee_t *current_emp)
{
    char *itoa = NULL;

    for (int j = 0; meet->emp_id[j] != -1; j++) {
        itoa = my_itoa(meet->emp_id[j]);
        current_emp = my_find_emp_with_emp_id(emp, itoa, &my_strcmp);
        my_printf("%s %s", current_emp->first_name, current_emp->last_name);
        if (meet->emp_id[j + 1] != -1)
            my_printf(", ");
        free(itoa);
    }
    my_printf("\n");
}

int print_infos_meetings(employee_t *emp, meeting_t *meet)
{
    employee_t *current_emp = emp;

    if (meet->day && meet->emp_id && meet->place) {
        for (int i = 0; i < 30; i++)
            my_printf("*");
        my_printf("\nMEETING\n");
        my_printf("date: %s\n", meet->day);
        my_printf("place: %s\n", meet->place);
        my_printf("with ");
        print_emp_in_meeting(meet, emp, current_emp);
    }
    return 0;
}

void check_id_meeting(meeting_t *current, employee_t *emp, \
char **array, int size)
{
    if (size == 2) {
        print_infos_meetings(emp, current);
        return;
    }
    for (int i = 2; i <= size; i++)
        if (current->id == my_getnbr(array[i]) && current->cancel == 0)
            print_infos_meetings(emp, current);
}

int display_info_meetings(char **array, employee_t *emp, meeting_t *meet)
{
    meeting_t *current = meet;
    int size = get_size_array((void **)array) - 1;

    if (size < 2)
        return 0;
    if (!my_strcmp(array[1], "sortByDate") || \
    !my_strcmp(array[1], "sortByZip") || \
    !my_strcmp(array[1], "sortById")) {
        swap_meet_with_condition(meet, array[1]);
        while (current) {
            check_id_meeting(current, emp, array, size);
            current = current->next;
        }
    }
    return 0;
}