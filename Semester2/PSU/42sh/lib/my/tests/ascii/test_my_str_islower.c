/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_str_islower function
*/

#include <criterion/criterion.h>
#include <string.h>
#include "libmy/ascii.h"

Test(my_str_islower, null_string)
{
    cr_assert_eq(my_str_islower(NULL), 0);
}

Test(my_str_islower, empty_string)
{
    cr_assert_eq(my_str_islower(""), 1);
}

Test(my_str_islower, lowercase_string)
{
    cr_assert_eq(my_str_islower("test"), 1);
}

Test(my_str_islower, uppercase_string)
{
    cr_assert_eq(my_str_islower("TEST"), 0);
}

Test(my_str_islower, mixed_case_string)
{
    cr_assert_eq(my_str_islower("ThisisaTEST"), 0);
}

Test(my_str_islower, alpha_string_with_punctuation)
{
    cr_assert_eq(my_str_islower("Is water wet?"), 0);
}

Test(my_str_islower, wierd_chars)
{
    cr_assert_eq(my_str_islower(" \a\t!\"#$%&'()*+,-./073:;<=>?@[\\]^`{~}"), 0);
}

Test(my_str_islower, char_below_upper_a)
{
    cr_assert_eq(my_str_islower(" "), 0);
}

Test(my_str_islower, char_between_upper_z_and_lower_a)
{
    cr_assert_eq(my_str_islower("^"), 0);
}

Test(my_str_islower, char_above_lower_z)
{
    cr_assert_eq(my_str_islower("~"), 0);
}
