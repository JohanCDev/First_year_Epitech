/*
** EPITECH PROJECT, 2020
** LibMy - collections module
** File description:
** Frees a vec
*/

#include <stdlib.h>
#include "libmy/collections.h"

static void my_vec_reinit(my_vec_t *vec)
{
    vec->data = NULL;
    vec->length = 0;
    vec->capacity = 0;
    vec->elem_size = 0;
}

static void my_vec_free_elems(my_vec_t *vec, void (*elem_free)(void *))
{
    size_t len = vec->length;

    for (size_t i = 0; i < len; ++i)
        (*elem_free)(my_vec_get(vec, i));
}

MY_COLLECTIONS_API void my_vec_free(my_vec_t *vec, void (*elem_free)(void *))
{
    if (!vec)
        return;
    if (!vec->data || !vec->capacity) {
        my_vec_reinit(vec);
        return;
    }
    if (elem_free)
        my_vec_free_elems(vec, elem_free);
    free(vec->data);
    my_vec_reinit(vec);
}
