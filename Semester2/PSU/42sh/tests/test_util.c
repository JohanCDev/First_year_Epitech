/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Tests utility functions
*/

#include <criterion/criterion.h>
#include "util.h"

Test(sh_count_words, no_words)
{
    cr_assert_eq(sh_count_words(NULL), 0);
    cr_assert_eq(sh_count_words(""), 0);
    cr_assert_eq(sh_count_words("    "), 0);
    cr_assert_eq(sh_count_words("\f\n\r\t\v"), 0);
}

Test(sh_count_words, one_word)
{
    cr_assert_eq(sh_count_words("test"), 1);
    cr_assert_eq(sh_count_words("  test  "), 1);
    cr_assert_eq(sh_count_words("\f\n\ryeet\t\v"), 1);
}

Test(sh_count_words, multiple_words)
{
    cr_assert_eq(sh_count_words("This is a test"), 4);
    cr_assert_eq(sh_count_words("  lorem ipsum  dolor sit amet"), 5);
    cr_assert_eq(sh_count_words("consectetur $VAR elit.\n"), 3);
}
