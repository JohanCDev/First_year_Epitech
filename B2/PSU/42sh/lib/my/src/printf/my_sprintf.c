/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Formatted printing to a string, with varargs
*/

#include "libmy/printf.h"

MY_PRINTF_API int my_sprintf(char *str, char const *fmt, ...)
{
    va_list args;
    int ret;

    va_start(args, fmt);
    ret = my_vsprintf(str, fmt, args);
    va_end(args);
    return ret;
}
