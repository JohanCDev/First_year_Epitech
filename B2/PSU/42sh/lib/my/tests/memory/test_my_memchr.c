/*
** EPITECH PROJECT, 2021
** LibMy unit tests
** File description:
** Tests the my_memchr function
*/

#include <criterion/criterion.h>
#include "libmy/memory.h"

Test(my_memchr, not_found)
{
    char const *data = "This is a test";

    cr_assert_eq(my_memchr(data, 'T', 0), NULL);
    cr_assert_eq(my_memchr(data, 'a', 4), NULL);
    cr_assert_eq(my_memchr(data, 'X', 14), NULL);
}

Test(my_memchr, found)
{
    char const *data = "This is a test";

    cr_assert_eq(my_memchr(data, 'T', 1), data);
    cr_assert_eq(my_memchr(data, 'a', 9), data + 8);
    cr_assert_eq(my_memchr(data, 's', 14), data + 3);
}
