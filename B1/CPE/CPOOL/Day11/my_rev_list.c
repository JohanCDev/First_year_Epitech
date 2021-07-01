/*
** EPITECH PROJECT, 2020
** my_rev_list
** File description:
** my_rev_list
*/

#include <mylist.h>
#include <stdio.h>

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *list;
    linked_list_t *tem;
    linked_list_t *tem_next;

    list = *begin;
    tem = 0;
    while (list != NULL) {
        tem_next = list->next;
        list->next = tem;
        tem = list;
        list = tem_next;
    }
    list->next = tem;
    *begin = list;
}