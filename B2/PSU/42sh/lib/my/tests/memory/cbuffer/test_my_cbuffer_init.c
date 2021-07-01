/*
** EPITECH PROJECT, 2020
** LibMy - memory module
** File description:
** Tests the my_cbuffer_init function
*/

#include <criterion/criterion.h>
#include "libmy/memory.h"

Test(my_cbuffer_init, normal)
{
    char *mem = "test";
    my_cbuffer_t buf;

    my_cbuffer_init(&buf, mem, 4);
    cr_assert_eq(buf.data, mem);
    cr_assert_eq(buf.cap, 4);
    cr_assert_eq(buf.len, 0);
    cr_assert_eq(buf.tail, 0);
    cr_assert_eq(buf.head, 0);
}
