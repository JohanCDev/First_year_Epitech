/*
** EPITECH PROJECT, 2020
** LibMy - memory module
** File description:
** Pushes elements to a circular buffer
*/

#include "libmy/memory.h"

MY_MEMORY_API void my_cbuffer_push_front(
    my_cbuffer_t *buf, void const *src, size_t size)
{
    my_cbuffer_write_front(buf, src, size);
    buf->tail = my_cbuffer_wrap_sub(buf, buf->tail, size);
    buf->len += size;
}

MY_MEMORY_API void my_cbuffer_push_back(
    my_cbuffer_t *buf, void const *src, size_t size)
{
    my_cbuffer_write_back(buf, src, size);
    buf->head = my_cbuffer_wrap_add(buf, buf->head, size);
    buf->len += size;
}
