/*
** EPITECH PROJECT, 2020
** B-CPE-100-NAN-1-1-cpoolday11-johan.chrillesen
** File description:
** my_find_node
*/

#include "mylist.h"
#include <stdio.h>

linked_list_t *my_find_node(linked_list_t const *begin, void const *data_ref\
, int (*cmp)())
{
    linked_list_t *tmp = (linked_list_t *) begin;

    while (tmp != NULL) {
        if (cmp(tmp->data, data_ref) == 0) {
            return (tmp);
        }
        tmp = tmp->next;
    }
    return (0);
}