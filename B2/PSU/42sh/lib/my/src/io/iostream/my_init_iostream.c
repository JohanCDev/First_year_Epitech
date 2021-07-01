/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Initializes the builtin streams
*/

#include <unistd.h>
#include "libmy/io.h"

MY_IO_API int my_init_stdin(
    unsigned char *buf, size_t buf_cap, void (*free_buf)(void *))
{
    my_iostream_t *my_stdin = MY_STDIN;

    my_finit_input_fd(STDIN_FILENO, my_stdin);
    return my_fset_buffer(buf, buf_cap, free_buf, my_stdin);
}

MY_IO_API int my_init_stdout(
    unsigned char *buf, size_t buf_cap, void (*free_buf)(void *))
{
    my_iostream_t *my_stdout = MY_STDOUT;

    my_finit_output_fd(STDOUT_FILENO, my_stdout);
    return my_fset_buffer(buf, buf_cap, free_buf, my_stdout);
}

MY_IO_API int my_init_stderr(
    unsigned char *buf, size_t buf_cap, void (*free_buf)(void *))
{
    my_iostream_t *my_stderr = MY_STDERR;

    my_finit_output_fd(STDERR_FILENO, my_stderr);
    return my_fset_buffer(buf, buf_cap, free_buf, my_stderr);
}
