/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the fread_to_string function
*/

#include <limits.h>
#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "libmy/io.h"

Test(my_fread_to_string, read_nothing)
{
    char const *input = "test";
    my_iostream_t in;
    char *output = "yeet";
    size_t output_len = 42;

    my_finit_input_memory(&input, 4, &in);
    output = my_fread_to_string(0, &output_len, &in);
    cr_assert_eq(output_len, 0);
    cr_assert_str_eq(output, "");
    free(output);
}

Test(my_fread_to_string, read_invalid_stream)
{
    char *output = "yeet";
    size_t output_len = 42;
    my_iostream_t stream;

    my_finit_input_fd(INT_MAX, &stream);
    my_fset_buffer(malloc(256), 256, &free, &stream);
    output = my_fread_to_string(67, &output_len, &stream);
    cr_assert_eq(output_len, 0);
    cr_assert_eq(output, NULL);
    free(output);
    my_ffree(&stream);
}

Test(my_fread_to_string, read_closed_stream)
{
    char *output = "yeet";
    size_t output_len = 42;
    my_iostream_t stream;

    my_finit_input_memory(NULL, 0, &stream);
    output = my_fread_to_string(67, &output_len, &stream);
    cr_assert_eq(output_len, 0);
    cr_assert_str_eq(output, "");
    free(output);
}

Test(my_fread_to_string, read_normal)
{
    char const *input = "This is a test";
    my_iostream_t stream;
    char *output = "yeet";
    size_t output_len = 42;

    my_finit_input_memory(input, 14, &stream);
    output = my_fread_to_string(14, &output_len, &stream);
    cr_assert_eq(output_len, 14);
    cr_assert_str_eq(output, "This is a test");
    free(output);
}

Test(my_fread_to_string, read_small)
{
    char const *input = "This is a test";
    my_iostream_t stream;
    char *output = "yeet";
    size_t output_len = 42;

    my_finit_input_memory(input, 14, &stream);
    output = my_fread_to_string(7, &output_len, &stream);
    cr_assert_eq(output_len, 7);
    cr_assert_str_eq(output, "This is");
    free(output);
}

Test(my_fread_to_string, read_whole_input)
{
    char const *input = "This is a test";
    my_iostream_t stream;
    char *output = "yeet";
    size_t output_len = 42;

    my_finit_input_memory(input, 14, &stream);
    output = my_fread_to_string(76786, &output_len, &stream);
    cr_assert_eq(output_len, 14);
    cr_assert_str_eq(output, "This is a test");
    free(output);
}
