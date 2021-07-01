/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_snprintf function
*/

#include <criterion/criterion.h>
#include "libmy/printf.h"

Test(my_snprintf, big_buffer)
{
    char buf[64];

    cr_assert_eq(my_snprintf(buf, 64, "%s", "Test"), 4);
    cr_assert_str_eq(buf, "Test");
}

Test(my_snprintf, perfect_sized_buffer)
{
    char buf[5];

    cr_assert_eq(my_snprintf(buf, 5, "%s", "Test"), 4);
    cr_assert_str_eq(buf, "Test");
}

Test(my_snprintf, small_buffer)
{
    char buf[2];

    cr_assert_eq(my_snprintf(buf, 2, "%s", "Test"), 4);
    cr_assert_str_eq(buf, "T");
}
