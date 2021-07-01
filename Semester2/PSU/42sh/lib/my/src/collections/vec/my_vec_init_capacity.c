/*
** EPITECH PROJECT, 2020
** LibMy - collections module
** File description:
** Initializes a vec
*/

#include <stdlib.h>
#include "libmy/collections.h"

MY_COLLECTIONS_API my_vec_err_t my_vec_init_capacity(
    my_vec_t *vec, size_t capacity, size_t elem_size)
{
    if (!elem_size)
        return MY_VEC_ZERO_ELEM_SIZE;
    if (capacity > 0) {
        vec->data = malloc(elem_size * capacity);
        if (!vec->data)
            return MY_VEC_ALLOC;
    } else {
        vec->data = NULL;
    }
    vec->length = 0;
    vec->capacity = capacity;
    vec->elem_size = elem_size;
    return MY_VEC_OK;
}
