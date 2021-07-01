/*
** EPITECH PROJECT, 2020
** LibMy - printf module
** File description:
** Formatted printing to a file descriptor, with va_list.
*/

#include "libmy/printf.h"

MY_PRINTF_API int my_vdprintf(int fd, char const *fmt, va_list args)
{
    unsigned char buf[MY_PRINTF_BUF_SIZE];
    my_iostream_t stream;
    int ret;

    my_finit_output_fd(fd, &stream);
    my_fset_buffer(buf, MY_PRINTF_BUF_SIZE, NULL, &stream);
    ret = my_vfprintf(&stream, fmt, args);
    my_ffree(&stream);
    return ret;
}
