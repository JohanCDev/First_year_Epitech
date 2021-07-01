/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share
** File description:
** my_itoa
*/

#include <stdlib.h>

int check_zero_and_negative(char *p, int nb)
{
    if (nb == 0)
        return (0);
    if (nb < 0) {
        *p++ = ' ';
        return (-nb);
    }
    return (nb);
}

char *my_itoa(int nb)
{
    char *b = malloc(sizeof(char) * 12);
    char const *digit = "0123456789";
    char *p = b;
    int tmp = 0;

    if (!(nb = check_zero_and_negative(p, nb)))
        return ("0");
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
