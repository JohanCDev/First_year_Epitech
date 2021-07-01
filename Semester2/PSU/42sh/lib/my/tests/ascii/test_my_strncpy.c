/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_strncpy function
*/

#include <criterion/criterion.h>
#include <string.h>
#include "libmy/ascii.h"

Test(my_strncpy, null_strings)
{
    my_strncpy(NULL, NULL, 10);
}

Test(my_strncpy, null_src_string)
{
    char dest[42];

    my_strncpy(NULL, dest, 10);
}

Test(my_strncpy, null_dest_string)
{
    my_strncpy("This is a test", NULL, 10);
}

Test(my_strncpy, normal_buffer_normal_n)
{
    char *src = "test";
    char dest[5];
    int result;

    my_strncpy(dest, src, 5);
    result = memcmp(dest, "test", 5);
    cr_assert(result == 0, "got %d", result);
}

Test(my_strncpy, normal_buffer_small_n)
{
    char *src = "test";
    char dest[5];
    int result;

    my_strncpy(dest, src, 3);
    result = memcmp(dest, "tes", 3);
    cr_assert(result == 0, "got %d", result);
}

Test(my_strncpy, small_buffer_small_n)
{
    char *src = "test";
    char dest[3];
    int result;

    my_strncpy(dest, src, 3);
    result = memcmp(dest, "tes", 3);
    cr_assert(result == 0, "got %d", result);
}

Test(my_strncpy, bigger_buffer_normal_n)
{
    char *src = "test";
    char dest[10];
    int result;

    my_strncpy(dest, src, 5);
    result = memcmp(dest, "test\0", 5);
    cr_assert(result == 0, "got %d", result);
}

Test(my_strncpy, bigger_buffer_small_n)
{
    char *src = "test";
    char dest[10];
    int result;

    my_strncpy(dest, src, 2);
    result = memcmp(dest, "te", 2);
    cr_assert(result == 0, "got %d", result);
}

Test(my_strncpy, bigger_buffer_big_n)
{
    char *src = "test";
    char dest[10];
    int result;

    my_strncpy(dest, src, 10);
    result = memcmp(dest, "test\0\0\0\0\0\0", 10);
    cr_assert(result == 0, "got %d", result);
}
