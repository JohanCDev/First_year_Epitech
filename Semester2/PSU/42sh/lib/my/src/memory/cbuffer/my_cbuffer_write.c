/*
** EPITECH PROJECT, 2020
** LibMy - memory module
** File description:
** Writes to a circular buffer
*/

#include "libmy/core.h"
#include "libmy/memory.h"

// Writes the given bytes *before* buf->tail.
//
// Examples for size = 2:
// # = filled, . = empty, T = tail (filled), H = head
//
// CASE 1: T = 7, H = 3: [###H...T##] -> [###H.T####]
// CASE 2: T = 1, H = 5: [.T###H....] -> [#####H...T]
// CASE 3: T = 2, H = 8: [..T#####H.] -> [T#######H.]
MY_MEMORY_API void my_cbuffer_write_front(
    my_cbuffer_t *buf, void const *src, size_t size)
{
    if (buf->tail > buf->head) {
        my_memcpy((char *)buf->data + (buf->tail - size), src, size);
    } else if (buf->tail < size) {
        size_t first_part = buf->tail;
        size_t second_part = size - first_part;

        my_memcpy(buf->data, (char *)src + second_part, first_part);
        my_memcpy(
            (char *)buf->data + (buf->cap - second_part), src, second_part);
    } else {
        my_memcpy((char *)buf->data + (buf->tail - size), src, size);
    }
}

// Writes the given bytes *after* buf->head (inclusive).
//
// Examples for size = 2:
// # = filled, . = empty, T = tail (filled), H = head
//
// CASE 1: T = 7, H = 3: [###H...T##] -> [#####H.T##]
// CASE 2: T = 5, H = 9: [.....T###H] -> [#H...T####]
// CASE 3: T = 2, H = 8: [..T#####H.] -> [H.T#######]
MY_MEMORY_API void my_cbuffer_write_back(
    my_cbuffer_t *buf, void const *src, size_t size)
{
    if (buf->tail <= buf->head && buf->head > buf->cap - size) {
        size_t first_part = buf->cap - buf->head;
        size_t second_part = size - first_part;

        my_memcpy((char *)buf->data + buf->head, src, first_part);
        my_memcpy(buf->data, (char *)src + first_part, second_part);
    } else {
        my_memcpy((char *)buf->data + buf->head, src, size);
    }
}
