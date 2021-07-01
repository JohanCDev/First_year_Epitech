/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_vec_push function
*/

#include <criterion/criterion.h>
#include <stdint.h>
#include "libmy/collections.h"

Test(my_vec_push, push_to_empty_data)
{
    my_vec_t vec = { NULL, 0, 0, sizeof(char) };

    cr_assert_eq(my_vec_push_multiple(&vec, "This is a test", 14), MY_VEC_OK);
    cr_assert_eq(vec.length, 14);

    cr_assert_eq(my_vec_push(&vec, "!"), MY_VEC_OK);
    cr_assert_eq(vec.length, 15);
    cr_assert_eq(my_vec_push(&vec, "\0"), MY_VEC_OK);
    cr_assert_eq(vec.length, 16);
    cr_assert_str_eq(vec.data, "This is a test!");
}

Test(my_vec_push, push_not_enough_capacity)
{
    my_vec_t vec = { strdup("Collection ?"), 12, 12, sizeof(char) };

    cr_assert_eq(my_vec_push_multiple(&vec, " Vector!", 9), MY_VEC_OK);
    cr_assert_eq(vec.length, 21);
    cr_assert_str_eq(vec.data, "Collection ? Vector!");
}

Test(my_vec_push, push_enough_capacity)
{
    char *data = malloc(sizeof(char) * 21);
    my_vec_t vec = { data, 12, 21, sizeof(char) };

    strcpy(data, "Collection ?");
    cr_assert_eq(my_vec_push_multiple(&vec, " Vector!", 9), MY_VEC_OK);
    cr_assert_eq(vec.length, 21);
    cr_assert_str_eq(vec.data, "Collection ? Vector!");
}

Test(my_vec_push, push_ints)
{
    my_vec_t vec = { NULL, 0, 0, sizeof(int) };
    int d1 = 42;
    int d2[] = { 1, 2 };

    cr_assert_eq(my_vec_push(&vec, &d1), MY_VEC_OK);
    cr_assert_eq(vec.length, 1);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 0), 42);
    cr_assert_eq(my_vec_push_multiple(&vec, &d2, 2), MY_VEC_OK);
    cr_assert_eq(vec.length, 3);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 1), 1);
    cr_assert_eq(MY_VEC_GET_ELEM(int, &vec, 2), 2);
}

Test(my_vec_push, push_big)
{
    unsigned char *big = malloc(2048);
    my_vec_t vec = { NULL, 0, 0, sizeof(unsigned char[2048]) };

    for (int i = 0; i < 2048; ++i)
        big[i] = i % 256;
    cr_assert_eq(my_vec_push(&vec, big), MY_VEC_OK);
    cr_assert_eq(vec.length, 1);
}

Test(my_vec_push, capacity_overflow)
{
    my_vec_t vec = { NULL, SIZE_MAX, SIZE_MAX, sizeof(int) };
    int d1 = 42;

    cr_assert_eq(my_vec_push(&vec, &d1), MY_VEC_CAPACITY_OVERFLOW);
}
