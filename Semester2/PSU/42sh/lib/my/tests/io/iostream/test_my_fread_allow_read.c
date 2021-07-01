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

Test(my_fread, unix_stream_invalid_fd)
{
    char buf[4];
    my_iostream_t stream;

    my_finit_input_fd(-42, &stream);
    my_fset_buffer(buf, 4, NULL, &stream);
    cr_assert_eq(my_fread(NULL, 0, 0, &stream), 0);
}

Test(my_fread, unix_stream_read_strings)
{
    unsigned char buf[15];
    my_iostream_t *my_stdin = MY_STDIN;
    FILE *in = cr_get_redirected_stdin();
    char output[32];

    my_init_stdin((unsigned char *)buf, 15, NULL);
    fputs("test", in);
    fflush(in);
    cr_assert_eq(my_fread(output, 1, 4, my_stdin), 4);
    output[4] = 0;
    cr_assert_str_eq(output, "test");
    fputs("filling the buf", in);
    fflush(in);
    cr_assert_eq(my_fread(output, 1, 15, my_stdin), 15);
    output[16] = 0;
    cr_assert_str_eq(output, "filling the buf");
}

Test(my_fread, unix_stream_read_full_buf_multiple_times)
{
    unsigned char buf[15];
    my_iostream_t *my_stdin = MY_STDIN;
    FILE *in = cr_get_redirected_stdin();
    char output[32];

    (void)in;
    my_init_stdin((unsigned char *)buf, 15, NULL);
    fputs("filling the buf", in);
    fflush(in);
    cr_assert_eq(my_fread(output, 1, 1, my_stdin), 1);
    cr_assert_eq(my_fread(output + 1, 1, 4, my_stdin), 4);
    cr_assert_eq(my_fread(output + 5, 1, 1, my_stdin), 1);
    cr_assert_eq(my_fread(output + 6, 1, 2, my_stdin), 2);
    cr_assert_eq(my_fread(output + 8, 1, 2, my_stdin), 2);
    cr_assert_eq(my_fread(output + 10, 5, 1, my_stdin), 1);
    output[16] = 0;
    cr_assert_str_eq(output, "filling the buf");
}

Test(my_fread, unix_stream_read_buf_with_existing_chars)
{
    unsigned char buf[15] = "testing";
    my_iostream_t *my_stdin = MY_STDIN;
    FILE *in = cr_get_redirected_stdin();
    char output[32];

    (void)in;
    my_init_stdin((unsigned char *)buf, 15, NULL);
    MY_STDIN->unix_stream.buf_len = 7;
    fputs(" is cool", in);
    fflush(in);
    cr_assert_eq(my_fread(output, 1, 15, my_stdin), 15);
    output[15] = 0;
    cr_assert_str_eq(output, "testing is cool");
}
