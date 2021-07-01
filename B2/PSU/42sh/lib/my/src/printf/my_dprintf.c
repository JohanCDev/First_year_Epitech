/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Formatted printing to file descriptor, with varargs
*/

#include "libmy/printf.h"

MY_PRINTF_API int my_dprintf(int fd, char const *fmt, ...)
{
    va_list args;
    int ret;

    va_start(args, fmt);
    ret = my_vdprintf(fd, fmt, args);
    va_end(args);
    return ret;
}
