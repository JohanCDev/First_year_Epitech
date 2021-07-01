/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Reads from a stream
*/

#include <unistd.h>
#include "libmy/core.h"
#include "libmy/io.h"
#include "libmy/memory.h"

static int transfer_buf(
    void **ptr, size_t size, size_t *nmemb, p_my_iostream_unix_t *stream)
{
    size_t elems_to_transfer;
    size_t bytes_to_transfer;

    if (stream->buf_len < size) {
        ssize_t ret = read(stream->fd, stream->buf + stream->buf_len,
            MY_MIN(MY_READ_SIZE, stream->buf_cap - stream->buf_len));

        if (ret < 0)
            return 1;
        stream->is_eof = ret == 0;
        stream->buf_len += ret;
    }
    elems_to_transfer = MY_MIN(*nmemb, stream->buf_len / size);
    bytes_to_transfer = elems_to_transfer * size;
    my_memcpy(*ptr, stream->buf, bytes_to_transfer);
    stream->buf_len -= bytes_to_transfer;
    my_memmove(stream->buf, stream->buf + bytes_to_transfer, stream->buf_len);
    *ptr = (char *)*ptr + bytes_to_transfer;
    *nmemb -= elems_to_transfer;
    return 0;
}

MY_LOCAL size_t p_my_fread_unix(
    p_my_iostream_unix_t *input, void *ptr, size_t size, size_t nmemb)
{
    size_t elems_to_read = nmemb;

    if (input->fd < 0)
        return 0;
    while (elems_to_read > 0 && !my_feof(MY_CAST(my_iostream_t *, input)))
        if (transfer_buf(&ptr, size, &elems_to_read, input))
            return 0;
    return nmemb - elems_to_read;
}
