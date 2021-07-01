/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Prints a string into the stream, followed by a new line.
*/

#include "libmy/io.h"

MY_IO_API int my_fputs_endl(char const *str, my_iostream_t *stream)
{
    return my_fputs(str, stream) || my_fputc('\n', stream);
}

MY_IO_API int my_puts_endl(char const *str)
{
    return my_fputs_endl(str, MY_STDOUT);
}

MY_IO_API int my_eputs_endl(char const *str)
{
    return my_fputs_endl(str, MY_STDERR);
}
