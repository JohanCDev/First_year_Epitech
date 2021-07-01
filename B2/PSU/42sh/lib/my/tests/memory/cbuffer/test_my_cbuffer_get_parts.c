/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_cbuffer_get_*_part functions
*/

#include <criterion/criterion.h>
#include "libmy/memory.h"

Test(my_cbuffer_get_first_part, contiguous_with_size)
{
    char *mem = "This is a test";
    my_cbuffer_t buf = { mem, 14, 7, 0, 7 };
    size_t size;

    cr_assert_eq(my_cbuffer_get_first_part(&buf, &size), mem);
    cr_assert_eq(size, 7);
}

Test(my_cbuffer_get_first_part, contiguous_empty)
{
    char *mem = "This is a test";
    my_cbuffer_t buf = { mem, 14, 0, 7, 7 };
    size_t size;

    cr_assert_eq(my_cbuffer_get_first_part(&buf, &size), mem + 7);
    cr_assert_eq(size, 0);
}

Test(my_cbuffer_get_first_part, contiguous_no_size)
{
    char *mem = "This is a test";
    my_cbuffer_t buf = { mem, 14, 4, 10, 14 };

    cr_assert_eq(my_cbuffer_get_first_part(&buf, NULL), mem + 10);
}

Test(my_cbuffer_get_first_part, split_with_size_whole_mem)
{
    char *mem = " is a testThis";
    my_cbuffer_t buf = { mem, 14, 14, 10, 10 };
    size_t size;

    cr_assert_eq(my_cbuffer_get_first_part(&buf, &size), mem + 10);
    cr_assert_eq(size, 4);
}

Test(my_cbuffer_get_first_part, split_with_size)
{
    char *mem = "This is a test";
    my_cbuffer_t buf = { mem, 14, 4, 10, 4 };
    size_t size;

    cr_assert_eq(my_cbuffer_get_first_part(&buf, &size), mem + 10);
    cr_assert_eq(size, 4);
}

Test(my_cbuffer_get_first_part, split_no_size)
{
    char *mem = "This is a test";
    my_cbuffer_t buf = { mem, 14, 4, 10, 4 };

    cr_assert_eq(my_cbuffer_get_first_part(&buf, NULL), mem + 10);
}

Test(my_cbuffer_get_second_part, contiguous_with_size)
{
    char *mem = "This is a test";
    my_cbuffer_t buf = { mem, 14, 7, 0, 7 };
    size_t size;

    cr_assert_eq(my_cbuffer_get_second_part(&buf, &size), mem + 7);
    cr_assert_eq(size, 0);
}

Test(my_cbuffer_get_second_part, contiguous_empty)
{
    char *mem = "This is a test";
    my_cbuffer_t buf = { mem, 14, 0, 7, 7 };
    size_t size;

    cr_assert_eq(my_cbuffer_get_second_part(&buf, &size), mem + 7);
    cr_assert_eq(size, 0);
}

Test(my_cbuffer_get_second_part, contiguous_no_size)
{
    char *mem = "This is a test";
    my_cbuffer_t buf = { mem, 14, 4, 10, 14 };

    cr_assert_eq(my_cbuffer_get_second_part(&buf, NULL), mem + 14);
}

Test(my_cbuffer_get_second_part, split_with_size_whole_buffer)
{
    char *mem = "This is a test";
    my_cbuffer_t buf = { mem, 14, 14, 10, 10 };
    size_t size;

    cr_assert_eq(my_cbuffer_get_second_part(&buf, &size), mem);
    cr_assert_eq(size, 10);
}

Test(my_cbuffer_get_second_part, split_with_size)
{
    char *mem = "This is a test";
    my_cbuffer_t buf = { mem, 14, 4, 10, 4 };
    size_t size;

    cr_assert_eq(my_cbuffer_get_second_part(&buf, &size), mem);
    cr_assert_eq(size, 4);
}

Test(my_cbuffer_get_second_part, split_no_size)
{
    char *mem = "This is a test";
    my_cbuffer_t buf = { mem, 14, 4, 10, 4 };

    cr_assert_eq(my_cbuffer_get_second_part(&buf, NULL), mem);
}
