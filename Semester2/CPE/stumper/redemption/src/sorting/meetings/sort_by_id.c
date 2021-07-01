/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-redemption-guillaume.terriere
** File description:
** sort_by_id
*/

#include "calendar.h"
#include "my.h"

meeting_t *sort_node_meet_by_id(meeting_t *before, meeting_t *meet1, \
meeting_t *meet2)
{
    if (meet1->id > meet2->id)
        swap_meet_nodes(before, meet1, meet2);
    return meet1;
}