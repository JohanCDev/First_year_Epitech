/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_sprintf function
*/

#include <criterion/criterion.h>
#include "libmy/printf.h"

Test(my_sprintf, null_strings)
{
    cr_assert_eq(my_sprintf(NULL, ""), 0);
    cr_assert_eq(my_sprintf(NULL, "test"), 4);
    cr_assert_eq(my_sprintf(NULL, "%d is non-zero: %r\n", 42), 21);
}

Test(my_sprintf, normal)
{
    char buf[64];

    cr_assert_eq(my_sprintf(buf, "This"), 4);
    cr_assert_eq(my_sprintf(buf + 4, " %2$s %1$s ", "a", "is"), 6);
    cr_assert_eq(my_sprintf(buf + 10, "%R", 0), 5);
    cr_assert_str_eq(buf, "This is a FALSE");
}
