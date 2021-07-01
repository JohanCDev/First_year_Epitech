/*
** EPITECH PROJECT, 2020
** B-CPE-100-NAN-1-1-cpoolday11-johan.chrillesen
** File description:
** my_concat_list
*/

#include "mylist.h"
#include <stdio.h>

void *my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
    linked_list_t *tmp = *begin1;
    linked_list_t *tmp2 = NULL;

    while (tmp != NULL) {
        tmp2 = tmp;
        tmp = tmp->next;
    }
    tmp2->next = begin2;
    return (0);
}