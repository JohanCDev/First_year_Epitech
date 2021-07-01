/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myrunner-johan.chrillesen
** File description:
** my_itoa
*/

#include "my.h"

char *my_itoa(int nb)
{
    char *b = malloc(sizeof(char) * 12);
    char const *digit = "0123456789";
    char *p = b;
    int tmp = 0;

    if (nb < 0) {
        *p++ = '-';
        nb *= -1;
    }
    tmp = nb;
    while (tmp) {
        ++p;
        tmp /= 10;
    }
    *p = '\0';
    while (nb) {
        *--p = digit[nb % 10];
        nb /= 10;
    }
    return (b);
}