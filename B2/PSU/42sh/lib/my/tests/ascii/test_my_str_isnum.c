/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_str_isnum function
*/

#include <criterion/criterion.h>
#include <string.h>
#include "libmy/ascii.h"

Test(my_str_isnum, null_string)
{
    cr_assert_eq(my_str_isnum(NULL), 0);
}

Test(my_str_isnum, empty_string)
{
    cr_assert_eq(my_str_isnum(""), 1);
}

Test(my_str_isnum, number_string)
{
    cr_assert_eq(my_str_isnum("783421623020963"), 1);
}

Test(my_str_isnum, float_string)
{
    cr_assert_eq(my_str_isnum("4.42"), 0);
}

Test(my_str_isnum, wierd_chars)
{
    cr_assert_eq(my_str_isnum(" \a\t!\"#$%&'()*+,-./073:;<=>?@[\\]^`{~}"), 0);
}

Test(my_str_isnum, char_below_0)
{
    cr_assert_eq(my_str_isnum(" "), 0);
}

Test(my_str_isnum, char_above_9)
{
    cr_assert_eq(my_str_isnum(":"), 0);
}
