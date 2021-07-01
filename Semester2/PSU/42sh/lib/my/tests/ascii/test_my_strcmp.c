/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_strcmp function
*/

#include <criterion/criterion.h>
#include <string.h>
#include "libmy/ascii.h"

Test(my_strcmp, null_strings)
{
    cr_assert_eq(0, my_strcmp(NULL, NULL));
    cr_assert_lt(my_strcmp(NULL, "some text"), 0);
    cr_assert_gt(my_strcmp("lorem ipsum", NULL), 0);
}

Test(my_strcmp, equal_strings)
{
    cr_assert_eq(0, my_strcmp("TEST", "TEST"));
}

Test(my_strcmp, same_length_but_different)
{
    cr_assert_gt(my_strcmp("yes", "no."), 0);
}

Test(my_strcmp, string_1_shorter_than_string_2)
{
    cr_assert_lt(my_strcmp("This is a test", "iconic."), 0);
}

Test(my_strcmp, string_2_shorter_than_string_1)
{
    cr_assert_gt(my_strcmp("oops!", "Whooooosh"), 0);
}

Test(my_strcmp, string_starts_the_same_way)
{
    cr_assert_gt(my_strcmp("This is cool!", "This is OK..."), 0);
}

Test(my_strcmp, same_strings_but_1_is_cut_off)
{
    cr_assert_lt(my_strcmp("This is a te", "This is a test"), 0);
}

Test(my_strcmp, same_strings_but_2_is_cut_off)
{
    cr_assert_gt(my_strcmp("This is a test", "This is a tes"), 0);
}
