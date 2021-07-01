/*
** EPITECH PROJECT, 2021
** linkedl
** File description:
** sort
*/

#include "../linked_list.h"
#include <stdlib.h>
#include "../my.h"

void swap_nodes(node_t *node1, node_t *node2)
{
    node_t tmp;

    if (!node1 || !node2)
        return;
    tmp = *node1;
    *node1 = *node2;
    *node2 = tmp;
    node2->next = node1->next;
    node2->prev = node1->prev;
    node1->next = tmp.next;
    node1->prev = tmp.prev;
}

void compare_for_swap(node_t *current_node, int (*cmp)(void *, void *))
{
    if (cmp(current_node->data, current_node->next->data) > 0)
        swap_nodes(current_node, current_node->next);
}

void bubble_sort_list(linked_list_t *list, int (*cmp)(void *, void *))
{
    node_t *current_node = list->first;

    if (list->size < 2)
        return;
    for (int i = 0; i < list->size; i++) {
        current_node = list->first;
        for (int j = 0; j < list->size - i - 1; j++) {
            compare_for_swap(current_node, cmp);
            current_node = current_node->next;
        }
    }
}