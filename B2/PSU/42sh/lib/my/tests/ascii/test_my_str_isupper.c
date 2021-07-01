/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_str_isupper function
*/

#include <criterion/criterion.h>
#include <string.h>
#include "libmy/ascii.h"

Test(my_str_isupper, null_string)
{
    cr_assert_eq(my_str_isupper(NULL), 0);
}

Test(my_str_isupper, empty_string)
{
    cr_assert_eq(my_str_isupper(""), 1);
}

Test(my_str_isupper, lowercase_string)
{
    cr_assert_eq(my_str_isupper("test"), 0);
}

Test(my_str_isupper, uppercase_string)
{
    cr_assert_eq(my_str_isupper("TEST"), 1);
}

Test(my_str_isupper, mixed_case_string)
{
    cr_assert_eq(my_str_isupper("ThisisaTEST"), 0);
}

Test(my_str_isupper, alpha_string_with_punctuation)
{
    cr_assert_eq(my_str_isupper("Is water wet?"), 0);
}

Test(my_str_isupper, wierd_chars)
{
    cr_assert_eq(my_str_isupper(" \a\t!\"#$%&'()*+,-./073:;<=>?@[\\]^`{~}"), 0);
}

Test(my_str_isupper, char_below_upper_a)
{
    cr_assert_eq(my_str_isupper(" "), 0);
}

Test(my_str_isupper, char_between_upper_z_and_upper_a)
{
    cr_assert_eq(my_str_isupper("^"), 0);
}

Test(my_str_isupper, char_above_upper_z)
{
    cr_assert_eq(my_str_isupper("~"), 0);
}
