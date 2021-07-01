/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_showstr function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "libmy/io.h"

static void redirect_all_output(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_showstr, null_string, .init=redirect_all_output)
{
    cr_assert_eq(my_showstr(NULL), -1);
}

Test(my_showstr, empty_string, .init=redirect_all_output)
{
    cr_assert_eq(my_showstr(""), 0);
}

Test(my_showstr, simple_string, .init=redirect_all_output)
{
    cr_assert_eq(my_showstr("test"), 0);
    cr_assert_stdout_eq_str("test", "");
}

Test(my_showstr, two_lines, .init=redirect_all_output)
{
    cr_assert_eq(my_showstr("line one\nline two\n"), 0);
    cr_assert_stdout_eq_str("line one\\0aline two\\0a", "");
}

Test(my_showstr, two_lines_with_spaces, .init=redirect_all_output)
{
    cr_assert_eq(my_showstr("I like \n ponies!"), 0);
    cr_assert_stdout_eq_str("I like \\0a ponies!", "");
}

Test(my_showstr, full_nonprintables, .init=redirect_all_output)
{
    cr_assert_eq(my_showstr("\x1\x2\x3\x6\x7\x8\x9\x1f\x7f"), 0);
    cr_assert_stdout_eq_str("\\01\\02\\03\\06\\07\\08\\09\\1f\\7f", "");
}
