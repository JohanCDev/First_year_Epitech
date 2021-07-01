/*
** EPITECH PROJECT, 2020
** LibMy - collections module
** File description:
** Change a value
*/

#include <assert.h>
#include <stdlib.h>

#include "libmy/collections.h"
#include "libmy/memory.h"

MY_COLLECTIONS_API my_vec_err_t my_vec_change_value(
    my_vec_t *vec, void *new_value, size_t index)
{
    assert(vec != NULL);
    assert(new_value != NULL);
    if (index >= vec->length)
        return MY_VEC_OUT_OF_BOUNDS;
    my_memcpy(((char *)vec->data) + vec->elem_size * index, new_value,
        vec->elem_size);
    return MY_VEC_OK;
}
