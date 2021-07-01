/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_getnbr function
*/

#include <criterion/criterion.h>
#include <string.h>
#include <limits.h>
#include "libmy/parsing.h"

Test(my_getnbr, null_string)
{
    cr_assert_eq(my_getnbr(NULL), 0);
}

Test(my_getnbr, empty_string)
{
    cr_assert_eq(my_getnbr(""), 0);
}

Test(my_getnbr, invalid_numbers)
{
    cr_assert_eq(my_getnbr("A"), 0);
    cr_assert_eq(my_getnbr("-+-.41"), 0);
}

Test(my_getnbr, overflow_numbers)
{
    cr_assert_eq(my_getnbr("123456789012"), 0);
    cr_assert_eq(my_getnbr("-9123456789012"), 0);
    cr_assert_eq(my_getnbr("2147483648"), 0);
    cr_assert_eq(my_getnbr("-2147483649"), 0);
}

Test(my_getnbr, positive_numbers)
{
    cr_assert_eq(my_getnbr("0"), 0);
    cr_assert_eq(my_getnbr("1"), 1);
    cr_assert_eq(my_getnbr("5"), 5);
    cr_assert_eq(my_getnbr("10"), 10);
    cr_assert_eq(my_getnbr("67830"), 67830);
    cr_assert_eq(my_getnbr("7819301"), 7819301);
}

Test(my_getnbr, negative_numbers)
{
    cr_assert_eq(my_getnbr("-0"), 0);
    cr_assert_eq(my_getnbr("-1"), -1);
    cr_assert_eq(my_getnbr("-4"), -4);
    cr_assert_eq(my_getnbr("-10"), -10);
    cr_assert_eq(my_getnbr("---675"), -675);
    cr_assert_eq(my_getnbr("+-123456"), -123456);
}

Test(my_getnbr, int_max)
{
    cr_assert_eq(my_getnbr("2147483647"), INT_MAX);
}

Test(my_getnbr, int_min)
{
    cr_assert_eq(my_getnbr("-2147483648"), INT_MIN);
}

Test(my_getnbr, lenient_parsing)
{
    cr_assert_eq(my_getnbr("42 is not 21"), 42);
    cr_assert_eq(my_getnbr("---20toto12"), -20);
}

Test(my_getnbr_strict, null_string)
{
    cr_assert_eq(my_getnbr_strict(NULL), 0);
}

Test(my_getnbr_strict, empty_string)
{
    cr_assert_eq(my_getnbr_strict(""), 0);
}

Test(my_getnbr_strict, invalid_numbers)
{
    cr_assert_eq(my_getnbr_strict("A"), 0);
    cr_assert_eq(my_getnbr_strict("-+-.41"), 0);
}

Test(my_getnbr_strict, overflow_numbers)
{
    cr_assert_eq(my_getnbr_strict("123456789012"), 0);
    cr_assert_eq(my_getnbr_strict("-9123456789012"), 0);
    cr_assert_eq(my_getnbr_strict("2147483648"), 0);
    cr_assert_eq(my_getnbr_strict("-2147483649"), 0);
}

Test(my_getnbr_strict, positive_numbers)
{
    cr_assert_eq(my_getnbr_strict("0"), 0);
    cr_assert_eq(my_getnbr_strict("1"), 1);
    cr_assert_eq(my_getnbr_strict("5"), 5);
    cr_assert_eq(my_getnbr_strict("10"), 10);
    cr_assert_eq(my_getnbr_strict("67830"), 67830);
    cr_assert_eq(my_getnbr_strict("7819301"), 7819301);
}

Test(my_getnbr_strict, negative_numbers)
{
    cr_assert_eq(my_getnbr_strict("-0"), 0);
    cr_assert_eq(my_getnbr_strict("-1"), -1);
    cr_assert_eq(my_getnbr_strict("-4"), -4);
    cr_assert_eq(my_getnbr_strict("-10"), -10);
    cr_assert_eq(my_getnbr_strict("---675"), -675);
    cr_assert_eq(my_getnbr_strict("+-123456"), -123456);
}

Test(my_getnbr_strict, int_max)
{
    cr_assert_eq(my_getnbr_strict("2147483647"), INT_MAX);
}

Test(my_getnbr_strict, int_min)
{
    cr_assert_eq(my_getnbr_strict("-2147483648"), INT_MIN);
}

Test(my_getnbr_strict, strict_parsing)
{
    cr_assert_eq(my_getnbr_strict("42 is not 21"), 0);
    cr_assert_eq(my_getnbr_strict("---20toto12"), 0);
}
