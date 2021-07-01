/*
** EPITECH PROJECT, 2021
** LibMy unit tests
** File description:
** Test the my_vec_remove & my_vec_remove_multiple_functions
*/

#include <criterion/criterion.h>
#include "libmy/collections/vec.h"

Test(my_vec_remove, remove_only_elem)
{
    int data[] = {42};
    my_vec_t vec = {data, 1, 1, sizeof(int)};
    int dst = -42;

    my_vec_remove(&vec, &dst, 0);
    cr_assert_eq(vec.length, 0);
    cr_assert_eq(dst, 42);
}

Test(my_vec_remove, remove_start_elem)
{
    int data[] = {42, 1, 2, 3, 4, 5, -1};
    my_vec_t vec = {data, 6, 7, sizeof(int)};
    int dst = -42;

    my_vec_remove(&vec, &dst, 0);
    cr_assert_eq(vec.length, 5);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 0), 1);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 1), 2);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 2), 3);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 3), 4);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 4), 5);
    cr_assert_eq(dst, 42);
}

Test(my_vec_remove, remove_mid_elem)
{
    int data[] = {1, 2, 3, 42, 4, 5, -1};
    my_vec_t vec = {data, 6, 7, sizeof(int)};
    int dst = -42;

    my_vec_remove(&vec, &dst, 3);
    cr_assert_eq(vec.length, 5);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 0), 1);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 1), 2);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 2), 3);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 3), 4);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 4), 5);
    cr_assert_eq(dst, 42);
}

Test(my_vec_remove, remove_end_elem)
{
    int data[] = {1, 2, 3, 4, 5, 42, -1};
    my_vec_t vec = {data, 6, 7, sizeof(int)};
    int dst = -42;

    my_vec_remove(&vec, &dst, 5);
    cr_assert_eq(vec.length, 5);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 0), 1);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 1), 2);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 2), 3);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 3), 4);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 4), 5);
    cr_assert_eq(dst, 42);
}

Test(my_vec_remove_multiple, remove_all_elems)
{
    int data[] = {21, 42, 84, -1, -2};
    my_vec_t vec = {data, 3, 5, sizeof(int)};
    int dst[3] = {0};

    my_vec_remove_multiple(&vec, &dst, 0, SIZE_MAX);
    cr_assert_eq(vec.length, 0);
    cr_assert_eq(dst[0], 21);
    cr_assert_eq(dst[1], 42);
    cr_assert_eq(dst[2], 84);
}

Test(my_vec_remove_multiple, remove_start_elems)
{
    int data[] = {21, 42, 84, 1, 2, 3, -1, -2};
    my_vec_t vec = {data, 6, 8, sizeof(int)};
    int dst[3] = {0};

    my_vec_remove_multiple(&vec, &dst, 0, 3);
    cr_assert_eq(vec.length, 3);
    cr_assert_eq(dst[0], 21);
    cr_assert_eq(dst[1], 42);
    cr_assert_eq(dst[2], 84);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 0), 1);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 1), 2);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 2), 3);
}

Test(my_vec_remove_multiple, remove_mid_elems)
{
    int data[] = {1, 2, 3, 21, 42, 84, 4, 5, 6, -1, -2};
    my_vec_t vec = {data, 9, 11, sizeof(int)};
    int dst[3] = {0};

    my_vec_remove_multiple(&vec, &dst, 3, 3);
    cr_assert_eq(vec.length, 6);
    cr_assert_eq(dst[0], 21);
    cr_assert_eq(dst[1], 42);
    cr_assert_eq(dst[2], 84);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 0), 1);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 1), 2);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 2), 3);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 3), 4);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 4), 5);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 5), 6);
}

Test(my_vec_remove_multiple, remove_end_elems)
{
    int data[] = {1, 2, 3, 4, 5, 6, 21, 42, 84};
    my_vec_t vec = {data, 9, 9, sizeof(int)};
    int dst[3] = {0};

    my_vec_remove_multiple(&vec, &dst, 6, 3);
    cr_assert_eq(vec.length, 6);
    cr_assert_eq(dst[0], 21);
    cr_assert_eq(dst[1], 42);
    cr_assert_eq(dst[2], 84);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 0), 1);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 1), 2);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 2), 3);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 3), 4);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 4), 5);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 5), 6);
}
