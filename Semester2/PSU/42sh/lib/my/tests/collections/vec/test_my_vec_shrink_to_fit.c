/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_vec_shrink_to_fit function
*/

#include <criterion/criterion.h>
#include "libmy/collections.h"

Test(my_vec_shrink_to_fit, zero_capacity_frees_data)
{
    my_vec_t vec = { malloc(sizeof(char) * 5), 0, 5, sizeof(char) };

    cr_assert_eq(my_vec_shrink_to_fit(&vec), MY_VEC_OK);
    cr_assert_eq(vec.capacity, 0);
    cr_assert_eq(vec.data, NULL);
}

Test(my_vec_shrink_to_fit, shrink)
{
    char **array = malloc(sizeof(*array) * 7);
    my_vec_t vec;

    array[0] = strdup("This");
    array[1] = strdup("is");
    array[2] = strdup("a");
    array[3] = strdup("test");

    vec = (my_vec_t){ (void *)array, 4, 7, sizeof(*array) };
    cr_assert_eq(my_vec_shrink_to_fit(&vec), MY_VEC_OK);
    cr_assert_eq(vec.capacity, 4);

    cr_assert_str_eq(MY_VEC_GET_ELEM(char *, &vec, 0), "This");
    cr_assert_str_eq(MY_VEC_GET_ELEM(char *, &vec, 1), "is");
    cr_assert_str_eq(MY_VEC_GET_ELEM(char *, &vec, 2), "a");
    cr_assert_str_eq(MY_VEC_GET_ELEM(char *, &vec, 3), "test");
}
