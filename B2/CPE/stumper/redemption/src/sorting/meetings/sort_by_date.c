/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-redemption-guillaume.terriere
** File description:
** sort_by_date
*/

#include "calendar.h"
#include "my.h"

meeting_t *sort_meet_by_date_and_then(meeting_t *before, \
char **array_meet1, char **array_meet2)
{
    if (my_getnbr(array_meet1[1]) == my_getnbr(array_meet2[1]) && \
    my_getnbr(array_meet1[0]) > my_getnbr(array_meet2[0])) {
        swap_meet_nodes(before, before->next, before->next->next);
    } else if (my_getnbr(array_meet1[0]) == my_getnbr(array_meet2[0]))
        sort_node_meet_by_id(before, before->next, before->next->next);
    return before;
}

meeting_t *sort_node_meet_by_date(meeting_t *before, meeting_t *meet1, \
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
        sort_meet_by_date_and_then(before, \
        array_meet1, array_meet2);
    }
    my_free_array(array_meet1);
    my_free_array(array_meet2);
    return meet1;
}