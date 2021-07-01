/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_revstr function
*/

#include <criterion/criterion.h>
#include <string.h>
#include "libmy/ascii.h"

Test(my_revstr, null_string)
{
    my_revstr(NULL);
}

Test(my_revstr, normal_string)
{
    char str[15] = "This is a test";
    char *expected = "tset a si sihT";

    my_revstr(str);
    cr_assert(strcmp(str, expected) == 0, "expected \"%s\", got \"%s\"",
    expected, str);
}
