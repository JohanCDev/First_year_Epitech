/*
** EPITECH PROJECT, 2020
** LibMy
** File description:
** Tests the my_swap_ptr function
*/

#include <criterion/criterion.h>
#include "libmy/memory.h"

Test(my_swap_ptr, base)
{
    char *a = "This is a test";
    char *b = "Bob";

    my_swap_ptr((const void **)&a, (const void **)&b);
    cr_assert_str_eq(a, "Bob");
    cr_assert_str_eq(b, "This is a test");
}
