/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_stricmp function
*/

#include <criterion/criterion.h>
#include <string.h>
#include "libmy/ascii.h"

Test(my_stricmp, null_strings)
{
    cr_assert_eq(0, my_stricmp(NULL, NULL));
    cr_assert_lt(my_stricmp(NULL, "some text"), 0);
    cr_assert_gt(my_stricmp("lorem ipsum", NULL), 0);
}

Test(my_stricmp, equal_strings)
{
    cr_assert_eq(0, my_stricmp("TEST", "TEST"));
    cr_assert_eq(0, my_stricmp("TesT", "test"));
    cr_assert_eq(0, my_stricmp("TESt", "TEST"));
}

Test(my_stricmp, same_length_but_different)
{
    cr_assert_gt(my_stricmp("yes", "no."), 0);
}

Test(my_stricmp, string_1_shorter_than_string_2)
{
    cr_assert_gt(my_stricmp("This is a test", "iconic."), 0);
}

Test(my_stricmp, string_2_shorter_than_string_1)
{
    cr_assert_lt(my_stricmp("oops!", "Whooooosh"), 0);
}

Test(my_stricmp, string_starts_the_same_way)
{
    cr_assert_lt(my_stricmp("This is cool!", "This is OK..."), 0);
}

Test(my_stricmp, same_strings_but_1_is_cut_off)
{
    cr_assert_lt(my_stricmp("This is a te", "This is a test"), 0);
}

Test(my_stricmp, same_strings_but_2_is_cut_off)
{
    cr_assert_gt(my_stricmp("This is a test", "This is a tes"), 0);
}
