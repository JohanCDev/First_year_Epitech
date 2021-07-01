/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_fget_buffer function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "libmy/io.h"

Test(my_fget_buffer, unix_stream_empty)
{
    my_iostream_t stream;
    size_t size;

    my_finit_output_fd(1, &stream);
    cr_assert_eq(my_fget_buffer(&size, &stream), NULL);
    cr_assert_eq(size, 0);
}

Test(my_fget_buffer, unix_stream_filled, .init = cr_redirect_stdout)
{
    unsigned char buf[42];
    size_t size;

    cr_assert_eq(my_init_stdout(buf, 42, NULL), 0);
    cr_assert_eq(my_puts("This is a test"), 0);
    cr_assert_eq(my_fget_buffer(&size, MY_STDOUT), buf);
    cr_assert_eq(size, 14);
    my_flush_stdout();
    cr_assert_eq(my_fget_buffer(&size, MY_STDOUT), buf);
    cr_assert_eq(size, 0);
}

Test(my_fget_buffer, memory_stream_filled)
{
    char buf[42];
    my_iostream_t stream;
    size_t size;

    cr_assert_eq(my_finit_output_memory(buf, 42, &stream), 0);
    cr_assert_eq(my_fputs("This is a test", &stream), 0);
    cr_assert_eq(my_fget_buffer(&size, &stream), buf);
    cr_assert_eq(size, 14);
    buf[size] = '\0';
    cr_assert_str_eq(buf, "This is a test");
}

Test(my_fget_buffer, void_stream)
{
    size_t size;

    cr_assert_eq(my_fget_buffer(&size, MY_VOID_OUT), NULL);
    cr_assert_eq(size, 0);
    cr_assert_eq(my_fget_buffer(&size, MY_VOID_IN), NULL);
    cr_assert_eq(size, 0);
}
