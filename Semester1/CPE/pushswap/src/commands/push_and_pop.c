/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-bspushswap-johan.chrillesen
** File description:
** push_and_pop
*/

#include "my.h"
#include "pushswap.h"

list push(list lists)
{
    int tmp = lists.l_a[0];
    lists.size_l_b++;
    if (lists.size_l_b > 1)
        lists = rotate_right_b(lists);
    lists.l_b[0] = tmp;
    if (lists.size_l_a > 1)
        lists = rotate_a(lists);
    lists.size_l_a--;
    return (lists);
}

list pop(list lists)
{
    int tmp = lists.l_b[0];
    lists.size_l_a++;
    if (lists.size_l_a > 1)
        lists = rotate_right_a(lists);
    lists.l_a[0] = tmp;
    if (lists.size_l_b > 1)
        lists = rotate_b(lists);
    lists.size_l_b--;
    return (lists);
}