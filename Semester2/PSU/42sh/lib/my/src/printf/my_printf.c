/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Formatted printing to stdout, with varargs
*/

#include "libmy/printf.h"

MY_PRINTF_API int my_printf(char const *fmt, ...)
{
    va_list args;
    int ret;

    va_start(args, fmt);
    ret = my_vprintf(fmt, args);
    va_end(args);
    return ret;
}
