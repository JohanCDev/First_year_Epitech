/*
** EPITECH PROJECT, 2020
** LibMy - memory module
** File description:
** Tests the my_cbuffer_read_* functions
*/

#include <criterion/criterion.h>
#include "libmy/memory.h"

Test(my_cbuffer_read_front, full_buffer_contiguous)
{
    my_cbuffer_t buf = {"abcdefhij", 10, 10, 0, 0};
    char dst[11] = {0};

    cr_assert_eq(my_cbuffer_read_front(&buf, dst, 10), dst);
    cr_assert_str_eq(dst, "abcdefhij");
    my_memset(dst, '\0', 10);
    cr_assert_eq(my_cbuffer_read_front(&buf, dst, 4), dst);
    cr_assert_str_eq(dst, "abcd");
}

Test(my_cbuffer_read_front, full_buffer_split)
{
    my_cbuffer_t buf = {"hijabcdefg", 10, 10, 3, 3};
    char dst[11] = {0};

    cr_assert_eq(my_cbuffer_read_front(&buf, dst, 10), dst);
    cr_assert_str_eq(dst, "abcdefghij");
    my_memset(dst, '\0', 10);
    cr_assert_eq(my_cbuffer_read_front(&buf, dst, 4), dst);
    cr_assert_str_eq(dst, "abcd");
}

Test(my_cbuffer_read_front, partial_buffer_contiguous)
{
    my_cbuffer_t buf = {"012345abc9", 10, 3, 6, 9};
    char dst[11] = "TestString";

    cr_assert_eq(my_cbuffer_read_front(&buf, dst, 3), dst);
    cr_assert_str_eq(dst, "abctString");
    my_memcpy(dst, "TestString", 10);
    cr_assert_eq(my_cbuffer_read_front(&buf, dst, 1), dst);
    cr_assert_str_eq(dst, "aestString");
}

Test(my_cbuffer_read_front, partial_buffer_split)
{
    my_cbuffer_t buf = {"bc2345678a", 10, 3, 9, 2};
    char dst[11] = "TestString";

    cr_assert_eq(my_cbuffer_read_front(&buf, dst, 3), dst);
    cr_assert_str_eq(dst, "abctString");
    my_memcpy(dst, "TestString", 10);
    cr_assert_eq(my_cbuffer_read_front(&buf, dst, 1), dst);
    cr_assert_str_eq(dst, "aestString");
}

Test(my_cbuffer_read_back, full_buffer_contiguous)
{
    my_cbuffer_t buf = {"abcdefghij", 10, 10, 0, 0};
    char dst[11] = {0};

    cr_assert_eq(my_cbuffer_read_back(&buf, dst, 10), dst);
    cr_assert_str_eq(dst, "abcdefghij");
    my_memset(dst, '\0', 10);
    cr_assert_eq(my_cbuffer_read_back(&buf, dst, 4), dst);
    cr_assert_str_eq(dst, "ghij");
}

Test(my_cbuffer_read_back, full_buffer_split)
{
    my_cbuffer_t buf = {"hijabcdefg", 10, 10, 3, 3};
    char dst[11] = {0};

    cr_assert_eq(my_cbuffer_read_back(&buf, dst, 10), dst);
    cr_assert_str_eq(dst, "abcdefghij");
    my_memset(dst, '\0', 10);
    cr_assert_eq(my_cbuffer_read_back(&buf, dst, 4), dst);
    cr_assert_str_eq(dst, "ghij");
}

Test(my_cbuffer_read_back, partial_buffer_contiguous)
{
    my_cbuffer_t buf = {"012345abc9", 10, 3, 6, 9};
    char dst[11] = "TestString";

    cr_assert_eq(my_cbuffer_read_back(&buf, dst, 3), dst);
    cr_assert_str_eq(dst, "abctString");
    my_memcpy(dst, "TestString", 10);
    cr_assert_eq(my_cbuffer_read_back(&buf, dst, 1), dst);
    cr_assert_str_eq(dst, "cestString");
}

Test(my_cbuffer_read_back, partial_buffer_split)
{
    my_cbuffer_t buf = {"bc2345678a", 10, 3, 9, 2};
    char dst[11] = "TestString";

    cr_assert_eq(my_cbuffer_read_back(&buf, dst, 3), dst);
    cr_assert_str_eq(dst, "abctString");
    my_memcpy(dst, "TestString", 10);
    cr_assert_eq(my_cbuffer_read_back(&buf, dst, 1), dst);
    cr_assert_str_eq(dst, "cestString");
}

Test(my_cbuffer_read_at, contigous_read)
{
    my_cbuffer_t buf1 = {"abcdefghij", 10, 10, 0, 0};
    my_cbuffer_t buf2 = {"hiXabcdefg", 10, 9, 3, 2};
    char dst[5] = "TEST\0";

    cr_assert_eq(my_cbuffer_read_at(&buf1, dst, 4, 3), dst);
    cr_assert_str_eq(dst, "defg");
    my_memcpy(dst, "TEST", 5);
    cr_assert_eq(my_cbuffer_read_at(&buf2, dst, 4, 3), dst);
    cr_assert_str_eq(dst, "defg");
}

Test(my_cbuffer_read_at, split_read)
{
    my_cbuffer_t buf1 = {"abcdefghij", 10, 10, 0, 0};
    my_cbuffer_t buf2 = {"ijabcdefgh", 10, 10, 2, 2};
    char dst[5] = "TEST\0";

    cr_assert_eq(my_cbuffer_read_at(&buf1, dst, 4, 8), dst);
    cr_assert_str_eq(dst, "ijab");
    my_memcpy(dst, "TEST", 5);
    cr_assert_eq(my_cbuffer_read_at(&buf2, dst, 4, 8), dst);
    cr_assert_str_eq(dst, "ijab");
}