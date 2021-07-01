/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myprintf-johan.chrillesen
** File description:
** check_types
*/

#include <stdarg.h>
#include "my.h"

void check_type_other(char *str, va_list args)
{
    switch (*str) {
        case 'p':
        case 'P':
            my_put_address((long long)va_arg(args, long long));
            break;
        case '%':
            my_putchar('%');
            break;
        case '#':
            check_for_hashtag(str, args);
            break;
        case '+':
            check_for_plus(str, args);
            break;
        default:
            break;
    }
}

char *check_type_base(char *str, va_list args)
{
    switch (*str) {
        case 'b':
            my_putnbr_base_int(va_arg(args, int), "01");
            break;
        case 'x':
            my_putnbr_base_int(va_arg(args, int), "0123456789abcdef");
            break;
        case 'X':
            my_putnbr_base_int(va_arg(args, int), "0123456789ABCDEF");
            break;
        case 'S':
            my_putstr_nonprintable(va_arg(args, char *));
            break;
        case 'o':
            my_putnbr_base_int(va_arg(args, int), "01234567");
            break;
        default:
            check_type_other(str, args);
    }
    return (str);
}

char *check_type_char(char *str, va_list args)
{
    switch (*str) {
        case 'c':
            my_putchar(va_arg(args, int));
            break;
        case 's':
            my_putstr(va_arg(args, char *));
            break;
        case 't':
            my_put_tab(va_arg(args, char **), "\n");
            break;
        case 'e':
            my_put_error(va_arg(args, char *));
            break;
        default:
            check_type_base(str, args);
    }
    return (str);
}

char *check_type_int(char *str, va_list args)
{
    switch (*++str) {
        case 'd':
        case 'i':
            my_put_nbr(va_arg(args, int));
            break;
        case 'u':
            my_put_unsigned_nbr(va_arg(args, int));
            break;
        default:
            check_type_char(str, args);
    }
    return (str);
}