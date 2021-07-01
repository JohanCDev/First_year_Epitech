/*
** EPITECH PROJECT, 2020
** test_my_revstr
** File description:
** test reverse a string
*/

#include <criterion/criterion.h>

char *my_revstr(char *str);

Test(my_revstr, rev_string_in_empty_array)
{
    char str[] = "Hello World!";
    
    my_revstr(str);
    cr_assert_str_eq(str, "!dlroW olleH");
}

Test(my_revstr, rev_string_in_empty_array1)
{
    char str[] = "";

    my_revstr(str);
    cr_assert_str_eq(str, "");
}

Test(my_revstr, rev_string_in_empty_array2)
{
    char str[] = "1234567890";

    my_revstr(str);
    cr_assert_str_eq(str, "0987654321");
}

Test(my_revstr, rev_string_in_empty_array)
{
    char str[] = "HelloWorld!";

    my_revstr(str);
    cr_assert_str_eq(str, "!dlroWolleH");
}
