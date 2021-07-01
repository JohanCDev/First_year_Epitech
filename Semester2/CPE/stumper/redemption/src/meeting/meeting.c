/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** create_meeting
*/

#include "calendar.h"
#include <stdlib.h>
#include "my.h"
#include <stdbool.h>

bool emp_id_is_in_array(int j, char *str, meeting_t *new)
{
    bool found = 0;

    for (int x = j - 1; x >= 0; x--) {
        if (new->emp_id[x] == my_getnbr(str)) {
            found = 1;
            break;
        }
    }
    return (found);
}

int *create_emp_id(meeting_t *new, employee_t *emp, char **array)
{
    int j = 0;
    bool found = 0;

    for (int k = 4; array[k]; k++) {
        if (my_find_emp_with_emp_id(emp, array[k], &my_strcmp) == NULL) {
            my_printf("Hey Out\n");
            return NULL;
        }
        found = emp_id_is_in_array(j, array[k], new);
        if (found == 0) {
            new->emp_id[j] = my_getnbr(array[k]);
            j++;
        }
    }
    new->emp_id[j - 1] = -1;
    return new->emp_id;
}

void go_to_last_node(meeting_t *new, meeting_t *meet)
{
    while (meet->next)
        meet = meet->next;
    meet->next = new;
}

int check_new_meeting(int size, char **array)
{
    char *date = my_strdup(array[2]);

    if (size < 6 || check_date(date) == NULL) {
        free(date);
        return 0;
    }
    free(date);
    return 1;
}

int create_new_meeting(char **array, employee_t *emp, meeting_t *meet)
{
    meeting_t *new = initialize_meeting();
    int size = get_size_array((void **)array) - 1;
    meeting_t *current = meet;

    if (new == NULL)
        return -1;
    if (check_new_meeting(size, array) == 0)
        return 0;
    if (my_find_meeting_with_meet_id(meet, array[3], &my_strcmp) != NULL)
        return my_put_error("This id of meeting already exists.", 0);
    new->place = my_strdup(array[1]);
    new->day = my_strdup(array[2]);
    new->id = my_getnbr(array[3]);
    if ((new->emp_id = malloc(sizeof(int) * (size - 3))) == NULL)
        return my_put_error("Error malloc\n", -1);
    if ((new->emp_id = create_emp_id(new, emp, array)) == NULL)
        return 0;
    if (nb_emps_in_meeting(new) <= 1)
        new->cancel = 1;
    go_to_last_node(new, current);
    return 0;
}