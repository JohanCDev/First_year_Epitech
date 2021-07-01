/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the fflush function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "libmy/io.h"

static void redirect_all_output(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_fflush, empty_unix_input_stream)
{
    unsigned char buf[256];
    my_iostream_t stream;

    my_finit_input_fd(0, &stream);
    my_fset_buffer(buf, 256, NULL, &stream);
    cr_assert_eq(my_fflush(&stream), 0);
    cr_assert_eq(stream.unix_stream.buf_len, 0);
    my_ffree(&stream);
}

Test(my_fflush, filled_unix_input_stream)
{
    unsigned char buf[256] = "yeet is the new foo";
    my_iostream_t stream;

    my_finit_input_fd(0, &stream);
    my_fset_buffer(buf, 256, NULL, &stream);
    stream.unix_stream.buf_len = 20;
    cr_assert_eq(my_fflush(&stream), 0);
    cr_assert_eq(stream.unix_stream.buf_len, 0);
    my_ffree(&stream);
}

Test(my_fflush, empty_unix_output_stream)
{
    unsigned char buf[256];
    my_iostream_t stream;

    my_finit_output_fd(1, &stream);
    my_fset_buffer(buf, 256, NULL, &stream);
    cr_assert_eq(my_fflush(&stream), 0);
    cr_assert_eq(stream.unix_stream.buf_len, 0);
    my_ffree(&stream);
}

Test(my_fflush, filled_output_stream, .init = redirect_all_output)
{
    unsigned char buf[256] = "This is a test message\n";
    my_iostream_t stream;

    my_finit_output_fd(2, &stream);
    my_fset_buffer(buf, 256, NULL, &stream);
    stream.unix_stream.buf_len = 23;
    cr_assert_eq(my_fflush(&stream), 0);
    cr_assert_eq(stream.unix_stream.buf_len, 0);
    cr_assert_stderr_eq_str("This is a test message\n", "");
    my_ffree(&stream);
}

Test(my_fflush, ultra_filled_unix_output_stream, .init = redirect_all_output)
{
    size_t size = MY_WRITE_SIZE + 42;
    my_iostream_t stream;
    unsigned char to_write = 0;

    my_finit_output_fd(1, &stream);
    my_fset_buffer(malloc(size), size, &free, &stream);
    for (size_t i = 0; i < size; ++i) {
        ((unsigned char *)stream.unix_stream.buf)[i] = to_write;
        to_write = to_write == 255 ? 0 : to_write + 1;
    }
    stream.unix_stream.buf_len = size;
    cr_assert_eq(my_fflush(&stream), 0);
    my_ffree(&stream);
}

Test(my_fflush, void_input_stream)
{
    cr_assert_eq(my_fflush(MY_VOID_IN), 0);
}

Test(my_fflush, void_output_stream)
{
    cr_assert_eq(my_fflush(MY_VOID_OUT), 0);
}
