/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_finit function
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include "libmy/io.h"

Test(my_finit_input_fd, base)
{
    my_iostream_t input;

    cr_assert_eq(my_finit_input_fd(42, &input), 0);
    cr_assert_neq(input.vtable, NULL);
    cr_assert_eq(input.vtable->write, NULL);
    cr_assert_eq(input.unix_stream.fd, 42);
    cr_assert_eq(input.unix_stream.is_eof, 0);
    cr_assert_eq(input.unix_stream.buf, NULL);
    cr_assert_eq(input.unix_stream.buf_cap, 0);
    cr_assert_eq(input.unix_stream.buf_len, 0);
    cr_assert_eq(input.unix_stream.threshold, MY_DEFAULT_FLUSH_THRESHOLD);
    cr_assert_eq(input.unix_stream.free_buf, NULL);
}

Test(my_finit_output_fd, base)
{
    my_iostream_t output;

    cr_assert_eq(my_finit_output_fd(42, &output), 0);
    cr_assert_neq(output.vtable, NULL);
    cr_assert_eq(output.vtable->read, NULL);
    cr_assert_eq(output.unix_stream.fd, 42);
    cr_assert_eq(output.unix_stream.is_eof, 0);
    cr_assert_eq(output.unix_stream.buf, NULL);
    cr_assert_eq(output.unix_stream.buf_cap, 0);
    cr_assert_eq(output.unix_stream.buf_len, 0);
    cr_assert_eq(output.unix_stream.threshold, MY_DEFAULT_FLUSH_THRESHOLD);
    cr_assert_eq(output.unix_stream.free_buf, NULL);
}

Test(my_finit_input_memory, base)
{
    my_iostream_t input;
    char const *buf = "test";

    cr_assert_eq(my_finit_input_memory(buf, 5, &input), 0);
    cr_assert_neq(input.vtable, NULL);
    cr_assert_eq(input.vtable->write, NULL);
    cr_assert_eq(input.vtable->flush, NULL);
    cr_assert_eq(input.vtable->destroy, NULL);
    cr_assert_eq(input.vtable->set_threshold, NULL);
    cr_assert_eq(input.vtable->set_buffer, NULL);
    cr_assert_eq(input.vtable->close, NULL);
    cr_assert_eq(input.memory_stream.buf, buf);
    cr_assert_eq(input.memory_stream.count, 0);
    cr_assert_eq(input.memory_stream.limit, 5);
}

Test(my_finit_output_memory, base)
{
    my_iostream_t output;
    char buf[] = "test";

    cr_assert_eq(my_finit_output_memory(buf, 5, &output), 0);
    cr_assert_neq(output.vtable, NULL);
    cr_assert_eq(output.vtable->read, NULL);
    cr_assert_eq(output.vtable->flush, NULL);
    cr_assert_eq(output.vtable->destroy, NULL);
    cr_assert_eq(output.vtable->set_threshold, NULL);
    cr_assert_eq(output.vtable->set_buffer, NULL);
    cr_assert_eq(output.vtable->close, NULL);
    cr_assert_eq(output.memory_stream.buf, buf);
    cr_assert_eq(output.memory_stream.count, 0);
    cr_assert_eq(output.memory_stream.limit, 5);
}
