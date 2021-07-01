/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Repeatedly prints a character
*/

#include "libmy/io.h"

MY_IO_API int my_frputc(char c, size_t count, my_iostream_t *stream)
{
    int ret;

    for (size_t i = 0; i < count; ++i) {
        ret = my_fputc(c, stream);
        if (ret != 0)
            return ret;
    }
    return 0;
}

MY_IO_API int my_rputc(char c, size_t count)
{
    return my_frputc(c, count, MY_STDOUT);
}

MY_IO_API int my_erputc(char c, size_t count)
{
    return my_frputc(c, count, MY_STDERR);
}
