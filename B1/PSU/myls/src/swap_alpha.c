/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myls-johan.chrillesen
** File description:
** swap_alpha
*/

#include "my.h"

int compare_nodes_alpha(linked_list_s *list)
{
    int swapped = 0;

    while (list->next) {
        if (my_strcmp(list->data->name_low, list->next->data->name_low) \
        > 0) {
            swap_nodes(list, list->next);
            swapped = 1;
        }
        list = list->next;
    }
    return (swapped);
}

int compare_nodes_alpha_rev(linked_list_s *list)
{
    int swapped = 0;

    while (list->next) {
        if (my_strcmp(list->data->name_low, list->next->data->name_low) \
        < 0) {
            swap_nodes(list, list->next);
            swapped = 1;
        }
        list = list->next;
    }
    return (swapped);
}