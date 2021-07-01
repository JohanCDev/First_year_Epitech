/*
** EPITECH PROJECT, 2021
** LibMy unit tests
** File description:
** Tests the my_vec_clear function
*/

#include <criterion/criterion.h>
#include "libmy/collections/vec.h"

static void should_not_be_called(void *elem)
{
    (void)elem;
    cr_assert(0);
}

static unsigned *free_count(void)
{
    static unsigned free_count = 0;

    return &free_count;
}

static void count_free(void *elem)
{
    (void)elem;
    *(free_count()) += 1;
}

Test(my_vec_clear, empty_zero_capacity)
{
    my_vec_t vec;

    my_vec_init(&vec, sizeof(short));
    my_vec_clear(&vec, &should_not_be_called);
    cr_assert_eq(vec.length, 0);
    cr_assert_eq(vec.capacity, 0);
    cr_assert_eq(vec.data, NULL);
}

Test(my_vec_clear, empty_some_capacity)
{
    my_vec_t vec;

    my_vec_init_capacity(&vec, 32, sizeof(short));
    my_vec_clear(&vec, &should_not_be_called);
    cr_assert_eq(vec.length, 0);
    cr_assert_eq(vec.capacity, 32);
    cr_assert_neq(vec.data, NULL);
    my_vec_free(&vec, &should_not_be_called);
}

Test(my_vec_clear, some_elements)
{
    my_vec_t vec;
    short val = 42;

    my_vec_init_capacity(&vec, 32, sizeof(short));
    my_vec_push(&vec, &val);
    my_vec_push(&vec, &val);
    my_vec_push(&vec, &val);
    my_vec_push(&vec, &val);
    *(free_count()) = 0;
    my_vec_clear(&vec, &count_free);
    cr_assert_eq(*(free_count()), 4);
    cr_assert_eq(vec.length, 0);
    cr_assert_eq(vec.capacity, 32);
    cr_assert_neq(vec.data, NULL);
    my_vec_push(&vec, &val);
    my_vec_clear(&vec, NULL);
    cr_assert_eq(vec.length, 0);
    cr_assert_eq(vec.capacity, 32);
    cr_assert_neq(vec.data, NULL);
    my_vec_free(&vec, &should_not_be_called);
}
