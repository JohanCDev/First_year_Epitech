/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_memdup function
*/

#include <stdlib.h>
#include <criterion/criterion.h>

#include "libmy/memory/alloc.h"

Test(my_memdup, zero_size)
{
    cr_assert_eq(my_memdup("This is a test", 0), NULL);
}

Test(my_memdup, alloc_error)
{
    cr_assert_eq(my_memdup("MEM", SIZE_MAX), NULL);
}

Test(my_memdup, normal)
{
    char const *to_dup = "Duplicate Me!";
    char *dup = my_memdup(to_dup, 14);

    cr_assert_str_eq(dup, to_dup);
    free(dup);
}
