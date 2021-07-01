/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_fprintf function
*/

#include <criterion/criterion.h>
#include "libmy/printf.h"

Test(my_fprintf, io_error_regular_string)
{
    char buf[4];
    my_iostream_t stream;

    my_finit_output_memory(buf, 4, &stream);
    cr_assert_lt(my_fprintf(&stream, "This is a test"), 0);
}

Test(my_fprintf, io_error_regular_string_with_conv)
{
    char buf[4];
    my_iostream_t stream;

    my_finit_output_memory(buf, 4, &stream);
    cr_assert_lt(my_fprintf(&stream, "Hello, %s!", "World"), 0);
}

Test(my_fprintf, io_error_signed_int)
{
    char buf[2];
    my_iostream_t stream;

    my_finit_output_memory(buf, 1, &stream);
    cr_assert_lt(my_fprintf(&stream, "%d", 42), 0);
}

Test(my_fprintf, io_error_signed_int_conv_left_padding)
{
    char buf[10];
    my_iostream_t stream;

    my_finit_output_memory(buf, 10, &stream);
    cr_assert_lt(my_fprintf(&stream, "%40d", 42), 0);
}

Test(my_fprintf, io_error_signed_int_conv_zero_padding)
{
    char buf[10];
    my_iostream_t stream;

    my_finit_output_memory(buf, 10, &stream);
    cr_assert_lt(my_fprintf(&stream, "%.40d", 42), 0);
}

Test(my_fprintf, io_error_signed_int_conv_plus_sign)
{
    char buf[10];
    my_iostream_t stream;

    my_finit_output_memory(buf, 2, &stream);
    cr_assert_lt(my_fprintf(&stream, "->%+d", 2), 0);
}

Test(my_fprintf, io_error_signed_int_conv_sign_blank)
{
    char buf[10];
    my_iostream_t stream;

    my_finit_output_memory(buf, 3, &stream);
    cr_assert_lt(my_fprintf(&stream, "->% d", 2), 0);
}

Test(my_fprintf, io_error_signed_int_conv_right_padding)
{
    char buf[10];
    my_iostream_t stream;

    my_finit_output_memory(buf, 10, &stream);
    cr_assert_lt(my_fprintf(&stream, "%-40d", 42), 0);
}

Test(my_fprintf, io_error_unsigned_int)
{
    char buf[2];
    my_iostream_t stream;

    my_finit_output_memory(buf, 1, &stream);
    cr_assert_lt(my_fprintf(&stream, "%u", 42), 0);
}

Test(my_fprintf, io_error_unsigned_int_conv_left_padding)
{
    char buf[10];
    my_iostream_t stream;

    my_finit_output_memory(buf, 10, &stream);
    cr_assert_lt(my_fprintf(&stream, "%40u", 42), 0);
}

Test(my_fprintf, io_error_unsigned_int_conv_zero_padding)
{
    char buf[10];
    my_iostream_t stream;

    my_finit_output_memory(buf, 10, &stream);
    cr_assert_lt(my_fprintf(&stream, "%.40u", 42), 0);
}

Test(my_fprintf, io_error_unsigned_int_conv_prefix)
{
    char buf[2];
    my_iostream_t stream;

    my_finit_output_memory(buf, 1, &stream);
    cr_assert_lt(my_fprintf(&stream, "%#x", 42), 0);
}

Test(my_fprintf, io_error_unsigned_int_conv_right_padding)
{
    char buf[10];
    my_iostream_t stream;

    my_finit_output_memory(buf, 10, &stream);
    cr_assert_lt(my_fprintf(&stream, "%-40u", 42), 0);
}

Test(my_fprintf, io_error_boolean_conv)
{
    char buf[2];
    my_iostream_t stream;

    my_finit_output_memory(buf, 1, &stream);
    cr_assert_lt(my_fprintf(&stream, "%r", 42), 0);
}

Test(my_fprintf, io_error_boolean_conv_left_padding)
{
    char buf[10];
    my_iostream_t stream;

    my_finit_output_memory(buf, 10, &stream);
    cr_assert_lt(my_fprintf(&stream, "%40r", 42), 0);
}

Test(my_fprintf, io_error_boolean_conv_right_padding)
{
    char buf[10];
    my_iostream_t stream;

    my_finit_output_memory(buf, 10, &stream);
    cr_assert_lt(my_fprintf(&stream, "%-40R", 42), 0);
}

Test(my_fprintf, io_error_string_conv_start_quote)
{
    char buf[2];
    my_iostream_t stream;

    my_finit_output_memory(buf, 2, &stream);
    cr_assert_lt(my_fprintf(&stream, "->%#s", "testing"), 0);
}

Test(my_fprintf, io_error_string_conv)
{
    char buf[2];
    my_iostream_t stream;

    my_finit_output_memory(buf, 2, &stream);
    cr_assert_lt(my_fprintf(&stream, "%s", "testing"), 0);
}

Test(my_fprintf, io_error_string_conv_end_quote)
{
    char buf[8];
    my_iostream_t stream;

    my_finit_output_memory(buf, 8, &stream);
    cr_assert_lt(my_fprintf(&stream, "%#s", "testing"), 0);
}

Test(my_fprintf, io_error_octal_string)
{
    char buf[16];
    my_iostream_t stream;

    my_finit_output_memory(buf, 2, &stream);
    cr_assert_lt(my_fprintf(&stream, "$>%S", "\ntest\n"), 0);
    my_finit_output_memory(buf, 2, &stream);
    cr_assert_lt(my_fprintf(&stream, "$%S", "\ntest\n"), 0);
    my_finit_output_memory(buf, 2, &stream);
    cr_assert_lt(my_fprintf(&stream, "%S", "\ntest\n"), 0);
    my_finit_output_memory(buf, 3, &stream);
    cr_assert_lt(my_fprintf(&stream, "%S", "\ntest\n"), 0);
}

Test(my_fprintf, io_error_octal_string_conv_end_quote)
{
    char buf[8];
    my_iostream_t stream;

    my_finit_output_memory(buf, 8, &stream);
    cr_assert_lt(my_fprintf(&stream, "%#S", "testing"), 0);
}

Test(my_fprintf, io_error_string_conv_left_padding)
{
    char buf[10];
    my_iostream_t stream;

    my_finit_output_memory(buf, 10, &stream);
    cr_assert_lt(my_fprintf(&stream, "%40s", "TEST"), 0);
}

Test(my_fprintf, io_error_string_conv_right_padding)
{
    char buf[10];
    my_iostream_t stream;

    my_finit_output_memory(buf, 10, &stream);
    cr_assert_lt(my_fprintf(&stream, "%-40s", "TEST"), 0);
}

Test(my_fprintf, io_error_char_conv)
{
    char buf[4];
    my_iostream_t stream;

    my_finit_output_memory(buf, 3, &stream);
    cr_assert_lt(my_fprintf(&stream, "$> %c", '_'), 0);
}

Test(my_fprintf, io_error_char_conv_left_padding)
{
    char buf[10];
    my_iostream_t stream;

    my_finit_output_memory(buf, 10, &stream);
    cr_assert_lt(my_fprintf(&stream, "%40c", '?'), 0);
}

Test(my_fprintf, io_error_char_conv_right_padding)
{
    char buf[10];
    my_iostream_t stream;

    my_finit_output_memory(buf, 10, &stream);
    cr_assert_lt(my_fprintf(&stream, "%-40c", '@'), 0);
}

Test(my_fprintf, io_error_pointer_conv)
{
    char buf[4];
    my_iostream_t stream;

    my_finit_output_memory(buf, 3, &stream);
    cr_assert_lt(my_fprintf(&stream, "%p", NULL), 0);
}

Test(my_fprintf, io_error_percent_conv)
{
    char buf[2];
    my_iostream_t stream;

    my_finit_output_memory(buf, 1, &stream);
    cr_assert_lt(my_fprintf(&stream, "?%%"), 0);
}
