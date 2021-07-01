/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_strupcase function
*/

#include <criterion/criterion.h>
#include <string.h>
#include "libmy/ascii.h"

Test(my_strupcase, null_string)
{
    cr_assert_eq(NULL, my_strupcase(NULL));
}

Test(my_strupcase, alpha_string)
{
    char str[] = "This is a Test";

    cr_assert_str_eq(my_strupcase(str), "THIS IS A TEST");
}

Test(my_strupcase, numalpha_string)
{
    char str[] = "1 Apple, 2 Apples";

    cr_assert_str_eq(my_strupcase(str), "1 APPLE, 2 APPLES");
}

Test(my_strupcase, nonalpha_string)
{
    char str[] = "#/:.,?";

    cr_assert_str_eq(my_strupcase(str), "#/:.,?");
}

Test(my_strupcase, char_below_lower_a)
{
    char str[] = "^";

    cr_assert_str_eq(my_strupcase(str), "^");
}

Test(my_strupcase, char_above_lower_z)
{
    char str[] = "~";

    cr_assert_str_eq(my_strupcase(str), "~");
}
