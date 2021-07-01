/*
** EPITECH PROJECT, 2020
** LibMy - memory module
** File description:
** Tests the my_cbuffer_push function
*/

#include <criterion/criterion.h>
#include "libmy/memory.h"

Test(my_cbuffer_push_front, empty_buf)
{
    char data[11] = "ABCDEFGHIJ";
    my_cbuffer_t buf = {data, 10, 0, 0, 0};

    my_cbuffer_push_front(&buf, "test", 4);
    cr_assert_str_eq(data, "ABCDEFtest");
    cr_assert_eq(buf.cap, 10);
    cr_assert_eq(buf.len, 4);
    cr_assert_eq(buf.tail, 6);
    cr_assert_eq(buf.head, 0);
}

Test(my_cbuffer_push_front, contiguous_to_contiguous)
{
    char data[11] = "ABCDefgHIJ";
    my_cbuffer_t buf = {data, 10, 3, 4, 7};

    my_cbuffer_push_front(&buf, "test", 4);
    cr_assert_str_eq(data, "testefgHIJ");
    cr_assert_eq(buf.cap, 10);
    cr_assert_eq(buf.len, 7);
    cr_assert_eq(buf.tail, 0);
    cr_assert_eq(buf.head, 7);
}

Test(my_cbuffer_push_front, contiguous_to_split)
{
    char data[11] = "ABCdefgHIJ";
    my_cbuffer_t buf = {data, 10, 4, 3, 7};

    my_cbuffer_push_front(&buf, "test", 4);
    cr_assert_str_eq(data, "estdefgHIt");
    cr_assert_eq(buf.cap, 10);
    cr_assert_eq(buf.len, 8);
    cr_assert_eq(buf.tail, 9);
    cr_assert_eq(buf.head, 7);
}

Test(my_cbuffer_push_front, split_to_split)
{
    char data[11] = "abCDEFGHij";
    my_cbuffer_t buf = {data, 10, 4, 8, 2};

    my_cbuffer_push_front(&buf, "test", 4);
    cr_assert_str_eq(data, "abCDtestij");
    cr_assert_eq(buf.cap, 10);
    cr_assert_eq(buf.len, 8);
    cr_assert_eq(buf.tail, 4);
    cr_assert_eq(buf.head, 2);
}

Test(my_cbuffer_push_back, empty_buf)
{
    char data[11] = "ABCDEFGHIJ";
    my_cbuffer_t buf = {data, 10, 0, 0, 0};

    my_cbuffer_push_back(&buf, "test", 4);
    cr_assert_str_eq(data, "testEFGHIJ");
    cr_assert_eq(buf.cap, 10);
    cr_assert_eq(buf.len, 4);
    cr_assert_eq(buf.tail, 0);
    cr_assert_eq(buf.head, 4);
}

Test(my_cbuffer_push_back, contiguous_to_contiguous)
{
    char data[11] = "ABcdefGHIJ";
    my_cbuffer_t buf = {data, 10, 4, 2, 6};

    my_cbuffer_push_back(&buf, "test", 4);
    cr_assert_str_eq(data, "ABcdeftest");
    cr_assert_eq(buf.cap, 10);
    cr_assert_eq(buf.len, 8);
    cr_assert_eq(buf.tail, 2);
    cr_assert_eq(buf.head, 0);
}

Test(my_cbuffer_push_back, contiguous_to_split)
{
    char data[11] = "ABCDefgHIJ";
    my_cbuffer_t buf = {data, 10, 3, 4, 7};

    my_cbuffer_push_back(&buf, "test", 4);
    cr_assert_str_eq(data, "tBCDefgtes");
    cr_assert_eq(buf.cap, 10);
    cr_assert_eq(buf.len, 7);
    cr_assert_eq(buf.tail, 4);
    cr_assert_eq(buf.head, 1);
}

Test(my_cbuffer_push_back, split_to_split)
{
    char data[11] = "abCDEFGHij";
    my_cbuffer_t buf = {data, 10, 4, 8, 2};

    my_cbuffer_push_back(&buf, "test", 4);
    cr_assert_str_eq(data, "abtestGHij");
    cr_assert_eq(buf.cap, 10);
    cr_assert_eq(buf.len, 8);
    cr_assert_eq(buf.tail, 8);
    cr_assert_eq(buf.head, 6);
}
