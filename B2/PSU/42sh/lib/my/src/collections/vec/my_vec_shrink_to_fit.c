/*
** EPITECH PROJECT, 2020
** LibMy - collections module
** File description:
** Shrinks the capacity of the vec as much as possible
*/

#include "libmy/collections.h"

MY_COLLECTIONS_API my_vec_err_t my_vec_shrink_to_fit(my_vec_t *vec)
{
    return my_vec_set_capacity(vec, vec->length, NULL);
}
