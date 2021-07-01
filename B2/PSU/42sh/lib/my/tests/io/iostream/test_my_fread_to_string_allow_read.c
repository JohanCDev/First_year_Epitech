/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the fread_to_string function (allow_read)
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "libmy/io.h"

Test(my_fread_to_string, read_stdin_small_buffer)
{
    char *output = "yeet";
    size_t output_len = 42;
    FILE *in = cr_get_redirected_stdin();

    my_init_stdin(malloc(3), 3, &free);
    fputs("Buffered I/O is awesome!", in);
    fflush(in);
    output = my_fread_to_string(24, &output_len, MY_STDIN);
    cr_assert_eq(output_len, 24);
    cr_assert_str_eq(output, "Buffered I/O is awesome!");
    free(output);
}

Test(my_fread_to_string, read_stdin_tiny_buffer)
{
    char *output = "yeet";
    size_t output_len = 42;
    FILE *in = cr_get_redirected_stdin();

    my_init_stdin(malloc(1), 1, &free);
    fputs("Buffered I/O is awesome!", in);
    fflush(in);
    output = my_fread_to_string(24, &output_len, MY_STDIN);
    cr_assert_eq(output_len, 24);
    cr_assert_str_eq(output, "Buffered I/O is awesome!");
    free(output);
}
