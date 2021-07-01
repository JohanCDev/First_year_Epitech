/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-pushswap-johan.chrillesen
** File description:
** my_put_int_list
*/

#include "my.h"

void my_put_int_list(int *list, int size)
{
    int i = 0;

    while (i < size) {
        my_put_nbr(*list++);
        my_putchar(' ');
        i++;
    }
    my_putchar('\n');
}