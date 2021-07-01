/*
** EPITECH PROJECT, 2020
** Libmy - io module
** File description:
** Tests the my_free_stdin, my_free_stdout and my_free_stderr functions
*/

#include <criterion/criterion.h>
#include "libmy/io.h"

Test(my_free_stdin, stack_buffer)
{
    unsigned char buf[16];

    my_init_stdin(buf, 16, NULL);
    my_free_stdin();
}

Test(my_free_stdin, alloc_buffer)
{
    my_init_stdin(malloc(256), 256, &free);
    my_free_stdin();
}

Test(my_free_stdout, stack_buffer)
{
    unsigned char buf[16];

    my_init_stdout(buf, 16, NULL);
    my_free_stdout();
}

Test(my_free_stdout, alloc_buffer)
{
    my_init_stdout(malloc(256), 256, &free);
    my_free_stdout();
}

Test(my_free_stderr, stack_buffer)
{
    unsigned char buf[16];

    my_init_stderr(buf, 16, NULL);
    my_free_stderr();
}

Test(my_free_stderr, alloc_buffer)
{
    my_init_stderr(malloc(256), 256, &free);
    my_free_stderr();
}
