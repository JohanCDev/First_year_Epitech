/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myls-johan.chrillesen
** File description:
** swap_time
*/

#include "my.h"

int compare_nodes_time_rev(linked_list_s *list)
{
    int swapped = 0;

    while (list->next) {
        if (list->data->elapsed_time < list->next->data->elapsed_time) {
            swap_nodes(list, list->next);
            swapped = 1;
        }
        list = list->next;
    }
    return (swapped);
}

int compare_nodes_time(linked_list_s *list)
{
    int swapped = 0;

    while (list->next) {
        if (list->data->elapsed_time > list->next->data->elapsed_time) {
            swap_nodes(list, list->next);
            swapped = 1;
        }
        list = list->next;
    }
    return (swapped);
}