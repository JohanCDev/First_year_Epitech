/*
** EPITECH PROJECT, 2020
** LibMy - collections module
** File description:
** Pushes an element to the back of the vec
*/

#include <stdint.h>
#include "libmy/collections.h"
#include "libmy/core.h"
#include "libmy/memory.h"

MY_COLLECTIONS_API my_vec_err_t my_vec_push(my_vec_t *vec, void *elem)
{
    return my_vec_push_multiple(vec, elem, 1);
}

MY_COLLECTIONS_API my_vec_err_t my_vec_push_multiple(
    my_vec_t *vec, void *elems, size_t count)
{
    my_vec_err_t ret;

    ret = my_vec_reserve(vec, count);
    if (ret)
        return ret;
    my_memcpy(((char *)vec->data) + vec->elem_size * vec->length, elems,
        vec->elem_size * count);
    vec->length += count;
    return MY_VEC_OK;
}
