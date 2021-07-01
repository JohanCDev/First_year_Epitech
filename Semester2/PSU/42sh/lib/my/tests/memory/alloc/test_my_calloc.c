/*
** EPITECH PROJECT, 2021
** LibMy unit tests
** File description:
** Tests the my_calloc function
*/

#include <criterion/criterion.h>
#include "libmy/memory/alloc.h"

Test(my_calloc, invalid)
{
    cr_assert_eq(NULL, my_calloc(0, 42));
    cr_assert_eq(NULL, my_calloc(42, 0));
    cr_assert_eq(NULL, my_calloc(42, SIZE_MAX));
}

Test(my_calloc, valid)
{
    int *array = my_calloc(21, sizeof(int));

    cr_assert_neq(NULL, array);
    for (size_t i = 0; i < 21; ++i)
        cr_assert_eq(0, array[i]);
}
