/*
** EPITECH PROJECT, 2020
** Day06 unit tests
** File description:
** Tests my_fputint
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <limits.h>
#include <stdlib.h>
#include "libmy/io.h"

static void redirect_all_output(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_fputint, negative_cannot_write)
{
    my_iostream_t stream;
    unsigned char buf[8];

    my_finit_output_memory(buf, 0, &stream);
    cr_assert_eq(my_fputint(-4, &stream), 0);
}

Test(my_fputint, negative_write_only_one_char)
{
    my_iostream_t stream;
    unsigned char buf[8];

    my_finit_output_memory(buf, 1, &stream);
    cr_assert_eq(my_fputint(-4, &stream), 0);
}

Test(my_fputint, cannot_write)
{
    my_iostream_t stream;
    unsigned char buf[8];

    my_finit_output_memory(buf, 0, &stream);
    cr_assert_eq(my_fputint(42, &stream), 0);
}

Test(my_fputint, zero, .init=redirect_all_output)
{
    unsigned char buf[256];

    my_init_stdout(buf, 256, NULL);
    cr_assert_eq(my_fputint(0, MY_STDOUT), 1);
    my_flush_stdout();
    cr_assert_stdout_eq_str("0", "");
}

Test(my_fputint, one, .init=redirect_all_output)
{
    unsigned char buf[256];

    my_init_stdout(buf, 256, NULL);
    cr_assert_eq(my_fputint(1, MY_STDOUT), 1);
    my_flush_stdout();
    cr_assert_stdout_eq_str("1", "");
}

Test(my_fputint_fd, minus_four, .init=redirect_all_output)
{
    unsigned char buf[256];

    my_init_stderr(buf, 256, NULL);
    cr_assert_eq(my_fputint(-4, MY_STDERR), 2);
    my_flush_stderr();
    cr_assert_stderr_eq_str("-4", "");
}

Test(my_fputint, minus_one_hundred_and_forty_two, .init=redirect_all_output)
{
    my_iostream_t mem_stream;
    unsigned char buf[256];
    unsigned char mem_buf[8] = { 0 };

    my_init_stdout(buf, 256, NULL);
    my_finit_output_memory(mem_buf, 8, &mem_stream);
    cr_assert_eq(my_fputint(-142, MY_STDOUT), 4);
    cr_assert_eq(my_fputint(-142, &mem_stream), 4);
    cr_assert_str_eq((char *)mem_buf, "-142");
    my_flush_stdout();
    cr_assert_stdout_eq_str("-142", "");
}

Test(my_fputint, two_thousand_seventy_four, .init=redirect_all_output)
{
    unsigned char buf[256];

    my_init_stdout(buf, 256, NULL);
    cr_assert_eq(my_fputint(2074, MY_STDOUT), 4);
    my_flush_stdout();
    cr_assert_stdout_eq_str("2074", "");
}

Test(my_fputint, int_max, .init=redirect_all_output)
{
    unsigned char buf[256];

    my_init_stdout(buf, 256, NULL);
    cr_assert_eq(my_fputint(INT_MAX, MY_STDOUT), 10);
    my_flush_stdout();
    cr_assert_stdout_eq_str("2147483647", "");
}

Test(my_fputint, int_min, .init=redirect_all_output)
{
    my_init_stdout(malloc(256), 256, &free);
    cr_assert_eq(my_fputint(INT_MIN, MY_STDOUT), 11);
    my_flush_stdout();
    cr_assert_stdout_eq_str("-2147483648", "");
}
