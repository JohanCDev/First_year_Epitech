/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_getnbr_base function
*/

#include <criterion/criterion.h>
#include <string.h>
#include <limits.h>
#include "libmy/parsing.h"

Test(my_getnbr_base, null_strings)
{
    cr_assert_eq(my_getnbr_base(NULL, NULL), 0);
    cr_assert_eq(my_getnbr_base(NULL, "ABCE"), 0);
    cr_assert_eq(my_getnbr_base("-12", NULL), 0);
}

Test(my_getnbr_base, empty_strings)
{
    cr_assert_eq(my_getnbr_base("", ""), 0);
    cr_assert_eq(my_getnbr_base("", "ABCE"), 0);
    cr_assert_eq(my_getnbr_base("-12", ""), 0);
}

Test(my_getnbr_base, invalid_numbers)
{
    cr_assert_eq(my_getnbr_base("A", "0129345689"), 0);
    cr_assert_eq(my_getnbr_base("42x", "0129345689"), 0);
    cr_assert_eq(my_getnbr_base("-+-.41", "0129345689"), 0);
}

Test(my_getnbr_base, overflow_numbers)
{
    cr_assert_eq(my_getnbr_base("123456789012", "0129345689"), 0);
    cr_assert_eq(my_getnbr_base("-9123456789012", "0129345689"), 0);
    cr_assert_eq(my_getnbr_base("2147483648", "0123456789"), 0);
    cr_assert_eq(my_getnbr_base("-2147483649", "0123456789"), 0);
}

Test(my_getnbr_base, base_10_positive_numbers)
{
    cr_assert_eq(my_getnbr_base("0", "0123456789"), 0);
    cr_assert_eq(my_getnbr_base("1", "0123456789"), 1);
    cr_assert_eq(my_getnbr_base("5", "0123456789"), 5);
    cr_assert_eq(my_getnbr_base("10", "0123456789"), 10);
    cr_assert_eq(my_getnbr_base("67830", "0123456789"), 67830);
    cr_assert_eq(my_getnbr_base("7819301", "0123456789"), 7819301);
}

Test(my_getnbr_base, base_10_negative_numbers)
{
    cr_assert_eq(my_getnbr_base("-0", "0123456789"), 0);
    cr_assert_eq(my_getnbr_base("-1", "0123456789"), -1);
    cr_assert_eq(my_getnbr_base("-4", "0123456789"), -4);
    cr_assert_eq(my_getnbr_base("-10", "0123456789"), -10);
    cr_assert_eq(my_getnbr_base("---675", "0123456789"), -675);
    cr_assert_eq(my_getnbr_base("+-123456", "0123456789"), -123456);
}

Test(my_getnbr_base, int_max)
{
    cr_assert_eq(my_getnbr_base("7fffffff", "0123456789abcdef"), INT_MAX);
    cr_assert_eq(my_getnbr_base("2147483647", "0123456789"), INT_MAX);
    cr_assert_eq(my_getnbr_base("17777777777", "01234567"), INT_MAX);
    cr_assert_eq(my_getnbr_base("1111111111111111111111111111111", "01"),
    INT_MAX);
}

Test(my_getnbr_base, int_min)
{
    cr_assert_eq(my_getnbr_base("-80000000", "0123456789abcdef"), INT_MIN);
    cr_assert_eq(my_getnbr_base("-2147483648", "0123456789"), INT_MIN);
    cr_assert_eq(my_getnbr_base("-20000000000", "01234567"), INT_MIN);
    cr_assert_eq(my_getnbr_base("-10000000000000000000000000000000", "01"),
    INT_MIN);
}
