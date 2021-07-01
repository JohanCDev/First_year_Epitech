/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_vec_ensure_capacity function
*/

#include <criterion/criterion.h>
#include "libmy/collections.h"

Test(my_vec_ensure_capacity, sufficient_capacity)
{
    my_vec_t vec;

    cr_assert_eq(my_vec_init_capacity(&vec, 42, sizeof(int)), MY_VEC_OK);
    cr_assert_eq(my_vec_ensure_capacity(&vec, 21), MY_VEC_OK);
    my_vec_free(&vec, NULL);
}

Test(my_vec_ensure_capacity, insufficient_capacity)
{
    my_vec_t vec;

    cr_assert_eq(my_vec_init_capacity(&vec, 21, sizeof(int)), MY_VEC_OK);
    cr_assert_eq(my_vec_ensure_capacity(&vec, 42), MY_VEC_OK);
    my_vec_free(&vec, NULL);
}
