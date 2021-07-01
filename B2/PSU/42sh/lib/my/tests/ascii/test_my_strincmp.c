/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_strincmp function
*/

#include <criterion/criterion.h>
#include <string.h>
#include "libmy/ascii.h"

Test(my_strincmp, null_strings)
{
    cr_assert_eq(my_strincmp(NULL, NULL, 42), 0);
    cr_assert_eq(my_strincmp(NULL, "some text", 4), 0);
    cr_assert_eq(my_strincmp("lorem ipsum", NULL, 11), 0);
}

Test(my_strincmp, zero_n)
{
    cr_assert_eq(my_strincmp("blah blah", "abcdef", 0), 0);
}

Test(my_strincmp, equal_strings)
{
    cr_assert_eq(my_strincmp("TEST", "TEST", 5), 0);
    cr_assert_eq(my_strincmp("TEST", "TEST", 10), 0);
    cr_assert_eq(my_strincmp("test", "TEST", 5), 0);
    cr_assert_eq(my_strincmp("test", "TeSt", 10), 0);
}

Test(my_strincmp, equal_strings_cut_off)
{
    cr_assert_eq(my_strincmp("TEST", "TeST", 2), 0);
    cr_assert_eq(my_strincmp("TeST", "TeST", 2), 0);
}

Test(my_strincmp, same_length_but_different)
{
    cr_assert_gt(my_strincmp("yes", "no.", 4), 0);
}

Test(my_strincmp, same_length_but_different_cut_off)
{
    cr_assert_gt(my_strincmp("yes", "no.", 1), 0);
}

Test(my_strincmp, string_1_shorter_than_string_2)
{
    cr_assert_gt(my_strincmp("This is a test", "iconic.", 20), 0);
}

Test(my_strincmp, string_2_shorter_than_string_1)
{
    cr_assert_lt(my_strincmp("oops!", "Whooooosh", 20), 0);
}

Test(my_strincmp, string_starts_the_same_way)
{
    cr_assert_lt(my_strincmp("This is cool!", "This is OK...", 14), 0);
}

Test(my_strincmp, string_starts_the_same_way_cut_off)
{
    cr_assert_eq(my_strincmp("This is cool!", "This is OK...", 4), 0);
}

Test(my_strincmp, same_strings_but_1_is_cut_off)
{
    cr_assert_lt(my_strincmp("This is a te", "This is a test", 14), 0);
}

Test(my_strincmp, same_strings_but_2_is_cut_off)
{
    cr_assert_gt(my_strincmp("This is a test", "This is a tes", 14), 0);
}

Test(my_strincmp, gone_too_soon)
{
    cr_assert_eq(my_strincmp("YB", "YA", 1), 0);
}
