/*
** EPITECH PROJECT, 2020
** Day06 unit tests
** File description:
** Tests my_fputuint
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

Test(my_fputuint, cannot_write)
{
    my_iostream_t stream;

    my_finit_output_memory(NULL, 0, &stream);
    cr_assert_eq(my_fputuint(42, &stream), 0);
}

Test(my_fputuint, zero, .init=redirect_all_output)
{
    unsigned char buf[256];

    my_init_stdout(buf, 256, NULL);
    cr_assert_eq(my_fputuint(0, MY_STDOUT), 1);
    my_flush_stdout();
    cr_assert_stdout_eq_str("0", "");
}

Test(my_fputuint, one, .init=redirect_all_output)
{
    unsigned char buf[256];

    my_init_stdout(buf, 256, NULL);
    cr_assert_eq(my_fputuint(1, MY_STDOUT), 1);
    my_flush_stdout();
    cr_assert_stdout_eq_str("1", "");
}

Test(my_fputuint, one_hundred_and_forty_two, .init=redirect_all_output)
{
    unsigned char buf[256];

    my_init_stdout(buf, 256, NULL);
    cr_assert_eq(my_fputuint(142, MY_STDOUT), 3);
    my_flush_stdout();
    cr_assert_stdout_eq_str("142", "");
}

Test(my_fputuint, two_thousand_seventy_four, .init=redirect_all_output)
{
    unsigned char buf[256];

    my_init_stdout(buf, 256, NULL);
    cr_assert_eq(my_fputuint(2074, MY_STDOUT), 4);
    my_flush_stdout();
    cr_assert_stdout_eq_str("2074", "");
}

Test(my_fputuint, uint_max, .init=redirect_all_output)
{
    my_init_stdout(malloc(256), 256, &free);
    cr_assert_eq(my_fputuint(UINT_MAX, MY_STDOUT), 10);
    my_flush_stdout();
    cr_assert_stdout_eq_str("4294967295", "");
}
