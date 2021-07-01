/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_vec_insert function
*/

#include <stdint.h>
#include <criterion/criterion.h>
#include "libmy/collections.h"

Test(my_vec_insert, insert_to_empty_data)
{
    my_vec_t vec = {NULL, 0, 0, sizeof(char)};

    cr_assert_eq(
        my_vec_insert_multiple(&vec, "This is a test", 0, 14), MY_VEC_OK);
    cr_assert_eq(vec.length, 14);
    cr_assert_eq(my_vec_insert_multiple(&vec, " not", 7, 4), MY_VEC_OK);
    cr_assert_eq(vec.length, 18);
    cr_assert_eq(my_vec_insert_multiple(&vec, "Hello, ", 0, 7), MY_VEC_OK);
    cr_assert_eq(vec.length, 25);
    cr_assert_eq(my_vec_insert(&vec, "\0", 25), MY_VEC_OK);
    cr_assert_eq(vec.length, 26);
    cr_assert_eq(my_vec_insert(&vec, "!", 25), MY_VEC_OK);
    cr_assert_eq(vec.length, 27);
    cr_assert_str_eq(vec.data, "Hello, This is not a test!");
}

Test(my_vec_insert, insert_not_enough_capacity)
{
    my_vec_t vec = {strdup("Lib Vector!"), 12, 12, sizeof(char)};

    cr_assert_eq(
        my_vec_insert_multiple(&vec, " Collection ?", 3, 13), MY_VEC_OK);
    cr_assert_eq(vec.length, 25);
    cr_assert_str_eq(vec.data, "Lib Collection ? Vector!");
}

Test(my_vec_insert, insert_enough_capacity)
{
    char *data = malloc(sizeof(char) * 25);
    my_vec_t vec = {data, 12, 25, sizeof(char)};

    strcpy(data, "Lib Vector!");
    cr_assert_eq(
        my_vec_insert_multiple(&vec, " Collection ?", 3, 13), MY_VEC_OK);
    cr_assert_eq(vec.length, 25);
    cr_assert_str_eq(vec.data, "Lib Collection ? Vector!");
}

Test(my_vec_insert, capacity_overflow)
{
    my_vec_t vec = {NULL, SIZE_MAX, SIZE_MAX, sizeof(int)};
    int d1 = 42;

    cr_assert_eq(my_vec_insert(&vec, &d1, 0), MY_VEC_CAPACITY_OVERFLOW);
}
