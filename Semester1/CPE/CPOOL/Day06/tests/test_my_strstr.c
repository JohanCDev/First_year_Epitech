/*
** EPITECH PROJECT, 2020
** test_my_strstr
** File description:
** test strstr
*/

#include <criterion/criterion.h>

char *my_strstr(char *str, char const *to_find);

Test(my_strstr, search_string_in_other_string)
{
    char str[] = "Hello World!";
    char to_find[] = "lo";
    
    cr_assert_str_eq(my_strstr(str, to_find), "lo World!");
}

Test(my_strstr, search_string_in_other_string1)
{
    char str[] = "Hello World!";
    char to_find[] = "po";

    cr_assert_eq(my_strstr(str, to_find), 0);
}

Test(my_strstr, search_string_in_other_string2)
{
    char str[] = "Hello World!";
    char to_find[] = "";

    cr_assert_str_eq(my_strstr(str, to_find), "Hello World!");
}

Test(my_strstr, search_string_in_other_string3)
{
    char str[] = "";
    char to_find[] = "Hello World!";

    cr_assert_eq(my_strstr(str, to_find), 0);
}

Test(my_strstr, search_string_in_other_string4)
{
    char str[] = "";
    char to_find[] = "";

    cr_assert_eq(my_strstr(str, to_find), 0);
}

Test(my_strstr, search_string_in_other_string5)
{
    char str[] = "a";
    char to_find[] = "b";

    cr_assert_eq(my_strstr(str, to_find), 0);
}

Test(my_strstr, search_string_in_other_string6)
{
    char str[] = "b";
    char to_find[] = "a";

    cr_assert_eq(my_strstr(str, to_find), 0);
}
