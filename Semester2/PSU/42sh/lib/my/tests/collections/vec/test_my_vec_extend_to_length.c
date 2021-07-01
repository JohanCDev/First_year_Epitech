/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_vec_extend_to_length function
*/

#include <criterion/criterion.h>
#include <stdint.h>
#include "libmy/collections.h"

Test(my_vec_extend_to_length, alloc_error)
{
    my_vec_t vec;
    int elem = 42;

    cr_assert_eq(my_vec_init(&vec, sizeof(int)), MY_VEC_OK);
    cr_assert_eq(my_vec_extend_to_length(&vec, &elem, SIZE_MAX), MY_VEC_ALLOC);
}

Test(my_vec_extend_to_length, no_extension)
{
    my_vec_t vec;
    int elems[] = { 21, -42, 84 };
    int elem = 42;

    cr_assert_eq(my_vec_init_capacity(&vec, 3, sizeof(int)), MY_VEC_OK);
    cr_assert_eq(my_vec_push_multiple(&vec, &elems, 3), MY_VEC_OK);
    cr_assert_eq(vec.length, 3);
    cr_assert_eq(my_vec_extend_to_length(&vec, &elem, 1), MY_VEC_OK);
    cr_assert_eq(vec.length, 3);
    cr_assert_eq(my_vec_extend_to_length(&vec, &elem, 3), MY_VEC_OK);
    cr_assert_eq(vec.length, 3);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 0), 21);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 1), -42);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 2), 84);
    my_vec_free(&vec, NULL);
}

Test(my_vec_extend_to_length, extension)
{
    my_vec_t vec;
    int elems[] = { 21, -42, 84 };
    int elem = 42;

    cr_assert_eq(my_vec_init_capacity(&vec, 3, sizeof(int)), MY_VEC_OK);
    cr_assert_eq(my_vec_push_multiple(&vec, &elems, 3), MY_VEC_OK);
    cr_assert_eq(vec.length, 3);
    cr_assert_eq(my_vec_extend_to_length(&vec, &elem, 5), MY_VEC_OK);
    cr_assert_eq(vec.length, 5);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 0), 21);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 1), -42);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 2), 84);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 3), 42);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 4), 42);
    my_vec_free(&vec, NULL);
}
