/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_vec_set_capacity function
*/

#include <criterion/criterion.h>
#include "libmy/collections.h"

static void elem_free(void *elem)
{
    free(*((char **)elem));
}

Test(my_vec_set_capacity, zero_capacity_frees_data_null_elem_free)
{
    char **array = malloc(sizeof(*array) * 4);
    my_vec_t vec;

    array[0] = strdup("This");
    array[1] = strdup("is");
    array[2] = strdup("a");
    array[3] = strdup("test");

    vec = (my_vec_t){(void *)array, 4, 4, sizeof(*array)};
    cr_assert_eq(my_vec_set_capacity(&vec, 0, NULL), MY_VEC_OK);
    cr_assert_eq(vec.capacity, 0);
    cr_assert_eq(vec.length, 0);
}

Test(my_vec_set_capacity, grow)
{
    char **array = malloc(sizeof(*array) * 4);
    my_vec_t vec;

    array[0] = strdup("This");
    array[1] = strdup("is");
    array[2] = strdup("a");
    array[3] = strdup("test");

    vec = (my_vec_t){(void *)array, 4, 4, sizeof(*array)};
    cr_assert_eq(my_vec_set_capacity(&vec, 5, &elem_free), MY_VEC_OK);
    vec.length = 5;

    cr_assert_str_eq(MY_VEC_GET_ELEM(char *, &vec, 0), "This");
    cr_assert_str_eq(MY_VEC_GET_ELEM(char *, &vec, 1), "is");
    cr_assert_str_eq(MY_VEC_GET_ELEM(char *, &vec, 2), "a");
    cr_assert_str_eq(MY_VEC_GET_ELEM(char *, &vec, 3), "test");

    MY_VEC_GET_ELEM(char *, &vec, 4) = strdup("of doom!");
    cr_assert_eq(vec.capacity, 5);
    cr_assert_str_eq(*((char **)my_vec_get(&vec, 4)), "of doom!");
}

Test(my_vec_set_capacity, shrink)
{
    char **array = malloc(sizeof(*array) * 4);
    my_vec_t vec;

    array[0] = strdup("This");
    array[1] = strdup("is");
    array[2] = strdup("a");
    array[3] = strdup("test");

    vec = (my_vec_t){(void *)array, 4, 4, sizeof(*array)};
    cr_assert_eq(my_vec_set_capacity(&vec, 2, &elem_free), MY_VEC_OK);
    cr_assert_eq(vec.length, 2);
    cr_assert_str_eq(MY_VEC_GET_ELEM(char *, &vec, 0), "This");
    cr_assert_str_eq(MY_VEC_GET_ELEM(char *, &vec, 1), "is");
}

Test(my_vec_set_capacity, shrink_with_null_elems)
{
    char **array = malloc(sizeof(*array) * 7);
    my_vec_t vec;

    array[0] = strdup("This");
    array[1] = strdup("is");
    array[2] = strdup("a");
    array[3] = strdup("test");
    array[4] = "cannot free";
    array[5] = "yup";
    array[6] = "nope";

    vec = (my_vec_t){(void *)array, 4, 7, sizeof(*array)};
    cr_assert_eq(my_vec_set_capacity(&vec, 2, &elem_free), MY_VEC_OK);
    cr_assert_eq(vec.length, 2);
    cr_assert_str_eq(MY_VEC_GET_ELEM(char *, &vec, 0), "This");
    cr_assert_str_eq(MY_VEC_GET_ELEM(char *, &vec, 1), "is");
}
