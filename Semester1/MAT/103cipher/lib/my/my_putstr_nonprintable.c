/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myprintf-johan.chrillesen
** File description:
** my_putstr_nonprintable
*/

#include "../../include/my.h"

void check_length_res(char str)
{
    if (str <= '\a')
        my_putstr("00");
    else if (str <= '?')
        my_putchar('0');
}

void my_putstr_nonprintable(char const *str)
{
    while (*str != '\0') {
        if (*str <= 31 || *str >= 127) {
            my_putchar('\\');
            check_length_res(*str);
            my_putnbr_base_int(*str, "01234567");
        } else
            my_putchar(*str);
        str++;
    }
}