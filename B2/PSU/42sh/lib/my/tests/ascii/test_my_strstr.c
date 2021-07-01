/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_strstr function
*/

#include <criterion/criterion.h>
#include <string.h>
#include "libmy/ascii.h"

Test(my_strstr, null_strings)
{
    cr_assert_eq(NULL, my_strstr(NULL, NULL));
}

Test(my_strstr, null_str)
{
    cr_assert_eq(NULL, my_strstr(NULL, "test"));
}

Test(my_strstr, null_needle)
{
    cr_assert_eq(NULL, my_strstr("I am a haystack", NULL));
}

Test(my_strstr, empty_needle)
{
    char *haystack = "haystack";

    cr_assert_eq(my_strstr(haystack, ""), haystack + 8);
}

Test(my_strstr, normal_string)
{
    char *found = my_strstr("I am a haystack", "stack");
    char *expected = "stack";

    cr_assert_str_eq(expected, found, "expected \"%s\", got \"%s\"", expected,
    found);
}

Test(my_strstr, no_needle_in_haystack)
{
    char *found = my_strstr("I am a haystack", "steak");

    cr_assert_eq(NULL, found, "got \"%s\"", found);
}

Test(my_strstr, incomplete_needle_in_haystack)
{
    char *found = my_strstr("I am hay", "haystack");

    cr_assert_eq(NULL, found, "got \"%s\"", found);
}

Test(my_strstr, needle_in_middle_of_haystack)
{
    char *found = my_strstr("Hey hay hey!", "hay");
    char *expected = "hay hey!";

    cr_assert_str_eq(expected, found, "expected \"%s\", got \"%s\"", expected,
    found);
}
