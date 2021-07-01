/*
** EPITECH PROJECT, 2020
** LibMy - collections module
** File description:
** Insert an element inside the vector
*/

#include "libmy/collections.h"
#include "libmy/core.h"
#include "libmy/memory.h"

MY_COLLECTIONS_API my_vec_err_t my_vec_insert(
    my_vec_t *vec, void *elem, size_t index)
{
    return my_vec_insert_multiple(vec, elem, index, 1);
}

MY_COLLECTIONS_API my_vec_err_t my_vec_insert_multiple(
    my_vec_t *vec, void *elems, size_t index, size_t count)
{
    my_vec_err_t ret;

    if (index > vec->length)
        return MY_VEC_OUT_OF_BOUNDS;
    if (index == vec->length)
        return my_vec_push_multiple(vec, elems, count);
    ret = my_vec_reserve(vec, count);
    if (ret)
        return ret;
    my_memmove(my_vec_get(vec, index + count), my_vec_get(vec, index),
        (vec->length - index) * vec->elem_size);
    my_memcpy(((char *)vec->data) + vec->elem_size * index, elems,
        vec->elem_size * count);
    vec->length += count;
    return MY_VEC_OK;
}