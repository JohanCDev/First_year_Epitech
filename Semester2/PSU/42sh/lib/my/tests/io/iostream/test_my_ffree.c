/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_ffree, my_free_stdin, my_free_stdout & my_free_stderr functions
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "libmy/io.h"

Test(my_ffree, stack_buffer)
{
    my_iostream_t stream;
    unsigned char buf[16];

    my_finit_output_fd(1, &stream);
    my_fset_buffer(buf, 16, NULL, &stream);
    my_ffree(&stream);
}

Test(my_ffree, alloc_buffer)
{
    my_iostream_t stream;

    my_finit_output_fd(1, &stream);
    my_fset_buffer(malloc(256), 256, &free, &stream);
    my_ffree(&stream);
}

Test(my_ffree, void_input_stream)
{
    my_ffree(MY_VOID_IN);
}

Test(my_ffree, void_output_stream)
{
    my_ffree(MY_VOID_OUT);
}
