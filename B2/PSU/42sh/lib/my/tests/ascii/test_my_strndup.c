/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_strndup function
*/

#include <stddef.h>
#include <stdlib.h>
#include <criterion/criterion.h>

#include "libmy/ascii.h"

Test(my_strndup, null_string)
{
    cr_assert_eq(my_strndup(NULL, 42), NULL);
}

Test(my_strndup, empty_string)
{
    char *src = "";
    char *dup = my_strndup(src, 42);

    cr_assert_neq(src, dup);
    cr_assert_str_eq(src, dup);
    free(dup);
}

Test(my_strndup, zero_length)
{
    char *src = "test";
    char *dup = my_strndup(src, 0);

    cr_assert_neq(src, dup);
    cr_assert_str_eq(dup, "");
    free(dup);
}

Test(my_strndup, regular_string_no_terminator)
{
    char *src = "This is a test";
    char *dup = my_strndup(src, 14);

    cr_assert_neq(src, dup);
    cr_assert_str_eq(src, dup);
    free(dup);
}

Test(my_strndup, regular_string_with_terminator)
{
    char *src = "This is a test";
    char *dup = my_strndup(src, 15);

    cr_assert_neq(src, dup);
    cr_assert_str_eq(src, dup);
    free(dup);
}
