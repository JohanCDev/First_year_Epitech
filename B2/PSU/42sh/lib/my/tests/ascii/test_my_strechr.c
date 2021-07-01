/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_strechr function
*/

#include <criterion/criterion.h>
#include "libmy/ascii.h"

Test(my_strechr, null_string)
{
    cr_assert_eq(my_strechr(NULL, '?'), NULL);
}

Test(my_strechr, empty_string)
{
    char *str = "";

    cr_assert_eq(my_strechr(str, '?'), str);
    cr_assert_eq(my_strechr(str, '\0'), str);
}

Test(my_strechr, regular_string)
{
    char *str = "This is a test, abcd";

    cr_assert_eq(my_strechr(str, 'T'), str);
    cr_assert_eq(my_strechr(str, 'i'), str + 2);
    cr_assert_eq(my_strechr(str, 'a'), str + 8);
    cr_assert_eq(my_strechr(str, 'd'), str + 19);
    cr_assert_eq(my_strechr(str, '\0'), str + 20);
}
