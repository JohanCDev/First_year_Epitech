/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_memset function
*/

#include <criterion/criterion.h>
#include "libmy/memory.h"

Test(my_memset, null_mem)
{
    cr_assert_eq(my_memset(NULL, 42, 78), NULL);
}

Test(my_memset, zero_size)
{
    char buf[] = "This is a buffer.\0";

    cr_assert_eq(my_memset(buf, 42, 0), buf);
    cr_assert_str_eq(buf, "This is a buffer.");
}

Test(my_memset, normal_fill)
{
    char buf[] = "This is a buffer.\0";

    cr_assert_eq(my_memset(buf, '.', 4), buf);
    cr_assert_str_eq(buf, ".... is a buffer.");
}
