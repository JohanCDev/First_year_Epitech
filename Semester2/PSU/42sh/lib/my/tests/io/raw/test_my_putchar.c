/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_putchar function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "libmy/io.h"

static void redirect_all_output(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_putchar, main, .init=redirect_all_output)
{
    my_putchar('X');
    cr_assert_stdout_eq_str("X", "");
}

Test(my_putchar_fd, main_stdout, .init=redirect_all_output)
{
    my_putchar_fd(1, 'X');
    cr_assert_stdout_eq_str("X", "");
}

Test(my_putchar_fd, main_stderr, .init=redirect_all_output)
{
    my_putchar_fd(2, 'X');
    cr_assert_stderr_eq_str("X", "");
}
