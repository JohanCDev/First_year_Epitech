/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Tests the my_feof function
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "libmy/io.h"

Test(my_feof, unix_stream_invalid_fd)
{
    my_iostream_t stream;

    my_finit_input_fd(-1, &stream);
    my_fset_buffer(malloc(256), 256, &free, &stream);
    cr_assert_eq(my_feof(&stream), 1);
    my_ffree(&stream);
}

Test(my_feof, unix_stream_empty_buf_and_eof)
{
    my_iostream_t stream;

    my_finit_input_fd(1, &stream);
    my_fset_buffer(malloc(256), 256, &free, &stream);
    stream.unix_stream.buf_len = 0;
    stream.unix_stream.is_eof = 1;
    cr_assert_eq(my_feof(&stream), 1);
    my_ffree(&stream);
}

Test(my_feof, unix_stream_empty_buf_no_eof)
{
    my_iostream_t stream;

    my_finit_input_fd(1, &stream);
    my_fset_buffer(malloc(256), 256, &free, &stream);
    stream.unix_stream.buf_len = 0;
    cr_assert_eq(my_feof(&stream), 0);
    my_ffree(&stream);
}

Test(my_feof, unix_stream_filled_buf_and_eof)
{
    my_iostream_t stream;

    my_finit_input_fd(1, &stream);
    my_fset_buffer(malloc(256), 256, &free, &stream);
    stream.unix_stream.buf_len = 45;
    stream.unix_stream.is_eof = 1;
    cr_assert_eq(my_feof(&stream), 0);
    my_ffree(&stream);
}

Test(my_feof, unix_stream_filled_buf_no_eof)
{
    my_iostream_t stream;

    my_finit_input_fd(1, &stream);
    my_fset_buffer(malloc(256), 256, &free, &stream);
    stream.unix_stream.buf_len = 45;
    stream.unix_stream.is_eof = 0;
    cr_assert_eq(my_feof(&stream), 0);
    my_ffree(&stream);
}

Test(my_feof, memory_streams_null_buf)
{
    my_iostream_t input;
    my_iostream_t output;

    my_finit_input_memory(NULL, 5, &input);
    my_finit_output_memory(NULL, 14, &output);
    cr_assert(my_feof(&input));
    cr_assert(my_feof(&output));
}

Test(my_feof, memory_streams_consumed_buf)
{
    my_iostream_t input;
    my_iostream_t output;
    char buf[14];

    my_finit_input_memory("test", 5, &input);
    my_finit_output_memory(buf, 14, &output);
    input.memory_stream.count = 5;
    output.memory_stream.count = 42;
    cr_assert(my_feof(&input));
    cr_assert(my_feof(&output));
}

Test(my_feof, memory_streams_valid)
{
    my_iostream_t input;
    my_iostream_t output;
    char buf[14];

    my_finit_input_memory("test", 5, &input);
    my_finit_output_memory(buf, 14, &output);
    cr_assert(!my_feof(&input));
    cr_assert(!my_feof(&output));
}

Test(my_feof, void_input_stream)
{
    cr_assert(my_feof(MY_VOID_IN));
}

Test(my_feof, void_output_stream)
{
    cr_assert(!my_feof(MY_VOID_OUT));
}
