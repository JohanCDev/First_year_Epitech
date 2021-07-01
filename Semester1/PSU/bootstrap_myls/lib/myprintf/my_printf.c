/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myprintf-johan.chrillesen
** File description:
** my_printf
*/

#include <stdarg.h>
#include "../../include/my_printf.h"

#define skip_after_hash(str) str == '#' || str == '+' ? str++ : 0

int detect_nb_args(char const *str) {
    int nb_args = 0;

    while (*str) {
        if (*str == '%')
            nb_args++;
        str++;
    }
    return (nb_args);
}

void my_printf(char const *str, ...)
{
    int n = detect_nb_args(str);
    int res = 0;
    va_list args;

    va_start(args, *str);
    while (*str) {
        if (*str == '%') {
            str = check_type_int((char *)str, args);
            skip_after_hash(*str);
        } else
            my_putchar(*str);
        *str++;
    }
    va_end(args);
}