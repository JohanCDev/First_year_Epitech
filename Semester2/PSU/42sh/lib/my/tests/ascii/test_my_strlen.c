/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_strlen function
*/

#include <criterion/criterion.h>
#include "libmy/ascii.h"

Test(my_strlen, empty_string)
{
    cr_assert_eq(my_strlen(""), 0);
}

Test(my_strlen, regular_string)
{
    cr_assert_eq(my_strlen("test"), 4);
}

Test(my_strlen, regular_nul_bytes)
{
    cr_assert_eq(my_strlen("test\0\0\0"), 4);
}
