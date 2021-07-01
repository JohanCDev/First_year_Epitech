/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_str_to_word_array function
*/

#include <criterion/criterion.h>
#include "libmy/ascii.h"

static int str_array_eq(char **a1, char **a2)
{
    if (a1 == a2)
        return 1;
    if (!a1 || !a2)
        return 0;
    while (*a1 && *a2 && my_strcmp(*a1, *a2) == 0) {
        ++a1;
        ++a2;
    }
    return *a1 == *a2;
}

Test(my_str_to_word_array, null_string)
{
    cr_assert(str_array_eq(my_str_to_word_array(NULL), NULL));
}

Test(my_str_to_word_array, empty_string)
{
    char *expected[] = {NULL};

    cr_assert(str_array_eq(my_str_to_word_array(""), expected));
}

Test(my_str_to_word_array, one_word)
{
    char *expected[] = {"yeet", NULL};

    cr_assert(str_array_eq(my_str_to_word_array("yeet"), expected));
}

Test(my_str_to_word_array, one_word_with_padding)
{
    char *expected[] = {"%", ",yeet0.:?", NULL};

    cr_assert(str_array_eq(my_str_to_word_array(" % ,yeet0.:?  "), expected));
}

Test(my_str_to_word_array, multi_words)
{
    char *expected[] = {"This", "is", "a", "test", NULL};

    cr_assert(str_array_eq(my_str_to_word_array("This is a test"), expected));
}

Test(my_str_to_word_array, multi_words_with_padding)
{
    char *expected[] = {"->", "This,", "is", "a", "test!", NULL};

    cr_assert(
        str_array_eq(my_str_to_word_array("-> This,\n is a test!"), expected));
}
