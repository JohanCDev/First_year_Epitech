/*
** EPITECH PROJECT, 2020
** my_apply_on_nodes
** File description:
** my_apply_on_nodes
*/

#include "mylist.h"
#include <stdio.h>

int my_apply_on_nodes(linked_list_t *begin, int(*f)(void *))
{
    while (begin->next != NULL) {
        (*f)(begin->data);
        begin = begin->next;
    }
    return (0);
}