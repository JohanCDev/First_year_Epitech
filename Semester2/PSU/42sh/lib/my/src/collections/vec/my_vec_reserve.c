/*
** EPITECH PROJECT, 2020
** LibMy - collections module
** File description:
** Reserves enough capacity to hold len + additional elements
*/

#include <stdint.h>
#include "libmy/collections.h"
#include "libmy/core.h"

// Computes the minimum non-zero capacity
// - 8 if the element size is 1, because any heap allocators is likely
//   to round up a request of less than 8 bytes to at least 8 bytes.
// - 4 if elements are moderate-sized (<= 1 KiB).
// - 1 otherwise, to avoid wasting too much space for very short vecs.
static size_t min_non_zero_cap(size_t elem_size)
{
    if (elem_size == 1) {
        return 8;
    } else if (elem_size <= 1024) {
        return 4;
    } else {
        return 1;
    }
}

MY_COLLECTIONS_API my_vec_err_t my_vec_reserve(
    my_vec_t *vec, size_t additional)
{
    size_t cap = MY_MAX(vec->capacity, min_non_zero_cap(vec->elem_size));
    size_t new_cap;

    if (vec->length > SIZE_MAX - additional)
        return MY_VEC_CAPACITY_OVERFLOW;
    new_cap = vec->length + additional;
    if (new_cap <= vec->capacity)
        return MY_VEC_OK;
    if (cap > SIZE_MAX / 2)
        cap = SIZE_MAX;
    else
        cap *= 2;
    return my_vec_set_capacity(vec, MY_MAX(new_cap, cap), NULL);
}
