/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myls-johan.chrillesen
** File description:
** print_list
*/

#include "my.h"

void print_long_list(int nb_total_blocks, linked_list_s *first_node)
{
    linked_list_s *list = first_node;

    my_printf("total %d\n", nb_total_blocks);
    while (list) {
        my_printf("%s ", list->data->rights);
        my_printf("%d ", list->data->nlinks);
        my_printf("%s ", list->data->file_master);
        my_printf("%s ", list->data->folder_master);
        my_printf("%d ", list->data->size);
        my_printf("%s ", list->data->time);
        my_printf("%s\n", list->data->name_file);
        list = list->next;
    }
}

void print_short_list(linked_list_s *first_node)
{
    linked_list_s *list = first_node;

    while (list) {
        my_printf("%s", list->data->name_file);
        if (list->next)
            my_printf(" ");
        list = list->next;
    }
    my_putchar('\n');
}