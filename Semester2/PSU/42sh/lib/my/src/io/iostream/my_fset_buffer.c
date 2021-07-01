/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Sets the buffer of a stream
*/

#include "libmy/io.h"

MY_LOCAL int p_my_fset_buffer_unix(p_my_iostream_unix_t *stream, void *buf,
    size_t buf_cap, void (*free_buf)(void *))
{
    stream->buf = buf;
    stream->buf_cap = buf_cap;
    stream->free_buf = free_buf;
    return 0;
}

MY_IO_API int my_fset_buffer(
    void *buf, size_t buf_cap, void (*free_buf)(void *), my_iostream_t *stream)
{
    p_my_fset_buf_impl_t func = stream->vtable->set_buffer;

    if (func)
        return (*func)(stream, buf, buf_cap, free_buf);
    return 0;
}
