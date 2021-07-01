/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_strstr_n_n function
*/

#include <criterion/criterion.h>
#include "libmy/ascii.h"

Test(my_strstr_n, null_args)
{
    cr_assert_eq(NULL, my_strstr_n(NULL, 12, NULL, 78));
    cr_assert_eq(NULL, my_strstr_n(NULL, -1, "test", -1));
    cr_assert_eq(NULL, my_strstr_n("I am a haystack", -1, NULL, -1));
}

Test(my_strstr_n, zero_to_find_len)
{
    cr_assert_eq(NULL, my_strstr_n("test", 4, "s", 0));
}

Test(my_strstr_n, normal_string)
{
    char *found = my_strstr_n("I am a haystack", -1, "stack", -1);
    char *expected = "stack";

    cr_assert_str_eq(expected, found, "expected \"%s\", got \"%s\"", expected,
    found);
}

Test(my_strstr_n, no_needle_in_haystack)
{
    char *found = my_strstr_n("I am a haystack", -1, "steak", -1);

    cr_assert_eq(NULL, found, "got \"%s\"", found);
}

Test(my_strstr_n, incomplete_needle_in_haystack)
{
    char *found = my_strstr_n("I am hay", -1, "haystack", -1);

    cr_assert_eq(NULL, found, "got \"%s\"", found);
}

Test(my_strstr_n, needle_in_middle_of_haystack)
{
    char *found = my_strstr_n("Hey hay hey!", -1, "hay", -1);
    char *expected = "hay hey!";

    cr_assert_str_eq(expected, found, "expected \"%s\", got \"%s\"", expected,
    found);
}

Test(my_strstr_n, half_needle_in_haystack)
{
    char *found = my_strstr_n("I am bread", -1, "bready", 5);
    char *expected = "bread";

    cr_assert_str_eq(expected, found, "expected \"%s\", got \"%s\"", expected,
    found);
}

Test(my_strstr_n, cannot_find_needle_past_haystack)
{
    char *found = my_strstr_n("\"This is a string\" hi!", 18, " hi!", -1);

    cr_assert_eq(NULL, found, "got \"%s\"", found);
}
