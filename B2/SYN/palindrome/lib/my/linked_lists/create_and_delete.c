/*
** EPITECH PROJECT, 2021
** linkedl
** File description:
** create
*/

#include "../linked_list.h"
#include <stdlib.h>
#include "../my.h"

linked_list_t *new_linked_list(void)
{
    linked_list_t *list = malloc(sizeof(linked_list_t));

    if (list == NULL)
        return NULL;
    list->first = NULL;
    list->last = NULL;
    list->size = 0;
    return list;
}

node_t *new_node(void *data)
{
    node_t *node = malloc(sizeof(node_t));

    if (node == NULL || !data)
        return NULL;
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void free_data(void *data)
{
    if (data != NULL) {
        free(data);
        data = NULL;
    }
}

int delete_node(node_t *node_to_delete, linked_list_t *list)
{
    if (!node_to_delete || !list)
        return my_put_error("Node or list is NULL in delete_node\n", -1);
    if (list->first == node_to_delete) {
        if (list->size == 1) {
            list->first = NULL;
            list->last = NULL;
        }
        list->first = node_to_delete->next;
    } else if (node_to_delete == list->last) {
        list->last = node_to_delete->prev;
        node_to_delete->prev->next = NULL;
    } else {
        node_to_delete->next->prev = node_to_delete->prev;
        node_to_delete->prev->next = node_to_delete->next;
    }
    list->size--;
    free_data(node_to_delete->data);
    free(node_to_delete);
    node_to_delete = NULL;
    return 0;
}

void delete_list(linked_list_t *list)
{
    while (list->last) {
        delete_node(list->last, list);
    }
    free(list);
    list = NULL;
}