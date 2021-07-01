/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_strlowcase function
*/

#include <criterion/criterion.h>
#include <string.h>
#include "libmy/ascii.h"

Test(my_strlowcase, null_string)
{
    cr_assert_eq(NULL, my_strlowcase(NULL));
}

Test(my_strlowcase, alpha_string)
{
    char str[] = "This is a Test";

    my_strlowcase(str);
    cr_assert_str_eq(str, "this is a test");
}

Test(my_strlowcase, numalpha_string)
{
    char str[] = "1 Apple, 2 Apples";

    my_strlowcase(str);
    cr_assert_str_eq(str, "1 apple, 2 apples");
}

Test(my_strlowcase, nonalpha_string)
{
    char str[] = "#/:.,?";

    my_strlowcase(str);
    cr_assert_str_eq(str, "#/:.,?");
}
