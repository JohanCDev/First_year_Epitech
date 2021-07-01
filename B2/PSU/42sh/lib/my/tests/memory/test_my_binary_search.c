/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_binary_search function
*/

#include <stdint.h>
#include <string.h>
#include <criterion/criterion.h>
#include "libmy/memory.h"

static int entry_cmp(char *a, char **b)
{
    return strcmp(a, *b);
}

Test(my_binary_search, null_array)
{
    my_array_t array = {NULL, 32, sizeof(char *)};

    cr_assert_eq(my_binary_search(&array, "yeet", &entry_cmp), SIZE_MAX);
}

Test(my_binary_search, zero_len)
{
    char *data[] = {"yeet", "bob", "foo"};
    my_array_t array = {data, 0, sizeof(char *)};

    cr_assert_eq(my_binary_search(&array, "yeet", &entry_cmp), SIZE_MAX);
}

Test(my_binary_search, null_cmp)
{
    char *data[] = {"yeet", "bob", "foo"};
    my_array_t array = {data, 0, sizeof(char *)};

    cr_assert_eq(my_binary_search(&array, "yeet", NULL), SIZE_MAX);
}

Test(my_binary_search, not_found_before_start)
{
    char *data[] = {"bob", "foo", "yeet"};
    my_array_t array = {data, 3, sizeof(char *)};

    cr_assert_eq(my_binary_search(&array, "abc", &entry_cmp), SIZE_MAX);
}

Test(my_binary_search, not_found_after_end)
{
    char *data[] = {"bob", "foo", "yeet"};
    my_array_t array = {data, 3, sizeof(char *)};

    cr_assert_eq(my_binary_search(&array, "zzz", &entry_cmp), SIZE_MAX);
}

Test(my_binary_search, one_elem)
{
    char *data[] = {"yeet"};
    my_array_t array = {data, 1, sizeof(char *)};

    cr_assert_eq(my_binary_search(&array, "yeet", &entry_cmp), 0);
}

Test(my_binary_search, three_elems_find_begin)
{
    char *data[] = {"bob", "foo", "yeet"};
    my_array_t array = {data, 3, sizeof(char *)};

    cr_assert_eq(my_binary_search(&array, "bob", &entry_cmp), 0);
}

Test(my_binary_search, three_elems_find_middle)
{
    char *data[] = {"bob", "foo", "yeet"};
    my_array_t array = {data, 3, sizeof(char *)};

    cr_assert_eq(my_binary_search(&array, "foo", &entry_cmp), 1);
}

Test(my_binary_search, three_elems_find_end)
{
    char *data[] = {"bob", "foo", "yeet"};
    my_array_t array = {data, 3, sizeof(char *)};

    cr_assert_eq(my_binary_search(&array, "yeet", &entry_cmp), 2);
}

Test(my_binary_search, six_elems_find_begin)
{
    char *data[] = {"abc", "bar", "bob", "foo", "yeet", "zebra"};
    my_array_t array = {data, 6, sizeof(char *)};

    cr_assert_eq(my_binary_search(&array, "abc", &entry_cmp), 0);
}

Test(my_binary_search, six_elems_find_middle)
{
    char *data[] = {"abc", "bar", "bob", "foo", "yeet", "zebra"};
    my_array_t array = {data, 6, sizeof(char *)};

    cr_assert_eq(my_binary_search(&array, "bob", &entry_cmp), 2);
}

Test(my_binary_search, six_elems_find_end)
{
    char *data[] = {"abc", "bar", "bob", "foo", "yeet", "zebra"};
    my_array_t array = {data, 6, sizeof(char *)};

    cr_assert_eq(my_binary_search(&array, "zebra", &entry_cmp), 5);
}
