/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Puts a character into the specified file stream.
*/

#include "libmy/io.h"

MY_IO_API int my_fputc(char c, my_iostream_t *stream)
{
    return my_fwrite(&c, 1, 1, stream) == 0;
}

MY_IO_API int my_putc(char c)
{
    return my_fwrite(&c, 1, 1, MY_STDOUT) == 0;
}

MY_IO_API int my_eputc(char c)
{
    return my_fwrite(&c, 1, 1, MY_STDERR) == 0;
}
