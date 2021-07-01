/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-bspushswap-johan.chrillesen
** File description:
** my_print_int_array
*/

#include "my.h"

void my_print_int_array(int *array, int size)
{
    for (int i = 0; i < size; i++) {
        my_put_nbr(array[i]);
        if (i != size - 1)
            my_putstr(", ");
    }
    my_putchar('\n');
}