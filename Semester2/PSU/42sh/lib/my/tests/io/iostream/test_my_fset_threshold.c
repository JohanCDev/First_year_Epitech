/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_fset_flush_threshold function
*/

#include <criterion/criterion.h>
#include "libmy/io.h"

Test(my_fset_flush_threshold, unix_streams_invalid)
{
    my_iostream_t input;
    my_iostream_t output;

    my_finit_input_fd(0, &input);
    my_finit_output_fd(2, &output);
    cr_assert_neq(my_fset_flush_threshold(-1.0, &input), 0);
    cr_assert_neq(my_fset_flush_threshold(42.4, &input), 0);
    cr_assert_neq(my_fset_flush_threshold(-1.0, &output), 0);
    cr_assert_neq(my_fset_flush_threshold(42.4, &output), 0);
}

Test(my_fset_flush_threshold, unix_streams_valid)
{
    my_iostream_t input;
    my_iostream_t output;

    my_finit_input_fd(0, &input);
    my_finit_output_fd(2, &output);
    cr_assert_eq(my_fset_flush_threshold(0.5, &input), 0);
    cr_assert_eq(my_fset_flush_threshold(0.5, &output), 0);
}

Test(my_fset_flush_threshold, memory_streams)
{
    my_iostream_t input;
    my_iostream_t output;

    my_finit_input_memory("test", 5, &input);
    my_finit_output_memory(NULL, 0, &output);
    cr_assert_eq(my_fset_flush_threshold(0.5, &input), 0);
    cr_assert_eq(my_fset_flush_threshold(0.5, &output), 0);
}

Test(my_fset_flush_threshold, void_streams)
{
    cr_assert_eq(my_fset_flush_threshold(0.5, MY_VOID_IN), 0);
    cr_assert_eq(my_fset_flush_threshold(0.4, MY_VOID_OUT), 0);
}
