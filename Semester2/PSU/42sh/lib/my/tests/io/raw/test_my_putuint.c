/*
** EPITECH PROJECT, 2020
** Day06 unit tests
** File description:
** Tests my_putuint
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <limits.h>
#include "libmy/io.h"

static void redirect_all_output(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_putuint, zero, .init=redirect_all_output)
{
    cr_assert_eq(my_putuint(0), 0);
    cr_assert_stdout_eq_str("0", "");
}

Test(my_putuint, one, .init=redirect_all_output)
{
    cr_assert_eq(my_putuint(1), 0);
    cr_assert_stdout_eq_str("1", "");
}

Test(my_putuint_fd, two_thousand_seventy_four, .init=redirect_all_output)
{
    cr_assert_eq(my_putuint_fd(2, 2074), 0);
    cr_assert_stderr_eq_str("2074", "");
}

Test(my_putuint_fd, uint_max, .init=redirect_all_output)
{
    cr_assert_eq(my_putuint_fd(1, UINT_MAX), 0);
    cr_assert_stdout_eq_str("4294967295", "");
}
