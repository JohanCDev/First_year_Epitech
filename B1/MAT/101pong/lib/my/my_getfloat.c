/*
** EPITECH PROJECT, 2020
** my_getfloat
** File description:
** Display a number as a string
*/

#include <stdio.h>
#include "my.h"

float check_period(char const *str, int counter) {
    float k = 10.0;
    float final_res = 0.0;

    if (str[counter] == '.') {
        counter++;
        while ((str[counter] >= '0' && str[counter] <= '9' && str[counter] \
        != '\0') || str[counter] == '.') {
            final_res += (str[counter] - 48) / k;
            k *= 10.0;
            counter++;
        }
    }
    return (final_res);
}

float my_getfloat(char const *str)
{
    int i = 0;
    int nb = 0;
    float final_res = 0.0;
    float minus = 1.0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-') {
            minus = -minus;
        }
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0') {
        nb = (nb * 10) + (str[i] - 48);
        i++;
    }
    final_res = check_period(str, i);
    final_res += nb;
    final_res *= minus;
    return (final_res);
}

