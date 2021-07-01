/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_fputuintmax_t_base function
*/

#include <criterion/criterion.h>
#include "libmy/io.h"

Test(my_fputuintmax_t_base, binary)
{
    uintmax_t nb = 0x4a;
    char const *base = "01";
    char buf[64];
    my_iostream_t stream;
    size_t written = 42;

    my_finit_output_memory(buf, 64, &stream);
    cr_assert_eq(my_fputuintmax_t_base(nb, base, 2, &stream), 7);
    my_fget_buffer(&written, &stream);
    cr_assert_eq(written, 7);
    buf[written] = '\0';
    cr_assert_str_eq(buf, "1001010");
}

Test(my_fputuintmax_t_base, octal)
{
    uintmax_t nb = 0744;
    char const *base = "01234567";
    char buf[64];
    my_iostream_t stream;
    size_t written = 42;

    my_finit_output_memory(buf, 64, &stream);
    cr_assert_eq(my_fputuintmax_t_base(nb, base, 8, &stream), 3);
    my_fget_buffer(&written, &stream);
    cr_assert_eq(written, 3);
    buf[written] = '\0';
    cr_assert_str_eq(buf, "744");
}

Test(my_fputuintmax_t_base, hexadecimal)
{
    uintmax_t nb = 0xAB01CD23;
    char const *base = "0123456789ABCDEF";
    char buf[64];
    my_iostream_t stream;
    size_t written = 42;

    my_finit_output_memory(buf, 64, &stream);
    cr_assert_eq(my_fputuintmax_t_base(nb, base, 16, &stream), 8);
    my_fget_buffer(&written, &stream);
    cr_assert_eq(written, 8);
    buf[written] = '\0';
    cr_assert_str_eq(buf, "AB01CD23");
}
