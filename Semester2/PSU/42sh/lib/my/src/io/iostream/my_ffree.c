/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Flushes the stream then free its buffer
*/

#include "libmy/io.h"

MY_LOCAL void p_my_ffree_unix(p_my_iostream_unix_t *stream)
{
    if (stream->free_buf)
        (*stream->free_buf)(stream->buf);
}

MY_IO_API void my_ffree(my_iostream_t *stream)
{
    p_my_ffree_impl_t func = stream->vtable->destroy;

    my_fflush(stream);
    if (func)
        (*func)(stream);
}
