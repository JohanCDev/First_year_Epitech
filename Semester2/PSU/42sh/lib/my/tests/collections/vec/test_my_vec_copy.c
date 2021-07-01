/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_vec_copy & my_vec_copy_into functions
*/

#include <criterion/criterion.h>
#include "libmy/collections.h"

Test(my_vec_copy, empty_src)
{
    my_vec_t src;
    my_vec_t dst;

    my_vec_init(&src, sizeof(int));
    cr_assert_eq(my_vec_copy(&dst, &src), MY_VEC_OK);
    cr_assert_eq(dst.capacity, 0);
    cr_assert_eq(dst.length, 0);
    cr_assert_eq(dst.elem_size, sizeof(int));
    cr_assert_eq(dst.data, NULL);
}

Test(my_vec_copy, elems_in_src)
{
    my_vec_t src;
    my_vec_t dst;
    int elems[] = { 42, -21, 84, 56 };

    my_vec_init(&src, sizeof(int));
    my_vec_push_multiple(&src, elems, 4);
    cr_assert_eq(my_vec_copy(&dst, &src), MY_VEC_OK);
    cr_assert_eq(dst.capacity, 4);
    cr_assert_eq(dst.length, 4);
    cr_assert_eq(dst.elem_size, sizeof(int));
    cr_assert_eq(MY_VEC_GET_ELEM(int, &dst, 0), elems[0]);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &dst, 1), elems[1]);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &dst, 2), elems[2]);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &dst, 3), elems[3]);
}

Test(my_vec_copy_into, empty_src)
{
    my_vec_t src;
    my_vec_t dst;

    my_vec_init(&src, sizeof(int));
    my_vec_init_capacity(&dst, 2, sizeof(int));
    cr_assert_eq(my_vec_copy_into(&dst, &src), MY_VEC_OK);
    cr_assert_eq(dst.length, 0);
    cr_assert_eq(dst.elem_size, sizeof(int));
}

Test(my_vec_copy_into, not_enough_cap_in_dst)
{
    my_vec_t src;
    my_vec_t dst;
    int elems[] = { 42, -21, 84, 56 };

    my_vec_init(&src, sizeof(int));
    my_vec_init_capacity(&dst, 2, sizeof(int));
    my_vec_push_multiple(&src, elems, 4);
    cr_assert_eq(my_vec_copy_into(&dst, &src), MY_VEC_OK);
    cr_assert_eq(dst.length, 4);
    cr_assert_eq(dst.elem_size, sizeof(int));
    cr_assert_eq(MY_VEC_GET_ELEM(int, &dst, 0), elems[0]);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &dst, 1), elems[1]);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &dst, 2), elems[2]);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &dst, 3), elems[3]);
}

Test(my_vec_copy_into, mismatched_elem_sizes)
{
    my_vec_t src;
    my_vec_t dst;
    int elems[] = { 42, -21, 84, 56 };

    my_vec_init(&src, sizeof(int));
    my_vec_init_capacity(&dst, 20, sizeof(char));
    my_vec_push_multiple(&src, elems, 4);
    cr_assert_eq(my_vec_copy_into(&dst, &src), MY_VEC_OK);
    cr_assert_eq(dst.length, 4);
    cr_assert_eq(dst.elem_size, sizeof(int));
    cr_assert_eq(MY_VEC_GET_ELEM(int, &dst, 0), elems[0]);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &dst, 1), elems[1]);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &dst, 2), elems[2]);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &dst, 3), elems[3]);
}

Test(my_vec_copy_into, enough_cap_in_dst)
{
    my_vec_t src;
    my_vec_t dst;
    int elems[] = { 42, -21, 84, 56 };

    my_vec_init(&src, sizeof(int));
    my_vec_init_capacity(&dst, 20, sizeof(int));
    my_vec_push_multiple(&src, elems, 4);
    cr_assert_eq(my_vec_copy_into(&dst, &src), MY_VEC_OK);
    cr_assert_eq(dst.length, 4);
    cr_assert_eq(dst.elem_size, sizeof(int));
    cr_assert_eq(MY_VEC_GET_ELEM(int, &dst, 0), elems[0]);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &dst, 1), elems[1]);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &dst, 2), elems[2]);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &dst, 3), elems[3]);
}
