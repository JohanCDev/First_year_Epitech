/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_dprintf function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "libmy/printf.h"

Test(my_dprintf, print_to_stdout, .init = cr_redirect_stdout)
{
    cr_assert_eq(my_dprintf(1, "test: %2$.2s, %1$p", NULL, "ok/NOT ok"), 15);
    cr_assert_stdout_eq_str("test: ok, (nil)", "");
}

Test(my_dprintf, print_to_stderr, .init = cr_redirect_stderr)
{
    cr_assert_eq(my_dprintf(2, "test: %2$.2s, %1$p", NULL, "ok/NOT ok"), 15);
    cr_assert_stderr_eq_str("test: ok, (nil)", "");
}
