/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_init_std* functions
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "libmy/io.h"

Test(my_init_stdin, base)
{
    unsigned char buf[256];
    p_my_iostream_unix_t *stream;

    cr_assert_eq(my_init_stdin(buf, 256, NULL), 0);
    stream = &(MY_STDIN->unix_stream);
    cr_assert_eq(stream->buf, buf);
    cr_assert_eq(stream->buf_cap, 256);
    cr_assert_eq(stream->fd, 0);
    cr_assert_eq(stream->is_eof, 0);
    cr_assert_eq(stream->free_buf, NULL);
}

Test(my_init_stdout, base)
{
    unsigned char buf[256];
    p_my_iostream_unix_t *stream;

    cr_assert_eq(my_init_stdout(buf, 256, NULL), 0);
    stream = &(MY_STDOUT->unix_stream);
    cr_assert_eq(stream->buf, buf);
    cr_assert_eq(stream->buf_cap, 256);
    cr_assert_eq(stream->fd, 1);
    cr_assert_eq(stream->is_eof, 0);
    cr_assert_eq(stream->free_buf, NULL);
}

Test(my_init_stderr, base)
{
    unsigned char buf[256];
    p_my_iostream_unix_t *stream;

    cr_assert_eq(my_init_stderr(buf, 256, &free), 0);
    stream = &(MY_STDERR->unix_stream);
    cr_assert_eq(stream->buf, buf);
    cr_assert_eq(stream->buf_cap, 256);
    cr_assert_eq(stream->fd, 2);
    cr_assert_eq(stream->is_eof, 0);
    cr_assert_eq(stream->free_buf, &free);
}
