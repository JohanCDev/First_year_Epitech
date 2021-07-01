/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_vec_reserve function
*/

#include <criterion/criterion.h>
#include <stdint.h>
#include "libmy/collections.h"

Test(my_vec_reserve, reverse_nothing)
{
    my_vec_t vec = { strdup("Test"), 5, 5, sizeof(char) };
    char *data = vec.data;

    cr_assert_eq(my_vec_reserve(&vec, 0), MY_VEC_OK);
    cr_assert_eq(vec.data, data);
    cr_assert_eq(vec.capacity, 5);
    cr_assert_eq(vec.length, 5);
}

Test(my_vec_reserve, reserve_with_no_previous_data)
{
    my_vec_t vec = { NULL, 0, 0, sizeof(char) };

    cr_assert_eq(my_vec_reserve(&vec, 5), MY_VEC_OK);
    cr_assert_geq(vec.capacity, 5);
    cr_assert_eq(vec.length, 0);

    vec.length = 5;
    strcpy(vec.data, "Test");
    cr_assert_str_eq(vec.data, "Test");
}

Test(my_vec_reserve, reserve_more_data)
{
    my_vec_t vec = { strdup("This"), 5, 5, sizeof(char) };
    char *data = vec.data;

    cr_assert_eq(my_vec_reserve(&vec, 10), MY_VEC_OK);
    cr_assert_neq(vec.data, data);
    cr_assert_geq(vec.capacity, 15);
    cr_assert_eq(vec.length, 5);

    vec.length = 15;
    strcpy(((char *)vec.data) + 4, " is a test");
    cr_assert_str_eq(vec.data, "This is a test");
}

Test(my_vec_reserve, double_capacity)
{
    my_vec_t vec = { malloc(8), 4, 8, sizeof(char) };

    strcpy(vec.data, "test");
    cr_assert_eq(my_vec_reserve(&vec, 9), MY_VEC_OK);
    cr_assert_eq(vec.capacity, 16);
    cr_assert_eq(vec.length, 4);

    vec.length = 13;
    strcpy(((char *)vec.data) + 4, " is cool");
    cr_assert_str_eq(vec.data, "test is cool");
}

Test(my_vec_reserve, data_overflow)
{
    my_vec_t vec = { NULL, 15, 15, sizeof(char) };

    cr_assert_eq(my_vec_reserve(&vec, SIZE_MAX), MY_VEC_CAPACITY_OVERFLOW);
}

Test(my_vec_reserve, capacity_overlow)
{
    my_vec_t vec = { NULL, SIZE_MAX - 4, SIZE_MAX - 42, sizeof(char) };

    cr_assert_eq(my_vec_reserve(&vec, 2), MY_VEC_ALLOC);
}
