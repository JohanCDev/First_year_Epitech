/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_str_isalpha function
*/

#include <criterion/criterion.h>
#include <string.h>
#include "libmy/ascii.h"

Test(my_str_isalpha, null_string)
{
    cr_assert_eq(my_str_isalpha(NULL), 0);
}

Test(my_str_isalpha, empty_string)
{
    cr_assert_eq(my_str_isalpha(""), 1);
}

Test(my_str_isalpha, lowercase_string)
{
    cr_assert_eq(my_str_isalpha("test"), 1);
}

Test(my_str_isalpha, uppercase_string)
{
    cr_assert_eq(my_str_isalpha("TEST"), 1);
}

Test(my_str_isalpha, mixed_case_string)
{
    cr_assert_eq(my_str_isalpha("ThisisaTEST"), 1);
}

Test(my_str_isalpha, alpha_string_with_punctuation)
{
    cr_assert_eq(my_str_isalpha("Is water wet?"), 0);
}

Test(my_str_isalpha, wierd_chars)
{
    cr_assert_eq(my_str_isalpha(" \a\t!\"#$%&'()*+,-./073:;<=>?@[\\]^`{~}"), 0);
}

Test(my_str_isalpha, char_below_upper_a)
{
    cr_assert_eq(my_str_isalpha(" "), 0);
}

Test(my_str_isalpha, char_between_upper_z_and_lower_a)
{
    cr_assert_eq(my_str_isalpha("^"), 0);
}

Test(my_str_isalpha, char_above_lower_z)
{
    cr_assert_eq(my_str_isalpha("~"), 0);
}
