/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_vec_init_capacity function
*/

#include <criterion/criterion.h>
#include "libmy/collections.h"

Test(my_vec_init_capacity, zero_capacity)
{
    my_vec_t vec;

    cr_assert_eq(my_vec_init_capacity(&vec, 0, sizeof(char)), MY_VEC_OK);
    cr_assert_eq(vec.data, NULL);
    cr_assert_eq(vec.length, 0);
    cr_assert_eq(vec.capacity, 0);
    cr_assert_eq(vec.elem_size, sizeof(char));
}

Test(my_vec_init_capacity, zero_elem_size)
{
    my_vec_t vec;

    cr_assert_eq(my_vec_init_capacity(&vec, 4, 0), MY_VEC_ZERO_ELEM_SIZE);
}

Test(my_vec_init_capacity, one_capacity)
{
    my_vec_t vec;

    cr_assert_eq(my_vec_init_capacity(&vec, 1, sizeof(char)), MY_VEC_OK);
    cr_assert_neq(vec.data, NULL);
    cr_assert_eq(vec.length, 0);
    cr_assert_eq(vec.capacity, 1);
    cr_assert_eq(vec.elem_size, sizeof(char));

    ((char *)vec.data)[0] = 'A';
    cr_assert_eq(((char *)vec.data)[0], 'A');
}

Test(my_vec_init_capacity, fourteen_capacity)
{
    my_vec_t vec;

    cr_assert_eq(my_vec_init_capacity(&vec, 14, sizeof(char)), MY_VEC_OK);
    cr_assert_neq(vec.data, NULL);
    cr_assert_eq(vec.length, 0);
    cr_assert_eq(vec.capacity, 14);
    cr_assert_eq(vec.elem_size, sizeof(char));

    strcpy((char *)vec.data, "This is a test");
    cr_assert_str_eq(vec.data, "This is a test");
}
