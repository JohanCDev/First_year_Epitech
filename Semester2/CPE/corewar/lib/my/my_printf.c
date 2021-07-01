/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myprintf-tanguy.bellicha
** File description:
** make re && gcc sources/my_printf.c -L. -lmy -I/includes && ./a.out
*/

#include <stdarg.h>
#include <stdio.h>
#include "my.h"

void my_printf(char *str, ...)
{
    va_list args;
    int i = 0;

    va_start(args, str);
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%') {
            i = my_switch_numbers(str, args, i);
            i += skip_param(str[i]);
        } else
            my_putchar(str[i]);
    }
    va_end(args);
}
