/*
** EPITECH PROJECT, 2021
** LibMy unit tests
** File description:
** Tests the my_memswap function
*/

#include <criterion/criterion.h>
#include "libmy/memory/memory.h"

Test(my_memswap, swap_chars_inline)
{
    char a = 'X';
    char b = 'Y';

    my_memswap(&a, &b, sizeof(char));
    cr_assert_eq('X', b);
    cr_assert_eq('Y', a);
}

Test(my_memswap, swap_strings_inline)
{
    char *a = "String X";
    char *b = "String Y";

    my_memswap(&a, &b, sizeof(char *));
    cr_assert_str_eq("String X", b);
    cr_assert_str_eq("String Y", a);
}

Test(my_memswap, swap_chars)
{
    char a = 'X';
    char b = 'Y';
    void (*func)(void *restrict, void *restrict, size_t) = &my_memswap;

    (*func)(&a, &b, sizeof(char));
    cr_assert_eq('X', b);
    cr_assert_eq('Y', a);
}

Test(my_memswap, swap_strings)
{
    char *a = "String X";
    char *b = "String Y";
    void (*func)(void *restrict, void *restrict, size_t) = &my_memswap;

    (*func)(&a, &b, sizeof(char *));
    cr_assert_str_eq("String X", b);
    cr_assert_str_eq("String Y", a);
}
