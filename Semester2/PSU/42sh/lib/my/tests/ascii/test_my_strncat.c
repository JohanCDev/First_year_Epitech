/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_strncat function
*/

#include <criterion/criterion.h>
#include <string.h>
#include "libmy/ascii.h"

Test(my_strncat, null_src)
{
    char dst[] = "hello world!";
    char *expected = strdup(dst);

    cr_assert_str_eq(my_strncat(dst, NULL, 89), expected);
}

Test(my_strncat, zero_size)
{
    char *src = "\nhello hello!";
    char dst[] = "hello world!";
    char *expected = strdup(dst);

    cr_assert_str_eq(my_strncat(dst, src, 0), expected);
}

Test(my_strncat, empty_src)
{
    char dst[] = "foobar";
    char *expected = strdup(dst);

    cr_assert_str_eq(my_strncat(dst, "", 72), expected);
}

Test(my_strncat, empty_dst)
{
    char *src = "This is a test";
    char dst[15] = { 0 };
    char *expected = strdup(src);

    cr_assert_str_eq(my_strncat(dst, src, 15), expected);
}

Test(my_strncat, empty_dst_cut)
{
    char *src = "This is a test";
    char dst[15] = { 0 };
    char *expected = "This";

    cr_assert_str_eq(my_strncat(dst, src, 4), expected);
}

Test(my_strncat, just_enough_space_for_both)
{
    char *src = " OK";
    char dst[11] = "This is\0";
    char *expected = "This is OK";

    cr_assert_str_eq(my_strncat(dst, src, 11), expected);
}

Test(my_strncat, extra_space_for_both)
{
    char *src = " OK";
    char dst[18] = "This is\0";
    char *expected = "This is OK";

    cr_assert_str_eq(my_strncat(dst, src, 18), expected);
}
