/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_flush_std* functions
*/

#include <criterion/criterion.h>
#include "libmy/io.h"

Test(my_flush_stdin, base)
{
    my_init_stdin(NULL, 0, NULL);
    my_flush_stdin();
    cr_assert_eq(MY_STDIN->unix_stream.buf_len, 0);
}

Test(my_flush_stdout, base)
{
    my_init_stdout(NULL, 0, NULL);
    my_flush_stdout();
    cr_assert_eq(MY_STDOUT->unix_stream.buf_len, 0);
}

Test(my_flush_stderr, base)
{
    my_init_stderr(NULL, 0, NULL);
    my_flush_stderr();
    cr_assert_eq(MY_STDERR->unix_stream.buf_len, 0);
}
