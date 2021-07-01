/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-pushswap-johan.chrillesen
** File description:
** commands
*/

#include "my.h"
#include "pushswap.h"

list push_into_a(list lists)
{
    lists = pop(lists);
    return (lists);
}

list push_into_b(list lists)
{
    lists = push(lists);
    return (lists);
}

list swap_a(list lists)
{
    if (lists.size_l_a > 1) {
        int tmp = lists.l_a[0];
        lists.l_a[0] = lists.l_a[1];
        lists.l_a[1] = tmp;
    }
    return (lists);
}

list swap_b(list lists)
{
    if (lists.size_l_b > 1) {
        int tmp = lists.l_b[0];
        lists.l_b[0] = lists.l_b[1];
        lists.l_b[1] = tmp;
    }
    return (lists);
}