/*
** EPITECH PROJECT, 2020
** Day06 unit tests
** File description:
** Tests my_put_nbr
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

Test(my_put_nbr, zero, .init=redirect_all_output)
{
    cr_assert_eq(my_put_nbr(0), 0);
    cr_assert_stdout_eq_str("0", "");
}

Test(my_put_nbr, one, .init=redirect_all_output)
{
    cr_assert_eq(my_put_nbr(1), 0);
    cr_assert_stdout_eq_str("1", "");
}

Test(my_put_nbr_fd, minus_four, .init=redirect_all_output)
{
    cr_assert_eq(my_put_nbr_fd(2, -4), 0);
    cr_assert_stderr_eq_str("-4", "");
}

Test(my_put_nbr, minus_one_hundred_and_forty_two, .init=redirect_all_output)
{
    cr_assert_eq(my_put_nbr(-142), 0);
    cr_assert_stdout_eq_str("-142", "");
}

Test(my_put_nbr, two_thousand_seventy_four, .init=redirect_all_output)
{
    cr_assert_eq(my_put_nbr(2074), 0);
    cr_assert_stdout_eq_str("2074", "");
}

Test(my_put_nbr, int_max, .init=redirect_all_output)
{
    cr_assert_eq(my_put_nbr(INT_MAX), 0);
    cr_assert_stdout_eq_str("2147483647", "");
}

Test(my_put_nbr_fd, int_min, .init=redirect_all_output)
{
    cr_assert_eq(my_put_nbr_fd(2, INT_MIN), 0);
    cr_assert_stderr_eq_str("-2147483648", "");
}
