/*
** EPITECH PROJECT, 2020
** my_putfloat
** File description:
** Display a number as a string
*/

#include <stdio.h>
#include <math.h>
#include "../includes/bsprintf.h"

void put_zeros(int nb_after_comma)
{
    for (int i = 0; i != nb_after_comma; i++) {
        my_putchar('0');
    }
}

void put_decimal(double floater, int nb_after_comma)
{
    if (floater < 10 && floater != 0)
        my_put_nbr(floater * 10);
    else if (floater >= 10 && floater != 0) {
        if (((floater - (floater * 10)) >= 5))
            floater = floater + 1;
        my_put_nbr(floater);
    }
    else
        put_zeros(nb_after_comma);
}

void my_put_float_with_dec(float nbr, int nb_after_comma)
{
    int sup = (int)nbr;
    double temp = (nbr * my_pow(10, nb_after_comma)) - \
    (sup * my_pow(10, nb_after_comma));
    double floater = (int)temp;
    int is_neg = 1;

    if (sup < 0)
        is_neg = -1;
    floater *= is_neg;
    my_put_nbr(sup);
    my_putchar('.');
}