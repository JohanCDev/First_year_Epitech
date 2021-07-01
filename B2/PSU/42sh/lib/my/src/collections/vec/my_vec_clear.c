/*
** EPITECH PROJECT, 2021
** LibMy - collections module
** File description:
** Flushes the elements of a vector
*/

#include "libmy/collections/vec.h"

MY_COLLECTIONS_API void my_vec_clear(my_vec_t *vec, void (*elem_free)(void *))
{
    my_vec_clear_from(vec, 0, elem_free);
}

MY_COLLECTIONS_API void my_vec_clear_from(
    my_vec_t *vec, size_t start_index, void (*elem_free)(void *))
{
    assert(vec != NULL);
    if (elem_free != NULL && start_index < vec->length) {
        size_t len = vec->length;

        for (size_t i = start_index; i < len; ++i)
            (*elem_free)(my_vec_get(vec, i));
    }
    vec->length = start_index;
}
