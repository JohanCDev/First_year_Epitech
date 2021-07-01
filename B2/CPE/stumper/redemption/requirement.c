/*
** EPITECH PROJECT, 2021
** stumper_redemption
** File description:
** requirement
*/

#include "requirement.h"
#include <stdlib.h>

int my_revlist_synthesis(list_t **begin)
{
    list_t *current = *begin;
    list_t *prev = NULL;
    list_t *next = NULL;

    if (current == NULL)
        return 84;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *begin = prev;
    return 0;
}

list_t *my_findnodeeqinlist_synthesis(list_t *begin, \
void *data_ref, int (*cmp)(void *, void *))
{
    list_t *current = begin;

    while (current != NULL) {
        if (cmp(data_ref, current->data) == 0)
            return (current);
        current = current->next;
    }
    return (NULL);
}