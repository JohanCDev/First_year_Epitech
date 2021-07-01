/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_strchr function
*/

#include <criterion/criterion.h>
#include "libmy/ascii.h"

Test(my_strchr, null_string)
{
    cr_assert_eq(my_strchr(NULL, '?'), NULL);
}

Test(my_strchr, empty_string)
{
    char *str = "";

    cr_assert_eq(my_strchr(str, '?'), NULL);
    cr_assert_eq(my_strchr(str, '\0'), str);
}

Test(my_strchr, regular_string)
{
    char *str = "This is a test, abcd";

    cr_assert_eq(my_strchr(str, 'T'), str);
    cr_assert_eq(my_strchr(str, 'i'), str + 2);
    cr_assert_eq(my_strchr(str, 'a'), str + 8);
    cr_assert_eq(my_strchr(str, 'd'), str + 19);
    cr_assert_eq(my_strchr(str, '\0'), str + 20);
}
