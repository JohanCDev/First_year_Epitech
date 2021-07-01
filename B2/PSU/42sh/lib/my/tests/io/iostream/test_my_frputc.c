/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_frputc, my_rputc and my_erputc functions
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include "libmy/io.h"

Test(my_frputc, error_in_stream)
{
    char buf[2];
    my_iostream_t stream;

    my_finit_output_memory(buf, 2, &stream);
    cr_assert_neq(my_frputc(' ', 10, &stream), 0);
}

Test(my_frputc, normal)
{
    char buf[6];
    my_iostream_t stream;

    my_finit_output_memory(buf, 5, &stream);
    cr_assert_eq(my_frputc(' ', 5, &stream), 0);
    buf[5] = '\0';
    cr_assert_str_eq(buf, "     ");
}

Test(my_rputc, normal, .init = cr_redirect_stdout)
{
    my_init_stdout(malloc(16), 16, &free);
    cr_assert_eq(my_rputc('.', 3), 0);
    my_flush_stdout();
    cr_assert_stdout_eq_str("...", "");
    my_free_stdout();
}

Test(my_erputc, normal, .init = cr_redirect_stderr)
{
    my_init_stderr(malloc(16), 16, &free);
    cr_assert_eq(my_erputc('!', 3), 0);
    my_flush_stderr();
    cr_assert_stderr_eq_str("!!!", "");
    my_free_stderr();
}
