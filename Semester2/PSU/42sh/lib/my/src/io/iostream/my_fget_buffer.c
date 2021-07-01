/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Returns the stream's current buffer
*/

#include "libmy/io.h"

MY_LOCAL void *p_my_fget_buffer_unix(
    p_my_iostream_unix_t const *stream, size_t *size)
{
    void *buf = stream->buf;

    if (!buf)
        return NULL;
    *size = stream->buf_len;
    return buf;
}

MY_LOCAL void *p_my_fget_buffer_memory(
    p_my_iostream_memory_t const *stream, size_t *size)
{
    *size = stream->count;
    return stream->buf;
}

MY_IO_API void *my_fget_buffer(size_t *size, my_iostream_t const *stream)
{
    p_my_fget_buf_impl_t func = stream->vtable->get_buffer;

    *size = 0;
    if (func)
        return (*func)(stream, size);
    return NULL;
}
