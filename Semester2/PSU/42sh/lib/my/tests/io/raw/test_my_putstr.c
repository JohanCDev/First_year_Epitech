/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_putstr function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "libmy/io.h"

static void redirect_all_output(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_putstr, main, .init=redirect_all_output)
{
    my_putstr("This is a test!");
    cr_assert_stdout_eq_str("This is a test!", "");
}

Test(my_putstr_fd, main_stdout, .init=redirect_all_output)
{
    my_putstr_fd(1, "This is a test!");
    cr_assert_stdout_eq_str("This is a test!", "");
}

Test(my_putstr_fd, main_stderr, .init=redirect_all_output)
{
    my_putstr_fd(2, "This is a test!");
    cr_assert_stderr_eq_str("This is a test!", "");
}
