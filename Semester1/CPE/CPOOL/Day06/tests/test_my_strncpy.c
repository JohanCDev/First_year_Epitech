/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** test
*/

#include <criterion/criterion.h>

char *my_strncpy(char *dest, char const *src, int n);

Test(my_strncpy, copy_five_characters_in_empty_array)
{
    char dest[6] = {0};

    my_strncpy(dest, "HelloWorld", 5);
    cr_assert_str_eq(dest, "Hello");
}

Test(my_strncpy, copy_zero_characters_in_empty_string)
{
    char dest[5] = {0};

    my_strncpy(dest, "HelloWorld", 0);
    cr_assert_str_eq(dest, "");
}

Test(my_strncpy, copy_four_characters_in_empty_string)
{
    char dest[5] = {0};

    my_strncpy(dest, "HelloWorld", 4);
    cr_assert_str_eq(dest, "Hell");
}

Test(my_strncpy, copy_four_characters_in_empty_string1)
{
    char dest[5] = {0};

    my_strncpy(dest, "Hello", 0);
    cr_assert_str_eq(dest, 0);
}

Test(my_strncpy, copy_four_characters_in_empty_string2)
{
    char dest[5] = {0};

    my_strncpy(dest, "HelloWorld", 1);
    cr_assert_str_eq(dest, "H");
}
