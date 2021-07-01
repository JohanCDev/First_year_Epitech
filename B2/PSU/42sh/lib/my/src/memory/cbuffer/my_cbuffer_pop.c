/*
** EPITECH PROJECT, 2020
** LibMy - memory module
** File description:
** Pop operations for circular buffers
*/

#include "libmy/memory.h"

MY_MEMORY_API void *my_cbuffer_pop_front(
    my_cbuffer_t *buf, void *dst, size_t size)
{
    my_cbuffer_read_front(buf, dst, size);
    buf->tail = my_cbuffer_wrap_add(buf, buf->tail, size);
    buf->len -= size;
    return dst;
}

MY_MEMORY_API void *my_cbuffer_pop_back(
    my_cbuffer_t *buf, void *dst, size_t size)
{
    my_cbuffer_read_back(buf, dst, size);
    buf->head = my_cbuffer_wrap_sub(buf, buf->head, size);
    buf->len -= size;
    return dst;
}
