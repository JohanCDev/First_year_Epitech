/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Checks if a stream has reached end-of-file
*/

#include "libmy/io.h"

MY_LOCAL int p_my_feof_unix(p_my_iostream_unix_t const *stream)
{
    return stream->fd < 0 || (stream->buf_len == 0 && stream->is_eof);
}

MY_LOCAL int p_my_feof_memory(p_my_iostream_memory_t const *stream)
{
    return stream->buf == NULL || stream->count >= stream->limit;
}

MY_LOCAL int p_my_feof_void(void const *stream)
{
    (void)stream;
    return 0;
}

MY_IO_API int my_feof(my_iostream_t *stream)
{
    p_my_feof_impl_t func = stream->vtable->eof;

    if (func)
        return (*func)(stream);
    return 1;
}
