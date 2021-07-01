/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_fwrite function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include <limits.h>
#include "libmy/io.h"

static void redirect_all_output(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_fwrite, write_strings, .init = redirect_all_output)
{
    unsigned char buf[15];
    my_iostream_t *my_stdout = MY_STDOUT;

    my_init_stdout((unsigned char *)&buf, 15, NULL);
    fflush(stdout);
    cr_assert_eq(my_fwrite("test\n", 5, 1, my_stdout), 1);
    cr_assert_eq(my_fwrite("bleh\n", 5, 1, my_stdout), 1);
    cr_assert_eq(my_fflush(my_stdout), 0);
    cr_assert_eq(my_stdout->unix_stream.buf_len, 0);
    cr_assert_eq(my_fwrite("filling the buf", 1, 15, my_stdout), 15);
    cr_assert_eq(my_fflush(my_stdout), 0);
    cr_assert_eq(my_fwrite("filling the ", 1, 12, my_stdout), 12);
    cr_assert_eq(my_fwrite("buf\n", 3, 1, my_stdout), 1);
    cr_assert_eq(my_fflush(my_stdout), 0);
    cr_assert_stdout_eq_str("test\nbleh\nfilling the buffilling the buf\n", "");
}

Test(my_fwrite, closed_stream)
{
    my_iostream_t stream;

    my_finit_output_fd(1, &stream);
    my_fset_buffer(malloc(256), 256, &free, &stream);
    stream.unix_stream.is_eof = 1;
    cr_assert_eq(my_fwrite("test", 1, 4, &stream), 0);
    my_ffree(&stream);
}

Test(my_fwrite, input_stream)
{
    my_iostream_t stream;

    my_finit_input_fd(0, &stream);
    my_fset_buffer(malloc(256), 256, &free, &stream);
    cr_assert_eq(my_fwrite("test", 1, 4, &stream), 0);
    my_ffree(&stream);
}

Test(my_fwrite, small_buf, .init = redirect_all_output)
{
    my_init_stdout(malloc(2), 2, &free);
    cr_assert_eq(my_fwrite("test\n", 5, 1, MY_STDOUT), 1);
    cr_assert_eq(my_fwrite("bleh\n", 5, 1, MY_STDOUT), 1);
    cr_assert_eq(my_fflush(MY_STDOUT), 0);
    cr_assert_eq(MY_STDOUT->unix_stream.buf_len, 0);
    cr_assert_stdout_eq_str("test\nbleh\n", "");
    my_free_stdout();
}

Test(my_fwrite, small_threshold, .init = redirect_all_output)
{
    my_init_stdout(malloc(512), 512, &free);
    my_fset_flush_threshold(0.0, MY_STDOUT);
    cr_assert_eq(my_fwrite("test\n", 5, 1, MY_STDOUT), 1);
    cr_assert_eq(my_fwrite("bleh\n", 5, 1, MY_STDOUT), 1);
    cr_assert_eq(my_fflush(MY_STDOUT), 0);
    cr_assert_eq(MY_STDOUT->unix_stream.buf_len, 0);
    cr_assert_stdout_eq_str("test\nbleh\n", "");
    my_free_stdout();
}

Test(my_fwrite, invalid_fd)
{
    my_iostream_t stream;

    my_finit_output_fd(INT_MAX, &stream);
    my_fset_buffer(malloc(256), 256, &free, &stream);
    my_fset_flush_threshold(0.0, &stream);
    cr_assert_eq(my_feof(&stream), 0);
    cr_assert_eq(my_fwrite("test", 1, 4, &stream), 0);
    my_ffree(&stream);
}

Test(my_fwrite, void_output_stream)
{
    cr_assert_eq(my_fwrite("test", 1, 4, MY_VOID_OUT), 4);
    cr_assert_eq(my_fwrite("test", 4, 1, MY_VOID_OUT), 1);
}

Test(my_fwrite, memory_partial)
{
    char buf[4];
    my_iostream_t stream;

    my_finit_output_memory(buf, 4, &stream);
    cr_assert_eq(my_fwrite("This is a test", 1, 14, &stream), 4);
}

Test(my_fwrite, memory_normal)
{
    char buf[15];
    my_iostream_t stream;

    my_finit_output_memory(buf, 15, &stream);
    cr_assert_eq(my_fwrite("This is a test", 1, 14, &stream), 14);
    buf[14] = '\0';
    cr_assert_str_eq(buf, "This is a test");
}
