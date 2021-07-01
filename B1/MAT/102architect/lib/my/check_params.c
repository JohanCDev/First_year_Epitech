/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myprintf-johan.chrillesen
** File description:
** check_params
*/

#include <stdarg.h>
#include "my.h"
#define int_is_printable(c) c > 31 && c < 127 ? 1 : 0
#define put_plus(nb) nb >= 0 ? my_putchar('+') : 0

char *check_for_hashtag(char *str, va_list args)
{
    switch (*++str) {
        case 'x':
            my_putstr("0x");
            my_putnbr_base_int(va_arg(args, int), "0123456789abcdef");
            break;
        case 'X':
            my_putstr("0x");
            my_putnbr_base_int(va_arg(args, int), "0123456789ABCDEF");
            break;
        case 'o':
            my_putstr("0");
            my_putnbr_base_int(va_arg(args, int), "01234567");
            break;
        default:
            my_put_error("Invalid argument");
            break;
    }
    return (str);
}

void check_for_plus(char *str, va_list args)
{
    int nb = va_arg(args, int);
    switch (*++str) {
        case 'i':
        case 'd':
            put_plus(nb);
            my_put_nbr(nb);
            break;
        default:
            break;
    }
}