/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myls-johan.chrillesen
** File description:
** swap_nodes
*/

#include "my.h"

void swap_nodes(linked_list_s *node1, linked_list_s *node2)
{
    s_list *tmp = node1->data;

    node1->data = node2->data;
    node2->data = tmp;
}

linked_list_s *sort_alpha(linked_list_s *list, \
linked_list_s *first_node, int rev)
{
    int done = 0;
    int swapped = 0;

    list = first_node;
    while (!done) {
        rev ? swapped = compare_nodes_alpha_rev(list) : 0;
        !rev ? swapped = compare_nodes_alpha(list) : 0;
        if (!swapped)
            done = 1;
        else
            list = first_node;
    }
    return (first_node);
}

linked_list_s *sort_time(linked_list_s *list, \
linked_list_s *first_node, int rev)
{
    int done = 0;
    int swapped = 0;

    list = first_node;
    while (!done) {
        rev ? swapped = compare_nodes_time_rev(list) : 0;
        !rev ? swapped = compare_nodes_time(list) : 0;
        if (!swapped)
            done = 1;
        else
            list = first_node;
    }
    return (first_node);
}