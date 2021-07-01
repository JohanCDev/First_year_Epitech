/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-bspushswap-johan.chrillesen
** File description:
** rotate_left
*/

#include "my.h"
#include "pushswap.h"

list rotate_a(list lists)
{
    if (lists.size_l_a > 1) {
        int tmp = lists.l_a[0];

        for (int i = 0; i < (lists.size_l_a - 1); i++)
            lists.l_a[i] = lists.l_a[i + 1];
        lists.l_a[lists.size_l_a - 1] = tmp;
    }
    return (lists);
}

list rotate_b(list lists)
{
    if (lists.size_l_b > 1) {
        int tmp = lists.l_b[0];

        for (int i = 0; i < (lists.size_l_b - 1); i++)
            lists.l_b[i] = lists.l_b[i + 1];
        lists.l_b[lists.size_l_b - 1] = tmp;
    }
    return (lists);
}

list rotate_right_a(list lists)
{
    if (lists.size_l_a > 1) {
        int tmp = 0;

        tmp = lists.l_a[lists.size_l_a - 1];
        for (int i = (lists.size_l_a - 1); i > 0; i--)
            lists.l_a[i] = lists.l_a[i - 1];
        lists.l_a[0] = tmp;
    }
    return (lists);
}

list rotate_right_b(list lists)
{
    if (lists.size_l_b > 1) {
        int tmp = 0;

        tmp = lists.l_b[lists.size_l_b - 1];
        for (int i = (lists.size_l_b - 1); i > 0; i--)
            lists.l_b[i] = lists.l_b[i - 1];
        lists.l_b[0] = tmp;
    }
    return (lists);
}