/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Tests the my_is_*_stream functions
*/

#include <criterion/criterion.h>
#include "libmy/io.h"

Test(my_is_input_stream, memory_input_stream)
{
    my_iostream_t stream;

    my_finit_input_memory(NULL, 42, &stream);
    cr_assert(my_is_input_stream(&stream));
}

Test(my_is_input_stream, memory_output_stream)
{
    my_iostream_t stream;

    my_finit_output_memory(NULL, 42, &stream);
    cr_assert(!my_is_input_stream(&stream));
}

Test(my_is_input_stream, void_input_stream)
{
    cr_assert(my_is_input_stream(MY_VOID_IN));
}

Test(my_is_input_stream, void_output_stream)
{
    cr_assert(!my_is_input_stream(MY_VOID_OUT));
}

Test(my_is_output_stream, unix_input_stream)
{
    my_iostream_t stream;

    my_finit_input_fd(0, &stream);
    cr_assert(!my_is_output_stream(&stream));
}

Test(my_is_output_stream, unix_output_stream)
{
    my_iostream_t stream;

    my_finit_output_fd(1, &stream);
    cr_assert(my_is_output_stream(&stream));
}

Test(my_is_output_stream, memory_input_stream)
{
    my_iostream_t stream;

    my_finit_input_memory(NULL, 42, &stream);
    cr_assert(!my_is_output_stream(&stream));
}

Test(my_is_output_stream, memory_output_stream)
{
    my_iostream_t stream;

    my_finit_output_memory(NULL, 42, &stream);
    cr_assert(my_is_output_stream(&stream));
}

Test(my_is_output_stream, void_input_stream)
{
    cr_assert(!my_is_output_stream(MY_VOID_IN));
}

Test(my_is_output_stream, void_output_stream)
{
    cr_assert(my_is_output_stream(MY_VOID_OUT));
}
