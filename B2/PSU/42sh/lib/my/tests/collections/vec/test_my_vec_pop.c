/*
** EPITECH PROJECT, 2020
** LibMy - collections module
** File description:
** Tests the my_vec_pop function
*/

#include <criterion/criterion.h>
#include "libmy/collections.h"

Test(my_vec_pop, pop_nothing)
{
    my_vec_t vec = { NULL, 0, 0, sizeof(short) };

    my_vec_pop(&vec, NULL);
}

Test(my_vec_pop, pop_all)
{
    my_vec_t vec = { strdup("TEST"), 5, 5, sizeof(char) };
    char d1;
    char d2[4];

    my_vec_pop(&vec, &d1);
    cr_assert_eq(d1, '\0');
    cr_assert_eq(vec.length, 4);
    my_vec_pop_multiple(&vec, &d2, 4);
    cr_assert_eq(d2[0], 'T');
    cr_assert_eq(d2[1], 'E');
    cr_assert_eq(d2[2], 'S');
    cr_assert_eq(d2[3], 'T');
    cr_assert_eq(vec.capacity, 5);
}

Test(my_vec_pop, pop_shorts)
{
    my_vec_t vec = { malloc(sizeof(short) * 5), 3, 5, sizeof(short) };
    short d1;

    ((short *)vec.data)[0] = 42;
    ((short *)vec.data)[1] = -1;
    ((short *)vec.data)[2] = 99;

    my_vec_pop(&vec, &d1);
    cr_assert_eq(d1, 99);
    cr_assert_eq(vec.length, 2);
    cr_assert_eq(MY_VEC_GET_ELEM(short, &vec, 0), 42);
    cr_assert_eq(MY_VEC_GET_ELEM(short, &vec, 1), -1);
    cr_assert_eq(vec.capacity, 5);
}

Test(my_vec_pop, clear_vec)
{
    my_vec_t vec = { strdup("TEST"), 5, 5, sizeof(char) };

    my_vec_pop_multiple(&vec, NULL, 5);
    cr_assert_eq(vec.length, 0);
    cr_assert_eq(vec.capacity, 5);
}
