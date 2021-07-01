/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Formatted printing to a string, with varargs
*/

#include "libmy/printf.h"

MY_PRINTF_API int my_snprintf(char *str, size_t size, const char *fmt, ...)
{
    va_list args;
    int ret;

    va_start(args, fmt);
    ret = my_vsnprintf(str, size, fmt, args);
    va_end(args);
    return ret;
}
