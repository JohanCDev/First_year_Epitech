/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Tests the my_fset_buffer function
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "libmy/io.h"

Test(my_fset_buffer, unix_streams_valid)
{
    my_iostream_t input;
    my_iostream_t output;

    my_finit_input_fd(0, &input);
    my_finit_output_fd(2, &output);
    cr_assert_eq(my_fset_buffer(malloc(64), 64, &free, &input), 0);
    cr_assert_eq(my_fset_buffer(malloc(64), 64, &free, &output), 0);
    cr_assert_neq(input.unix_stream.buf, NULL);
    cr_assert_neq(output.unix_stream.buf, NULL);
    cr_assert_eq(input.unix_stream.buf_cap, 64);
    cr_assert_eq(output.unix_stream.buf_cap, 64);
    cr_assert_eq(input.unix_stream.free_buf, &free);
    cr_assert_eq(output.unix_stream.free_buf, &free);
    my_ffree(&input);
    my_ffree(&output);
}

Test(my_fset_buffer, memory_streams)
{
    my_iostream_t input;
    my_iostream_t output;

    my_finit_input_memory("test", 5, &input);
    my_finit_output_memory(NULL, 0, &output);
    cr_assert_eq(my_fset_buffer(NULL, 0, NULL, &input), 0);
    cr_assert_eq(my_fset_buffer(NULL, 0, NULL, &output), 0);
}

Test(my_fset_buffer, void_streams)
{
    cr_assert_eq(my_fset_buffer(NULL, 0, NULL, MY_VOID_IN), 0);
    cr_assert_eq(my_fset_buffer(NULL, 0, NULL, MY_VOID_OUT), 0);
}
