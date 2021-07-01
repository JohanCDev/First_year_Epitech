/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_memmove function
*/

#include <criterion/criterion.h>
#include "libmy/memory.h"

Test(my_memmove, null_dest)
{
    cr_assert_eq(my_memmove(NULL, "test", 5), NULL);
}

Test(my_memmove, null_src)
{
    char dest[5];

    cr_assert_eq(my_memmove(dest, NULL, 5), NULL);
}

Test(my_memmove, same_pointers)
{
    char *str = "This is a test";

    cr_assert_eq(my_memmove(str, str, 14), str);
}

Test(my_memmove, no_copy)
{
    char *src = "source";
    char dst[] = "destination";

    cr_assert_eq(my_memmove(dst, src, 0), dst);
}

Test(my_memmove, normal_copy)
{
    char dest[5];

    cr_assert_eq(my_memmove(dest, "test", 5), dest);
    cr_assert_str_eq(dest, "test");
}

Test(my_memmove, overlapping_dst_before_src)
{
    char mem[] = "[--test]";
    char *dst = mem + 1;
    char *src = mem + 3;

    cr_assert_eq(my_memmove(dst, src, 4), dst);
    cr_assert_str_eq(mem, "[testst]");
}

Test(my_memmove, overlapping_dst_after_src)
{
    char mem[] = "[test--]";
    char *dst = mem + 3;
    char *src = mem + 1;

    cr_assert_eq(my_memmove(dst, src, 4), dst);
    cr_assert_str_eq(mem, "[tetest]");
}
