/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Formatted printing to output stream, with varargs
*/

#include "libmy/printf.h"

MY_PRINTF_API int my_fprintf(my_iostream_t *out, char const *fmt, ...)
{
    va_list args;
    int ret;

    va_start(args, fmt);
    ret = my_vfprintf(out, fmt, args);
    va_end(args);
    return ret;
}
