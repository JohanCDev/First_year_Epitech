/*
** EPITECH PROJECT, 2021
** linkedl
** File description:
** utils
*/

#include "../linked_list.h"
#include <stdlib.h>
#include "../my.h"

int get_size_list(linked_list_t *list)
{
    if (list)
        return (list->size);
    return my_put_error("List do not exist in get_size_list\n", -1);
}

int print_list_int(linked_list_t *list)
{
    node_t *current = NULL;

    if (!list || !list->first)
        return -1;
    current = list->first;
    while (current) {
        if (current->data)
            printf("%d\n", *(int *)current->data);
        else
            return my_put_error("Data is null\n", -1);
        current = current->next;
    }
    return 0;
}

int print_list_str(linked_list_t *list)
{
    node_t *current = NULL;

    if (!list || !list->first)
        return -1;
    current = list->first;
    while (current) {
        if (current->data)
            printf("%s\n", (char *)current->data);
        else
            return -1;
        current = current->next;
    }
    return 0;
}