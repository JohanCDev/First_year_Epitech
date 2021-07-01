/*
** EPITECH PROJECT, 2020
** my_getfloat
** File description:
** Display a number as a string
*/

#include <stdio.h>
#include "my.h"

float my_getfloat(char const *str)
{
    int i = 0;
    int nb = 0;
    float k = 10.0;
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
    if (str[i] == '.') {
        i++;
        while ((str[i] >= '0' && str[i] <= '9' && str[i] != '\0') || str[i] == '.') {
            final_res += (str[i] - 48) / k;
            k *= 10.0;
            i++;
        }
    }
    final_res += nb;
    final_res *= minus;
    return (final_res);
}