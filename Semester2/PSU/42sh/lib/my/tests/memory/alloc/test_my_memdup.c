/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_memcmp function
*/

#include <criterion/criterion.h>

#include "libmy/memory/memory.h"

Test(my_memcmp, equal_strings)
{
    cr_assert_eq(0, my_memcmp("TEST", "TEST", 5));
}

Test(my_memcmp, same_length_but_different)
{
    cr_assert_gt(my_memcmp("yes", "no.", 4), 0);
}

Test(my_memcmp, string_1_shorter_than_string_2)
{
    cr_assert_lt(my_memcmp("This is a test", "iconic.", 8), 0);
}

Test(my_memcmp, string_2_shorter_than_string_1)
{
    cr_assert_gt(my_memcmp("oops!", "Whooooosh", 6), 0);
}

Test(my_memcmp, string_starts_the_same_way)
{
    cr_assert_gt(my_memcmp("This is cool!", "This is OK...", 14), 0);
}

Test(my_memcmp, same_strings_but_1_is_cut_off)
{
    cr_assert_lt(my_memcmp("This is a te", "This is a test", 13), 0);
}

Test(my_memcmp, same_strings_but_2_is_cut_off)
{
    cr_assert_gt(my_memcmp("This is a test", "This is a tes", 14), 0);
}
