/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_memcpy function
*/

#include <criterion/criterion.h>
#include "libmy/memory.h"

Test(my_memcpy, null_dest)
{
    cr_assert_eq(my_memcpy(NULL, "test", 5), NULL);
}

Test(my_memcpy, null_src)
{
    char dest[5];

    cr_assert_eq(my_memcpy(dest, NULL, 5), NULL);
}

Test(my_memcpy, normal_copy)
{
    char dest[5];

    cr_assert_eq(my_memcpy(dest, "test", 5), dest);
    cr_assert_str_eq(dest, "test");
}
