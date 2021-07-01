/*
** EPITECH PROJECT, 2021
** Libmy unit tests
** File description:
** Tests the my_hasher_init function
*/

#include <criterion/criterion.h>
#include "libmy/hash.h"

Test(my_hasher_init, base)
{
    my_hasher_t hasher;

    my_hasher_init(&hasher, 21, 42);
    cr_assert_eq(hasher.inner.length, 0);
    cr_assert_eq(hasher.inner.key_1, 21);
    cr_assert_eq(hasher.inner.key_2, 42);
    cr_assert_eq(hasher.inner.tail, 0);
    cr_assert_eq(hasher.inner.ntail, 0);
}
