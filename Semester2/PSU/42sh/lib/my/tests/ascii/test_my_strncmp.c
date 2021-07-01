/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_strncmp function
*/

#include <criterion/criterion.h>
#include <string.h>
#include "libmy/ascii.h"

Test(my_strncmp, null_strings)
{
    cr_assert_eq(my_strncmp(NULL, NULL, 42), 0);
    cr_assert_eq(my_strncmp(NULL, "some text", 4), 0);
    cr_assert_eq(my_strncmp("lorem ipsum", NULL, 11), 0);
}

Test(my_strncmp, zero_n)
{
    cr_assert_eq(my_strncmp("blah blah", "abcdef", 0), 0);
}

Test(my_strncmp, equal_strings)
{
    cr_assert_eq(my_strncmp("TEST", "TEST", 5), 0);
    cr_assert_eq(my_strncmp("TEST", "TEST", 10), 0);
}

Test(my_strncmp, equal_strings_cut_off)
{
    cr_assert_eq(my_strncmp("TEST", "TEST", 2), 0);
}

Test(my_strncmp, same_length_but_different)
{
    cr_assert_gt(my_strncmp("yes", "no.", 4), 0);
}

Test(my_strncmp, same_length_but_different_cut_off)
{
    cr_assert_gt(my_strncmp("yes", "no.", 1), 0);
}

Test(my_strncmp, string_1_shorter_than_string_2)
{
    cr_assert_lt(my_strncmp("This is a test", "iconic.", 20), 0);
}

Test(my_strncmp, string_2_shorter_than_string_1)
{
    cr_assert_gt(my_strncmp("oops!", "Whooooosh", 20), 0);
}

Test(my_strncmp, string_starts_the_same_way)
{
    cr_assert_gt(my_strncmp("This is cool!", "This is OK...", 14), 0);
}

Test(my_strncmp, string_starts_the_same_way_cut_off)
{
    cr_assert_eq(my_strncmp("This is cool!", "This is OK...", 4), 0);
}

Test(my_strncmp, same_strings_but_1_is_cut_off)
{
    cr_assert_lt(my_strncmp("This is a te", "This is a test", 14), 0);
}

Test(my_strncmp, same_strings_but_2_is_cut_off)
{
    cr_assert_gt(my_strncmp("This is a test", "This is a tes", 14), 0);
}

Test(my_strncmp, gone_too_soon)
{
    cr_assert_eq(my_strncmp("YB", "YA", 1), 0);
}
