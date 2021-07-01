/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-redemption-guillaume.terriere
** File description:
** sort_meets_for_display_emps
*/

#include "my.h"
#include "calendar.h"

void swap_for_date_in_meetings_emp_and_then(meeting_t *before, \
char **array_meet1, char **array_meet2)
{
    if (my_getnbr(array_meet1[1]) == my_getnbr(array_meet2[1]) && \
        my_getnbr(array_meet1[0]) > my_getnbr(array_meet2[0]))
        swap_meet_nodes(before, before->next, before->next->next);
    else if (my_getnbr(array_meet1[0]) == my_getnbr(array_meet2[0]) && \
        my_strcmp(before->next->place, before->next->next->place) > 0)
        swap_meet_nodes(before, before->next, before->next->next);
}

void swap_for_date_in_meetings_emp(meeting_t *before, meeting_t *meet1, \
meeting_t *meet2)
{
    char **array_meet1 = my_str_to_word_array(meet1->day, "/");
    char **array_meet2 = my_str_to_word_array(meet2->day, "/");

    if (my_getnbr(array_meet1[2]) > my_getnbr(array_meet2[2])) {
        swap_meet_nodes(before, meet1, meet2);
    } else if (my_getnbr(array_meet1[2]) == my_getnbr(array_meet2[2]) && \
        my_getnbr(array_meet1[1]) > my_getnbr(array_meet2[1]))
        swap_meet_nodes(before, meet1, meet2);
    else {
        swap_for_date_in_meetings_emp_and_then(before, \
        array_meet1, array_meet2);
    }
    my_free_array(array_meet1);
    my_free_array(array_meet2);
}

void swap_for_meetings_info(meeting_t *meet)
{
    int size = get_size_list_meet(meet);
    meeting_t *current_sort = meet;

    if (size < 2)
        return;
    for (int i = 0; i < size; i++) {
        current_sort = meet;
        for (int j = 0; j < size - i - 1; j++) {
            swap_for_date_in_meetings_emp(current_sort, current_sort->next, \
            current_sort->next->next);
            current_sort = current_sort->next;
        }
    }
}