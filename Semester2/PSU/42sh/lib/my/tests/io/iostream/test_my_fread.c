/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_fread function
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "libmy/io.h"

Test(my_fread, memory_stream_eof)
{
    char *buf = "test";
    my_iostream_t stream;

    my_finit_input_memory(buf, 4, &stream);
    stream.memory_stream.count = 4;
    cr_assert_eq(my_fread(NULL, 0, 0, &stream), 0);
}

Test(my_fread, memory_stream_normal_strings)
{
    char *buf = "This is a test";
    char dst[16] = {0};
    my_iostream_t stream;

    my_finit_input_memory(buf, 15, &stream);
    cr_assert_eq(my_fread(dst, 1, 4, &stream), 4);
    cr_assert_str_eq(dst, "This");
    cr_assert_eq(my_fread(dst + 4, 6, 1, &stream), 1);
    cr_assert_str_eq(dst, "This is a ");
    cr_assert_eq(my_fread(dst + 10, 1, 4, &stream), 4);
    cr_assert_str_eq(dst, "This is a test");
    cr_assert_eq(my_fread(dst, 42, 1, &stream), 0);
}

Test(my_fread, void_streams)
{
    cr_assert_eq(my_fread(NULL, 0, 0, MY_VOID_IN), 0);
    cr_assert_eq(my_fread(NULL, 0, 0, MY_VOID_OUT), 0);
}
