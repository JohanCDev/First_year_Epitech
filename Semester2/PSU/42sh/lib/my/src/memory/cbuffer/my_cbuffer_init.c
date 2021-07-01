/*
** EPITECH PROJECT, 2020
** LibMy - memory module
** File description:
** Initializes a circular buffer
*/

#include "libmy/memory.h"

MY_MEMORY_API void my_cbuffer_init(
    my_cbuffer_t *buf, void *data, size_t capacity)
{
    buf->data = data;
    buf->cap = capacity;
    buf->len = 0;
    buf->head = 0;
    buf->tail = 0;
}
