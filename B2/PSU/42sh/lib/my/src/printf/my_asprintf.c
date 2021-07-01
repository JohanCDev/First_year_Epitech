/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Formatted printing to an allocated string, with varargs
*/

#include "libmy/printf.h"

MY_PRINTF_API int my_asprintf(char **strp, const char *fmt, ...)
{
    va_list args;
    int ret;

    va_start(args, fmt);
    ret = my_vasprintf(strp, fmt, args);
    va_end(args);
    return ret;
}
