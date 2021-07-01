/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_vec_free function
*/

#include <criterion/criterion.h>
#include "libmy/collections.h"

static void elem_free(void *elem)
{
    free(*((char **)elem));
}

Test(my_vec_free, null_vec)
{
    my_vec_free(NULL, &elem_free);
}

Test(my_vec_free, zero_capacity)
{
    my_vec_t vec = { strdup("test"), 8, 0, sizeof(char) };

    my_vec_free(&vec, &elem_free);
    cr_assert_eq(vec.data, NULL);
    cr_assert_eq(vec.length, 0);
    cr_assert_eq(vec.capacity, 0);
    cr_assert_eq(vec.elem_size, 0);
}

Test(my_vec_free, zero_len)
{
    my_vec_t vec = { strdup("test"), 0, 78, sizeof(char) };

    my_vec_free(&vec, &elem_free);
    cr_assert_eq(vec.data, NULL);
    cr_assert_eq(vec.length, 0);
    cr_assert_eq(vec.capacity, 0);
    cr_assert_eq(vec.elem_size, 0);
}

Test(my_vec_free, null_data)
{
    my_vec_t vec = { NULL, 4, 5, sizeof(char) };

    my_vec_free(&vec, &elem_free);
    cr_assert_eq(vec.data, NULL);
    cr_assert_eq(vec.length, 0);
    cr_assert_eq(vec.capacity, 0);
    cr_assert_eq(vec.elem_size, 0);
}

Test(my_vec_free, str_vec)
{
    my_vec_t vec = { strdup("This is a test"), 15, 15, sizeof(char) };

    my_vec_free(&vec, NULL);
    cr_assert_eq(vec.data, NULL);
    cr_assert_eq(vec.length, 0);
    cr_assert_eq(vec.capacity, 0);
    cr_assert_eq(vec.elem_size, 0);
}

Test(my_vec_free, str_array_vec)
{
    char **array = malloc(sizeof(*array) * 4);
    my_vec_t vec;

    array[0] = strdup("This");
    array[1] = strdup("is");
    array[2] = strdup("a");
    array[3] = strdup("test");
    vec = (my_vec_t){ array, 4, 4, sizeof(*array) };
    my_vec_free(&vec, &elem_free);
    cr_assert_eq(vec.data, NULL);
    cr_assert_eq(vec.length, 0);
    cr_assert_eq(vec.capacity, 0);
    cr_assert_eq(vec.elem_size, 0);
}
