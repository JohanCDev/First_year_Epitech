/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_realloc function
*/

#include <criterion/criterion.h>
#include "libmy/memory.h"

Test(my_realloc, null_ptr)
{
    cr_assert_neq(my_realloc(NULL, 12, 69), NULL);
}

Test(my_realloc, zero_size_free)
{
    char *str = strdup("test");

    cr_assert_eq(my_realloc(str, 5, 0), NULL);
}

Test(my_realloc, same_size)
{
    char *str = strdup("This is a test");

    cr_assert_eq(my_realloc(str, 15, 15), str);
}

Test(my_realloc, growing)
{
    char *src = "This is a";
    char *str = strdup(src);
    char *rea;

    rea = my_realloc(str, 10, 15);
    cr_assert_neq(str, rea);
    cr_assert_str_eq(rea, src);
    strcpy(rea, "This is a test");
    cr_assert_str_eq(rea, "This is a test");
}

Test(my_realloc, shrinking)
{
    char *str = strdup("This is a test");
    char *rea;

    rea = my_realloc(str, 15, 10);
    cr_assert_neq(str, rea);
    rea[9] = 0;
    cr_assert_str_eq(rea, "This is a");
}
