/*
** EPITECH PROJECT, 2020
** LibMy - collections module
** File description:
** Copies a vector into an other
*/

#include <stdlib.h>
#include "libmy/collections.h"
#include "libmy/memory.h"

MY_COLLECTIONS_API my_vec_err_t my_vec_copy(my_vec_t *dst, my_vec_t const *src)
{
    if (src->length > 0) {
        dst->data = malloc(src->length * src->elem_size);
        if (!dst->data)
            return MY_VEC_ALLOC;
        my_memcpy(dst->data, src->data, src->length * src->elem_size);
    } else {
        dst->data = NULL;
    }
    dst->length = src->length;
    dst->capacity = src->length;
    dst->elem_size = src->elem_size;
    return MY_VEC_OK;
}

MY_COLLECTIONS_API my_vec_err_t my_vec_copy_into(
    my_vec_t *dst, my_vec_t const *src)
{
    if (dst->capacity < src->length || dst->elem_size != src->elem_size) {
        my_vec_free(dst, NULL);
        return my_vec_copy(dst, src);
    }
    if (src->length)
        my_memcpy(dst->data, src->data, src->length * src->elem_size);
    dst->length = src->length;
    return MY_VEC_OK;
}
