/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_next_size_t function
*/

#include <criterion/criterion.h>
#include "libmy/parsing.h"

Test(my_next_size_t, invalid_params)
{
    char const *str = NULL;
    char const *below_zero = " ";
    char const *above_nine = "X";
    size_t dst = 0;

    cr_assert_neq(my_next_size_t(NULL, &dst), 0);
    cr_assert_neq(my_next_size_t(&str, &dst), 0);
    cr_assert_neq(my_next_size_t(&below_zero, NULL), 0);
    cr_assert_neq(my_next_size_t(&below_zero, &dst), 0);
    cr_assert_neq(my_next_size_t(&above_nine, &dst), 0);
}

Test(my_next_size_t, zero)
{
    char const *str = "0zx";
    size_t dst = 42;

    cr_assert_eq(my_next_size_t(&str, &dst), 0);
    cr_assert_eq(dst, 0);
    cr_assert_str_eq(str, "zx");
}

Test(my_next_size_t, leading_zeros)
{
    char const *str = "00042";
    size_t dst = 21;

    cr_assert_eq(my_next_size_t(&str, &dst), 0);
    cr_assert_eq(dst, 0);
    cr_assert_str_eq(str, "0042");
}

Test(my_next_size_t, leading_zeros_null_dst)
{
    char const *str = "00042";

    cr_assert_eq(my_next_size_t(&str, NULL), 0);
    cr_assert_str_eq(str, "0042");
}

Test(my_next_size_t, digit_followed_by_zero)
{
    char const *str = "40";
    size_t dst = 76;

    cr_assert_eq(my_next_size_t(&str, &dst), 0);
    cr_assert_eq(dst, 40);
    cr_assert_str_eq(str, "");
}

Test(my_next_size_t, normal_number)
{
    char const *str = "12340567890 is an awesome number!";
    size_t dst = 21;

    cr_assert_eq(my_next_size_t(&str, &dst), 0);
    cr_assert_eq(dst, 12340567890);
    cr_assert_str_eq(str, " is an awesome number!");
}

Test(my_next_size_t, normal_number_null_dst)
{
    char const *str = "12340567890 is an awesome number!";

    cr_assert_eq(my_next_size_t(&str, NULL), 0);
    cr_assert_str_eq(str, " is an awesome number!");
}

Test(my_next_size_t, size_max)
{
    char const *str = "18446744073709551615!?";
    size_t dst = 21;

    cr_assert_eq(my_next_size_t(&str, &dst), 0);
    cr_assert_eq(dst, 18446744073709551615);
    cr_assert_str_eq(str, "!?");
}

Test(my_next_size_t, above_size_max)
{
    char const *str = "18446744073709551616!";
    size_t dst = 21;

    cr_assert_eq(my_next_size_t(&str, &dst), 0);
    cr_assert_eq(dst, 1844674407370955161);
    cr_assert_str_eq(str, "!");
}

Test(my_next_size_t, size_max_overflowing)
{
    char const *str = "1844674407370955161567163781381...";
    size_t dst = 21;

    cr_assert_eq(my_next_size_t(&str, &dst), 0);
    cr_assert_eq(dst, 18446744073709551615);
    cr_assert_str_eq(str, "...");
}
