/*
** EPITECH PROJECT, 2020
** Libmy unit tests
** File description:
** Tests the my_fclose function
*/

#include <limits.h>
#include <criterion/criterion.h>
#include "libmy/io.h"

Test(my_fclose, memory_stream)
{
    my_iostream_t stream;

    cr_assert_eq(my_finit_input_memory("test", 4, &stream), 0);
    cr_assert_eq(my_fclose(&stream), 0);
}
