/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myprintf-tanguy.bellicha
** File description:
** my_switch_file
*/

#include <stdarg.h>
#include "my.h"

int my_switch_plus(char *str, va_list args, int i)
{
    int nb = 0;
    switch (str[++i]) {
    case 'i':
    case 'd':
        nb = va_arg(args, int);
        put_sign(nb);
        my_put_nbr(nb);
        break;
    }
    return (i);
}

int my_switch_numbers(char *str, va_list args, int i)
{
    switch (str[++i]) {
    case 'i':
    case 'd':
        my_put_nbr(va_arg(args, int));
        break;
    case 'u':
        my_put_unsigned(va_arg(args, unsigned int));
        break;
    case '+':
        my_switch_plus(str, args, i);
        break;
    default:
        my_switch_alpha(str, args, i);
    }
    return (i);
}

int my_switch_alpha(char *str, va_list args, int i)
{
    switch (str[i]) {
    case 's':
        my_putstr(va_arg(args, char *));
        break;
    case 'c':
        my_putchar(va_arg(args, int));
        break;
    case 'S':
        my_putstr_np(va_arg(args, char *));
        break;
    case 'o':
        my_put_nbr(convert_decimal_to_octal(va_arg(args, int)));
        break;
    case 'p':
        my_put_adress((long long)va_arg(args, long long));
        break;
    default:
        my_switch_hexbin(str, args, i);
    }
    return (i);
}

int my_switch_hexbin(char *str, va_list args, int i)
{
    switch (str[i]) {
    case 'x':
        my_put_nbr_base_int(va_arg(args, int), "0123456789abcdef");
        break;
    case 'X':
        my_put_nbr_base_int(va_arg(args, int), "0123456789ABCDEF");
        break;
    case 'b':
        my_put_nbr_base_int(va_arg(args, int), "01");
        break;
    case '#':
        my_switch_hash(str, args, i);
        break;
    case '%':
        my_putchar('%');
        break;
    }
    return (i);
}

int my_switch_hash(char *str, va_list args, int i)
{
    switch (str[++i]) {
    case 'x':
        my_putstr("0x");
        my_put_nbr_base_int(va_arg(args, int), "0123456789abcdef");
        break;
    case 'X':
        my_putstr("0X");
        my_put_nbr_base_int(va_arg(args, int), "0123456789ABCDEF");
        break;
    case 'o':
        my_putstr("0");
        my_put_nbr(convert_decimal_to_octal(va_arg(args, int)));
        break;
    case 'b':
        my_putstr("0b");
        my_put_nbr_base_int(va_arg(args, int), "01");
        break;
    }
    return (i);
}