/*
** EPITECH PROJECT, 2020
** LibMy - memory module
** File description:
** Tests the my_cbuffer_rotate_* functions
*/

#include <criterion/criterion.h>
#include "libmy/memory.h"

Test(my_u16_to_le, base)
{
    my_u16_t to_convert = 0xABCD;
    my_m16_t converted = {.num = my_u16_to_le(to_convert)};

    cr_assert_eq(converted.data[0], 0xCD);
    cr_assert_eq(converted.data[1], 0xAB);
}

Test(my_u16_to_be, base)
{
    my_u16_t to_convert = 0xABCD;
    my_m16_t converted = {.num = my_u16_to_be(to_convert)};

    cr_assert_eq(converted.data[0], 0xAB);
    cr_assert_eq(converted.data[1], 0xCD);
}

Test(my_u32_to_le, base)
{
    my_u32_t to_convert = 0xABCD1234;
    my_m32_t converted = {.num = my_u32_to_le(to_convert)};

    cr_assert_eq(converted.data[0], 0x34);
    cr_assert_eq(converted.data[1], 0x12);
    cr_assert_eq(converted.data[2], 0xCD);
    cr_assert_eq(converted.data[3], 0xAB);
}

Test(my_u32_to_be, base)
{
    my_u32_t to_convert = 0xABCD1234;
    my_m32_t converted = {.num = my_u32_to_be(to_convert)};

    cr_assert_eq(converted.data[0], 0xAB);
    cr_assert_eq(converted.data[1], 0xCD);
    cr_assert_eq(converted.data[2], 0x12);
    cr_assert_eq(converted.data[3], 0x34);
}

Test(my_u64_to_le, base)
{
    my_u64_t to_convert = 0xABCDEF0123456789;
    my_m64_t converted = {.num = my_u64_to_le(to_convert)};

    cr_assert_eq(converted.data[0], 0x89);
    cr_assert_eq(converted.data[1], 0x67);
    cr_assert_eq(converted.data[2], 0x45);
    cr_assert_eq(converted.data[3], 0x23);
    cr_assert_eq(converted.data[4], 0x01);
    cr_assert_eq(converted.data[5], 0xEF);
    cr_assert_eq(converted.data[6], 0xCD);
    cr_assert_eq(converted.data[7], 0xAB);
}

Test(my_u64_to_be, base)
{
    my_u64_t to_convert = 0xABCDEF0123456789;
    my_m64_t converted = {.num = my_u64_to_be(to_convert)};

    cr_assert_eq(converted.data[0], 0xAB);
    cr_assert_eq(converted.data[1], 0xCD);
    cr_assert_eq(converted.data[2], 0xEF);
    cr_assert_eq(converted.data[3], 0x01);
    cr_assert_eq(converted.data[4], 0x23);
    cr_assert_eq(converted.data[5], 0x45);
    cr_assert_eq(converted.data[6], 0x67);
    cr_assert_eq(converted.data[7], 0x89);
}
