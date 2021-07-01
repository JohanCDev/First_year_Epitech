/*
** EPITECH PROJECT, 2020
** LibMy - collections module
** File description:
** Extends a vec to a given length with the passed element
*/

#include "libmy/collections.h"
#include "libmy/core.h"
#include "libmy/memory.h"

MY_COLLECTIONS_API my_vec_err_t my_vec_extend_to_length(
    my_vec_t *vec, void *elem, size_t length)
{
    size_t new_length = MY_MAX(length, vec->length);
    my_vec_err_t ret = my_vec_ensure_capacity(vec, length);

    if (ret != MY_VEC_OK)
        return ret;
    for (size_t i = vec->length; i < new_length; ++i)
        my_memcpy(my_vec_get(vec, i), elem, vec->elem_size);
    vec->length = new_length;
    return MY_VEC_OK;
}
