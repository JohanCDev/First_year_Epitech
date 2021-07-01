/*
** EPITECH PROJECT, 2021
** LibMy unit tests
** File description:
** Tests the my_memrev function
*/

#include <criterion/criterion.h>
#include "libmy/memory/memory.h"

Test(my_memrev, byte_size)
{
    char data[] = "This is a test";

    my_memrev(data, 14, sizeof(char));
    cr_assert_str_eq("tset a si sihT", data);
}

Test(my_memrev, int_array)
{
    int data[] = {1, -42, 7, 8, 65761, -771};

    my_memrev(data, 6, sizeof(int));
    cr_assert_eq(-771, data[0]);
    cr_assert_eq(65761, data[1]);
    cr_assert_eq(8, data[2]);
    cr_assert_eq(7, data[3]);
    cr_assert_eq(-42, data[4]);
    cr_assert_eq(1, data[5]);
}
