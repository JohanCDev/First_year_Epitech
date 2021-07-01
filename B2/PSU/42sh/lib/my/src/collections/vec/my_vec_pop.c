/*
** EPITECH PROJECT, 2020
** LibMy - collections module
** File description:
** Removes the last elements from a vec
*/

#include "libmy/collections.h"
#include "libmy/core.h"
#include "libmy/memory.h"

MY_COLLECTIONS_API void my_vec_pop(my_vec_t *vec, void *dst)
{
    my_vec_pop_multiple(vec, dst, 1);
}

MY_COLLECTIONS_API void my_vec_pop_multiple(
    my_vec_t *vec, void *dst, size_t count)
{
    count = MY_MIN(count, vec->length);
    if (!count)
        return;
    vec->length -= count;
    if (dst)
        my_memcpy(dst, ((char *)vec->data) + vec->length * vec->elem_size,
            count * vec->elem_size);
}
