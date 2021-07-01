/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Writes to the passed stream
*/

#include "libmy/core.h"
#include "libmy/io.h"
#include "libmy/memory.h"

static void transfer_buf(
    const void **ptr, size_t *bytes, p_my_iostream_unix_t *stream)
{
    size_t to_transfer = MY_MIN(*bytes, stream->buf_cap - stream->buf_len);

    my_memcpy(stream->buf + stream->buf_len, *ptr, to_transfer);
    *ptr = (void *)((char *)*ptr + to_transfer);
    stream->buf_len += to_transfer;
    *bytes -= to_transfer;
}

MY_LOCAL size_t p_my_fwrite_unix(
    p_my_iostream_unix_t *output, const void *ptr, size_t size, size_t nmemb)
{
    size_t bytes = size * nmemb;
    size_t threshold;

    if (my_feof(MY_CAST(my_iostream_t *, output)))
        return 0;
    threshold = (size_t)((double)output->buf_cap * (double)output->threshold);
    while (bytes > 0) {
        transfer_buf(&ptr, &bytes, output);
        if (output->buf_len < output->buf_cap && output->buf_len < threshold)
            continue;
        if (my_fflush(MY_CAST(my_iostream_t *, output)))
            return 0;
    }
    return nmemb;
}

MY_LOCAL size_t p_my_fwrite_memory(
    p_my_iostream_memory_t *output, const void *ptr, size_t size, size_t nmemb)
{
    size_t bytes;

    if (my_feof(MY_CAST(my_iostream_t *, output)))
        return 0;
    bytes = MY_MIN(output->limit - output->count, size * nmemb);
    my_memcpy(output->buf + output->count, ptr, bytes);
    output->count += bytes;
    return bytes / size;
}

MY_LOCAL size_t p_my_fwrite_void(
    void *output, const void *ptr, size_t size, size_t nmemb)
{
    (void)output;
    (void)ptr;
    (void)size;
    return nmemb;
}

MY_IO_API size_t my_fwrite(
    const void *ptr, size_t size, size_t nmemb, my_iostream_t *stream)
{
    p_my_fwrite_impl_t func = stream->vtable->write;

    if (func)
        return (*func)(stream, ptr, size, nmemb);
    return 0;
}
