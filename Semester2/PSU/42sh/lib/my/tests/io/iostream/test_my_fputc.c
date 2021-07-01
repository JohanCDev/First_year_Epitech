/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_fputc, my_putc & my_eputc
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "libmy/io.h"

static void redirect_all_output(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_fputc, base, .init = redirect_all_output)
{
    unsigned char buf[256];
    my_iostream_t stream;

    my_finit_output_fd(1, &stream);
    my_fset_buffer(buf, 256, NULL, &stream);
    cr_assert_eq(my_fputc('A', &stream), 0);
    cr_assert_eq(my_fputc('B', &stream), 0);
    cr_assert_eq(my_fflush(&stream), 0);
    cr_assert_stdout_eq_str("AB", "");
    my_ffree(&stream);
}

Test(my_putc, base, .init = redirect_all_output)
{
    unsigned char buf[256];

    my_init_stdout(buf, 256, NULL);
    cr_assert_eq(my_putc('C'), 0);
    cr_assert_eq(my_putc('D'), 0);
    cr_assert_eq(my_flush_stdout(), 0);
    cr_assert_stdout_eq_str("CD", "");
    my_free_stdout();
}

Test(my_eputc, base, .init = redirect_all_output)
{
    unsigned char buf[256];

    my_init_stderr(buf, 256, NULL);
    cr_assert_eq(my_eputc('E'), 0);
    cr_assert_eq(my_eputc('F'), 0);
    cr_assert_eq(my_flush_stderr(), 0);
    cr_assert_stderr_eq_str("EF", "");
    my_free_stderr();
}
