/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_strcat function
*/

#include <criterion/criterion.h>
#include <string.h>
#include "libmy/ascii.h"

Test(my_strcat, null_src)
{
    char dst[] = "hello world!";
    char *expected = strdup(dst);

    cr_assert_str_eq(my_strcat(dst, NULL), expected);
}

Test(my_strcat, empty_src)
{
    char dst[] = "foobar";
    char *expected = strdup(dst);

    cr_assert_str_eq(my_strcat(dst, ""), expected);
}

Test(my_strcat, empty_dst)
{
    char *src = "This is a test";
    char dst[15] = { 0 };
    char *expected = strdup(src);

    cr_assert_str_eq(my_strcat(dst, src), expected);
}

Test(my_strcat, just_enough_space_for_both)
{
    char *src = " OK";
    char dst[11] = "This is\0";
    char *expected = "This is OK";

    cr_assert_str_eq(my_strcat(dst, src), expected);
}

Test(my_strcat, extra_space_for_both)
{
    char *src = " OK";
    char dst[18] = "This is\0";
    char *expected = "This is OK";

    cr_assert_str_eq(my_strcat(dst, src), expected);
}
