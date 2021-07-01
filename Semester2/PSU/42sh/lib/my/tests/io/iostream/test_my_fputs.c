/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_fputs functions
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include "libmy/io.h"

static void setup(void)
{
    my_init_stdout(malloc(256), 256, &free);
    my_init_stderr(malloc(256), 256, &free);
    cr_redirect_stdout();
    cr_redirect_stderr();
}

static void finish(void)
{
    my_free_stdout();
    my_free_stderr();
}

Test(my_fputs, input_stream)
{
    my_iostream_t stream;

    my_finit_input_memory("some input", 10, &stream);
    cr_assert_neq(my_fputs("test\n", &stream), 0);
}

Test(my_fputs, null_string, .init = setup, .fini = finish)
{
    cr_assert_eq(my_fputs(NULL, MY_STDOUT), 0);
    cr_assert_eq(my_flush_stdout(), 0);
}

Test(my_fputs, empty_string, .init = setup, .fini = finish)
{
    cr_assert_eq(my_fputs("", MY_STDOUT), 0);
    cr_assert_eq(my_flush_stdout(), 0);
}

Test(my_fputs, unix_stream_filled_string, .init = setup, .fini = finish)
{
    cr_assert_eq(my_fputs("Hello, World!\n", MY_STDOUT), 0);
    cr_assert_eq(my_flush_stdout(), 0);
    cr_assert_stdout_eq_str("Hello, World!\n", "");
}

Test(my_fputs, memory_stream_filled_string)
{
    my_iostream_t stream;
    char buf[16] = { 0 };

    my_finit_output_memory(buf, 16, &stream);
    cr_assert_eq(my_fputs("This is a test.", &stream), 0);
    cr_assert_str_eq(buf, "This is a test.");
}

Test(my_puts, base, .init = setup, .fini = finish)
{
    cr_assert_eq(my_puts("This is a test."), 0);
    cr_assert_eq(my_flush_stdout(), 0);
    cr_assert_stdout_eq_str("This is a test.", "");
}

Test(my_eputs, base, .init = setup, .fini = finish)
{
    cr_assert_eq(my_eputs("Error: test"), 0);
    cr_assert_eq(my_flush_stderr(), 0);
    cr_assert_stderr_eq_str("Error: test", "");
}
