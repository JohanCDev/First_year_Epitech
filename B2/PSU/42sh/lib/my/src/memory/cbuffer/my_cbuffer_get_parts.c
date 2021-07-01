/*
** EPITECH PROJECT, 2020
** LibMy - memory module
** File description:
** Returns the parts of a circular buffer
*/

#include "libmy/memory.h"

MY_MEMORY_API void *my_cbuffer_get_first_part(
    my_cbuffer_t const *buf, size_t *size)
{
    size_t end = buf->head;

    if (!my_cbuffer_is_contiguous(buf))
        end = buf->cap;
    if (size)
        *size = end - buf->tail;
    return (void *)((char *)buf->data + buf->tail);
}

MY_MEMORY_API void *my_cbuffer_get_second_part(
    my_cbuffer_t const *buf, size_t *size)
{
    if (!my_cbuffer_is_contiguous(buf)) {
        if (size)
            *size = buf->head;
        return buf->data;
    }
    if (size)
        *size = 0;
    return (void *)((char *)buf->data + buf->head);
}
