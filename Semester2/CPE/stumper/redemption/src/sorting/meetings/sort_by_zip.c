/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-redemption-guillaume.terriere
** File description:
** sort_by_zip
*/

#include "my.h"
#include "calendar.h"

meeting_t *sort_node_meet_by_zip(meeting_t *before, meeting_t *meet1, \
meeting_t *meet2)
{
    if (my_strcmp(meet1->place, meet2->place) > 0) {
        swap_meet_nodes(before, meet1, meet2);
    } else if (my_strcmp(meet1->place, meet2->place) == 0)
        sort_node_meet_by_id(before, meet1, meet2);
    return meet1;
}