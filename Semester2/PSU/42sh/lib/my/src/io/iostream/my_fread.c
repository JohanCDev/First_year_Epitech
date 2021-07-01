/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Reads from a stream
*/

#include "libmy/core.h"
#include "libmy/io.h"
#include "libmy/memory.h"

MY_LOCAL size_t p_my_fread_memory(
    p_my_iostream_memory_t *input, void *ptr, size_t size, size_t nmemb)
{
    size_t elems_to_read;
    size_t bytes;

    if (my_feof(MY_CAST(my_iostream_t *, input)))
        return 0;
    elems_to_read = MY_MIN(nmemb, (input->limit - input->count) / size);
    bytes = elems_to_read * size;
    my_memcpy(ptr, input->buf + input->count, bytes);
    input->count += bytes;
    return elems_to_read;
}

MY_LOCAL size_t p_my_fread_void(
    void *input, void *ptr, size_t size, size_t nmemb)
{
    (void)input;
    (void)ptr;
    (void)size;
    (void)nmemb;
    return 0;
}

MY_IO_API size_t my_fread(
    void *ptr, size_t size, size_t nmemb, my_iostream_t *stream)
{
    p_my_fread_impl_t func = stream->vtable->read;

    if (func)
        return (*func)(stream, ptr, size, nmemb);
    return 0;
}
