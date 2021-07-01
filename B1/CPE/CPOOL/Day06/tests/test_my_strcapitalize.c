/*
** EPITECH PROJECT, 2020
** test_my_str_capitalize
** File description:
** test capitalize
*/

#include <criterion/criterion.h>

char *my_strcapitalize(char *str);

Test(my_strcapitalize, capitalize_a_string)
{
    char str[] = "hey, how are you? 42WORds forty-two; fifty+one";

    cr_assert_str_eq(my_strcapitalize(str),
                     "Hey, How Are You? 42words Forty-Two; Fifty+One");
}

Test(my_strcapitalize, capitalize_a_string1)
{
    char str[] = "Hello, IM joHan. lOL";

    cr_assert_str_eq(my_strcapitalize(str), "Hello, Im Johan. Lol");
}

Test(my_strcapitalize, capitalize_a_string2)
{
    char str[] = "+a";

    cr_assert_str_eq(my_strcapitalize(str), "+A");
}

Test(my_strcapitalize, capitalize_a_string3)
{
    char str[] = "-a";

    cr_assert_str_eq(my_strcapitalize(str), "-A");
}
