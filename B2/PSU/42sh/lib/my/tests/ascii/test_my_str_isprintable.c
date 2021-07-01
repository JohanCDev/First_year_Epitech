/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_str_isprintable function
*/

#include <criterion/criterion.h>
#include <string.h>
#include "libmy/ascii.h"

Test(my_str_isprint, null_string)
{
    cr_assert_eq(my_str_isprintable(NULL), 0);
}

Test(my_str_isprint, empty_string)
{
    cr_assert_eq(my_str_isprintable(""), 1);
}

Test(my_str_isprint, lowercase_string)
{
    cr_assert_eq(my_str_isprintable("test"), 1);
}

Test(my_str_isprint, uppercase_string)
{
    cr_assert_eq(my_str_isprintable("TEST"), 1);
}

Test(my_str_isprint, mixed_case_string)
{
    cr_assert_eq(my_str_isprintable("ThisisaTEST"), 1);
}

Test(my_str_isprint, alpha_string_with_punctuation)
{
    cr_assert_eq(my_str_isprintable("Is water wet?"), 1);
}

Test(my_str_isprint, wierd_chars)
{
    cr_assert_eq(my_str_isprintable(" \a\t!\"#$%&'()*+,-./073:;<=>?@[\\]^`{~}"),
    0);
}

Test(my_str_isprint, no_printable_lower)
{
    cr_assert_eq(my_str_isprintable("\r"), 0);
}

Test(my_str_isprint, no_printable_upper)
{
    cr_assert_eq(my_str_isprintable("\x7F"), 0);
}
