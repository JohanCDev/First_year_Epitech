/*
** EPITECH PROJECT, 2020
** test_my_str_is_alpha
** File description:
** test my_is_alpha
*/

#include <criterion/criterion.h>

int my_str_isalpha(char const *str);

Test(my_str_isalpha, is_a_string_only_alpha)
{
    cr_assert_eq(my_str_isalpha("a"), 1);
}

Test(my_str_isalpha, is_a_string_only_alpha1)
{
    cr_assert_eq(my_str_isalpha(""), 1);
}

Test(my_str_isalpha, is_a_string_only_alpha2)
{
    cr_assert_eq(my_str_isalpha("1"), 0);
}

Test(my_str_isalpha, is_a_string_only_alpha3)
{
    cr_assert_eq(my_str_isalpha("A"), 1);
}

Test(my_str_isalpha, is_a_string_only_alpha4)
{
    cr_assert_eq(my_str_isalpha("{"), 0);
}


