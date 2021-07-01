/*
** EPITECH PROJECT, 2021
** LibMy unit tests
** File description:
** Tests the character conversion functions
*/

#include <criterion/criterion.h>
#include <criterion/logging.h>
#include "libmy/ascii/character.h"

Test(my_toupper, base)
{
    cr_assert_eq(my_toupper('A'), 'A');
    cr_assert_eq(my_toupper('?'), '?');
    cr_assert_eq(my_toupper('f'), 'F');
}

Test(my_tolower, base)
{
    cr_assert_eq(my_tolower('A'), 'a');
    cr_assert_eq(my_tolower('?'), '?');
    cr_assert_eq(my_tolower('f'), 'f');
}
