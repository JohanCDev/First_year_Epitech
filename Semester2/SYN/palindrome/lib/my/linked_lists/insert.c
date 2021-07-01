/*
** EPITECH PROJECT, 2021
** linkedl
** File description:
** insert
*/

#include "../linked_list.h"
#include <stdlib.h>
#include "../my.h"

node_t *insert_first_in_list(node_t *node_to_add, linked_list_t *list)
{
    if (!node_to_add || !list) {
        return my_put_error_ret_ptr\
            ("Node or list is NULL in insert first\n", NULL);
    }
    if (list->size == 0) {
        list->first = node_to_add;
        list->last = node_to_add;
    } else {
        node_to_add->next = list->first;
        list->first->prev = node_to_add;
        list->first = node_to_add;
    }
    node_to_add->prev = NULL;
    list->size++;
    return node_to_add;
}

node_t *insert_last_in_list(node_t *node_to_add, linked_list_t *list)
{
    if (!node_to_add || !list) {
        return my_put_error_ret_ptr\
            ("Node or list is NULL in insert last\n", NULL);
    }
    if (list->size == 0) {
        list->first = node_to_add;
        list->last = node_to_add;
    } else {
        node_to_add->prev = list->last;
        list->last->next = node_to_add;
        list->last = node_to_add;
    }
    node_to_add->next = NULL;
    list->size++;
    return node_to_add;
}