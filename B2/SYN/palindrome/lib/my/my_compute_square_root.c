/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** calcul square root
*/

#include <stdio.h>

int my_compute_square_root(int nb)
{
    int count_times = 1;
    int sub = 1;

    while (nb > 0) {
        nb -= sub;
        if (nb == 0)
            return count_times;
        if (nb < 0)
            return 0;
        count_times++;
        sub += 2;
    }
    return 0;
}