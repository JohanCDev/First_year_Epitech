/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_msort function
*/

#include <criterion/criterion.h>
#include <limits.h>
#include "libmy/memory.h"

static int comparator(void const *a, void const *b)
{
    return *(int *)a - *(int *)b;
}

Test(my_msort, zero)
{
    int data[3] = { 3, 1, 2 };
    int work[3];
    void *param[2] = { data, work };

    my_msort(param, 0, sizeof(int), &comparator);
    cr_assert_eq(data[0], 3);
    cr_assert_eq(data[1], 1);
    cr_assert_eq(data[2], 2);
}

Test(my_msort, one)
{
    int data[3] = { 3, 1, 2 };
    int work[3];
    void *param[2] = { data, work };

    my_msort(param, 1, sizeof(int), &comparator);
    cr_assert_eq(data[0], 3);
    cr_assert_eq(data[1], 1);
    cr_assert_eq(data[2], 2);
}

Test(my_msort, three)
{
    int data[3] = { 3, 1, 2 };
    int work[3];
    void *param[2] = { data, work };

    my_msort(param, 3, sizeof(int), &comparator);
    cr_assert_eq(data[0], 1);
    cr_assert_eq(data[1], 2);
    cr_assert_eq(data[2], 3);
}

Test(my_msort, big_list)
{
    int data[13] = { 89, -49, 55, 61, -32, -3, -24, -72, -100, 17, 45, 33, 59 };
    int work[13];
    void *param[2] = { data, work };

    my_msort(param, 13, sizeof(int), &comparator);
    cr_assert_eq(data[0], -100);
    cr_assert_eq(data[1], -72);
    cr_assert_eq(data[2], -49);
    cr_assert_eq(data[3], -32);
    cr_assert_eq(data[4], -24);
    cr_assert_eq(data[5], -3);
    cr_assert_eq(data[6], 17);
    cr_assert_eq(data[7], 33);
    cr_assert_eq(data[8], 45);
    cr_assert_eq(data[9], 55);
    cr_assert_eq(data[10], 59);
    cr_assert_eq(data[11], 61);
    cr_assert_eq(data[12], 89);
}
