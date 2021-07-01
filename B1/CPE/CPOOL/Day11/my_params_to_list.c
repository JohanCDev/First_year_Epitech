/*
** EPITECH PROJECT, 2020
** my_params_to_list
** File description:
** from arguments to linked list
*/

#include <stdio.h>
#include "mylist.h"
#include <stdlib.h>

linked_list_t *my_put_in_list(void *data, linked_list_t *list)
{
    linked_list_t *new;

    new = malloc(sizeof(linked_list_t));
    new->data = data;
    new->next = list;
    return (new);
}

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *list;

    list = NULL;
    for (int i = 0; i < ac; i++) {
        list = my_put_in_list(av[i], list);
    }
    return (list);
}