/*
** EPITECH PROJECT, 2020
** Libmy unit tests
** File description:
** Tests the my_fclose function (with close syscall allowed)
*/

#include <limits.h>
#include <criterion/criterion.h>
#include "libmy/io.h"

Test(my_fclose, unix_invalid_fd)
{
    my_iostream_t stream;

    cr_assert_eq(my_finit_output_fd(INT_MAX, &stream), 0);
    cr_assert_neq(my_fclose(&stream), 0);
}

Test(my_fclose, unix_valid_fd)
{
    my_iostream_t stream;

    cr_assert_eq(my_finit_output_fd(2, &stream), 0);
    cr_assert_eq(my_fclose(&stream), 0);
}
