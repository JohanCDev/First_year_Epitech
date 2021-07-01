/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myprintf-johan.chrillesen
** File description:
** my_printf
*/

#include <stdarg.h>
#include "my.h"

void my_printf(char const *str, ...)
{
    va_list args;

    va_start(args, *str);
    while (*str) {
        if (*str == '%') {
            str = check_type_int((char *)str, args);
            skip_after_hash(*str);
        } else
            my_putchar(*str);
        str += 1;
    }
    va_end(args);
}