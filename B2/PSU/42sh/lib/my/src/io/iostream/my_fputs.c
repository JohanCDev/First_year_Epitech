/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Puts a null-terminatid string into the specified output stream
*/

#include "libmy/ascii.h"
#include "libmy/io.h"

MY_IO_API int my_fputs(char const *str, my_iostream_t *stream)
{
    size_t len;

    if (!my_is_output_stream(stream))
        return 1;
    if (!str)
        return 0;
    len = my_strlen(str);
    if (!len)
        return 0;
    return my_fwrite(str, len, 1, stream) == 0;
}

MY_IO_API int my_puts(char const *str)
{
    return my_fputs(str, MY_STDOUT);
}

MY_IO_API int my_eputs(char const *str)
{
    return my_fputs(str, MY_STDERR);
}
