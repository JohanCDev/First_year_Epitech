/*
** EPITECH PROJECT, 2021
** LibMy unit tests
** File description:
** Tests the my_next_uint function
*/

#include <criterion/criterion.h>
#include "libmy/parsing.h"

Test(my_next_uint, invalid_params)
{
    char const *str = NULL;
    char const *below_zero = " ";
    char const *above_nine = "X";
    unsigned dst = 0;

    cr_assert_neq(my_next_uint(NULL, &dst), 0);
    cr_assert_neq(my_next_uint(&str, &dst), 0);
    cr_assert_neq(my_next_uint(&below_zero, NULL), 0);
    cr_assert_neq(my_next_uint(&below_zero, &dst), 0);
    cr_assert_neq(my_next_uint(&above_nine, &dst), 0);
}

Test(my_next_uint, zero)
{
    char const *str = "0zx";
    unsigned dst = 42;

    cr_assert_eq(my_next_uint(&str, &dst), 0);
    cr_assert_eq(dst, 0);
    cr_assert_str_eq(str, "zx");
}

Test(my_next_uint, leading_zeros)
{
    char const *str = "00042";
    unsigned dst = 21;

    cr_assert_eq(my_next_uint(&str, &dst), 0);
    cr_assert_eq(dst, 0);
    cr_assert_str_eq(str, "0042");
}

Test(my_next_uint, leading_zeros_null_dst)
{
    char const *str = "00042";

    cr_assert_eq(my_next_uint(&str, NULL), 0);
    cr_assert_str_eq(str, "0042");
}

Test(my_next_uint, digit_followed_by_zero)
{
    char const *str = "40";
    unsigned dst = 76;

    cr_assert_eq(my_next_uint(&str, &dst), 0);
    cr_assert_eq(dst, 40);
    cr_assert_str_eq(str, "");
}

Test(my_next_uint, normal_number)
{
    char const *str = "1234 is an awesome number!";
    unsigned dst = 21;

    cr_assert_eq(my_next_uint(&str, &dst), 0);
    cr_assert_eq(dst, 1234);
    cr_assert_str_eq(str, " is an awesome number!");
}

Test(my_next_uint, normal_number_null_dst)
{
    char const *str = "1234 is an awesome number!";

    cr_assert_eq(my_next_uint(&str, NULL), 0);
    cr_assert_str_eq(str, " is an awesome number!");
}

Test(my_next_uint, uint_max)
{
    char const *str = "4294967295!?";
    unsigned dst = 21;

    cr_assert_eq(my_next_uint(&str, &dst), 0);
    cr_assert_eq(dst, 4294967295);
    cr_assert_str_eq(str, "!?");
}

Test(my_next_uint, above_uint_max)
{
    char const *str = "4294967296!";
    unsigned dst = 21;

    cr_assert_eq(my_next_uint(&str, &dst), 0);
    cr_assert_eq(dst, 429496729);
    cr_assert_str_eq(str, "!");
}

Test(my_next_uint, uint_max_overflowing)
{
    char const *str = "42949672954294967295...";
    unsigned dst = 21;

    cr_assert_eq(my_next_uint(&str, &dst), 0);
    cr_assert_eq(dst, 4294967295);
    cr_assert_str_eq(str, "...");
}
