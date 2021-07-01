/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** desc
*/

#include "my.h"

void my_putchar(char c);

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
    return (0);
}

void put_zeros(char *str, int i)
{
    if (str[i] < 63)
        my_putchar('0');
    if (str[i] < 8)
        my_putchar('0');
}

void my_putstr_np(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            put_zeros(str, i);
            my_put_nbr(convert_decimal_to_octal(str[i]));
        } else
            my_putchar(str[i]);
        i++;
    }
}
