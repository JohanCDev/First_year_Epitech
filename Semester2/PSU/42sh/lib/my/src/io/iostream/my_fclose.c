/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Closes an IO stream.
*/

#include "libmy/io.h"

MY_IO_API int my_fclose(my_iostream_t *stream)
{
    p_my_fclose_impl_t func = stream->vtable->close;

    my_fflush(stream);
    if (func)
        return (*func)(stream);
    return 0;
}
