/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_fputs_endl, my_puts_endl & my_eputs_endl
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "libmy/io.h"

static void redirect_all_output(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_fputs_endl, closed_stream)
{
    unsigned char buf[256];
    my_iostream_t stream;

    my_finit_output_fd(1, &stream);
    my_fset_buffer(buf, 256, NULL, &stream);
    stream.unix_stream.is_eof = 1;
    cr_assert_neq(my_fputs_endl("This is a test", &stream), 0);
}

Test(my_fputs_endl, cant_write_newline)
{
    unsigned char buf[8] = { 0 };
    my_iostream_t stream;

    my_finit_output_memory(buf, 4, &stream);
    cr_assert_neq(my_fputs_endl("test", &stream), 0);
    cr_assert_str_eq((char *)buf, "test");
}

Test(my_fputs_endl, normal, .init = redirect_all_output)
{
    unsigned char buf[256];
    my_iostream_t stream;

    my_finit_output_fd(1, &stream);
    my_fset_buffer(buf, 256, NULL, &stream);
    cr_assert_eq(my_fputs_endl("This is a test", &stream), 0);
    cr_assert_eq(my_fflush(&stream), 0);
    cr_assert_stdout_eq_str("This is a test\n", "");
    my_ffree(&stream);
}

Test(my_puts_endl, base, .init = redirect_all_output)
{
    unsigned char buf[256];

    my_init_stdout(buf, 256, NULL);
    cr_assert_eq(my_puts_endl("Zbeub zbeub"), 0);
    cr_assert_eq(my_flush_stdout(), 0);
    cr_assert_stdout_eq_str("Zbeub zbeub\n", "");
    my_free_stdout();
}

Test(my_eputs_endl, base, .init = redirect_all_output)
{
    unsigned char buf[256];

    my_init_stderr(buf, 256, NULL);
    cr_assert_eq(my_eputs_endl("Help me please!"), 0);
    cr_assert_eq(my_flush_stderr(), 0);
    cr_assert_stderr_eq_str("Help me please!\n", "");
    my_free_stderr();
}
