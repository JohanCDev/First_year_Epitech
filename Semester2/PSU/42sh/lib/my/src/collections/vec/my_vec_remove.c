/*
** EPITECH PROJECT, 2021
** LibMy - collections module
** File description:
** Removes elements from a vector
*/

#include "libmy/collections/vec.h"
#include "libmy/memory.h"

MY_COLLECTIONS_API void my_vec_remove(my_vec_t *vec, void *dst, size_t index)
{
    my_vec_remove_multiple(vec, dst, index, 1);
}

MY_COLLECTIONS_API void my_vec_remove_multiple(
    my_vec_t *vec, void *dst, size_t index, size_t count)
{
    size_t length = vec->length;
    size_t to_shift_start = index + count;

    if (to_shift_start > length) {
        count = vec->length - index;
        to_shift_start = index + count;
    }
    my_memcpy(dst, my_vec_get(vec, index), vec->elem_size * count);
    vec->length -= count;
    if (to_shift_start == length)
        return;
    my_memmove(my_vec_get(vec, index), my_vec_get(vec, to_shift_start),
        (length - to_shift_start) * vec->elem_size);
}
