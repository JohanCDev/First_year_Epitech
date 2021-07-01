/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Flushes a stream
*/

#include <unistd.h>
#include "libmy/core.h"
#include "libmy/io.h"
#include "libmy/memory.h"

static int write_until_empty(p_my_iostream_unix_t *stream)
{
    while (1) {
        size_t to_write = MY_MIN(stream->buf_len, MY_WRITE_SIZE);
        ssize_t ret = write(stream->fd, stream->buf, to_write);

        if (ret < 0)
            return 1;
        if ((size_t)ret == stream->buf_len) {
            stream->buf_len -= ret;
            return 0;
        }
        stream->buf_len -= ret;
        my_memmove(stream->buf, stream->buf + ret, stream->buf_len);
    }
}

MY_LOCAL int p_my_fflush_unix(p_my_iostream_unix_t *stream)
{
    if (my_is_output_stream(MY_CAST(my_iostream_t *, stream)))
        return write_until_empty(stream);
    stream->buf_len = 0;
    return 0;
}

MY_IO_API int my_fflush(my_iostream_t *stream)
{
    p_my_fflush_impl_t func = stream->vtable->flush;

    if (func)
        return (*func)(stream);
    return 0;
}
