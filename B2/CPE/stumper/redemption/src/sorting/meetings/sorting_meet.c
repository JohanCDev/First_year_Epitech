/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-redemption-guillaume.terriere
** File description:
** sorting
*/

#include "my.h"
#include "calendar.h"
#include <stdlib.h>

int get_sum_string(char *str)
{
    int size = 0;

    for (int i = 0; str[i]; i++) {
        size += str[i];
    }
    return size;
}

void swap_meet_nodes(meeting_t *before, meeting_t *meet1, meeting_t *meet2)
{
    meeting_t *tmp_before_next = before->next;

    if (!meet2 || !meet1)
        return;
    before->next = meet1->next;
    meet1->next = meet2->next;
    meet2->next = tmp_before_next;
}

int get_size_list_meet(meeting_t *meet)
{
    meeting_t *current = meet;
    int size = 0;

    while (current) {
        size++;
        current = current->next;
    }
    return size - 1;
}

void my_sort_meet(meeting_t *meet, \
meeting_t *(*sort)(meeting_t *, meeting_t *, meeting_t *))
{
    int size = get_size_list_meet(meet);
    meeting_t *current_sort = meet;

    if (size < 2)
        return;
    for (int i = 0; i < size; i++) {
        current_sort = meet;
        for (int j = 0; j < size - i - 1; j++) {
            sort(current_sort, current_sort->next, current_sort->next->next);
            current_sort = current_sort->next;
        }
    }
}

meeting_t *swap_meet_with_condition(meeting_t *meet, char *data_ref)
{
    switch (get_sum_string(data_ref)) {
    case SORTBYDATE:
        my_sort_meet(meet, &sort_node_meet_by_date);
        break;
    case SORTBYZIP:
        my_sort_meet(meet, &sort_node_meet_by_zip);
        break;
    case SORTBYID:
        my_sort_meet(meet, &sort_node_meet_by_id);
        break;
    default:
        break;
    }
    return (meet);
}