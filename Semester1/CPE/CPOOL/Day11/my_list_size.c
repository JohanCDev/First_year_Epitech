/*
** EPITECH PROJECT, 2020
** my_list_size
** File description:
** my_list_size
*/

#include <stdio.h>
#include "mylist.h"

int my_list_size(linked_list_t const * begin)
{
    int count = 0;

    while (begin != NULL) {
        begin = begin->next;
        count++;
    }
    return (count);
}