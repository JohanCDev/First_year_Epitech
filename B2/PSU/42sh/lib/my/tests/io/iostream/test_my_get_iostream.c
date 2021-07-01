/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_get_std* functions
*/

#include <criterion/criterion.h>
#include "libmy/io.h"

Test(my_get_stdin, base)
{
    cr_assert_neq(my_get_stdin(), NULL);
    cr_assert_neq(MY_STDIN, NULL);
}

Test(my_get_stdout, base)
{
    cr_assert_neq(my_get_stdout(), NULL);
    cr_assert_neq(MY_STDOUT, NULL);
}

Test(my_get_stderr, base)
{
    cr_assert_neq(my_get_stderr(), NULL);
    cr_assert_neq(MY_STDERR, NULL);
}

Test(my_get_void_input, base)
{
    my_iostream_t *void_input = MY_VOID_IN;

    cr_assert_neq(my_get_void_input(), NULL);
    cr_assert_neq(MY_VOID_IN, NULL);
    cr_assert_eq(void_input->vtable->write, NULL);
}

Test(my_get_void_output, base)
{
    my_iostream_t *void_output = MY_VOID_OUT;

    cr_assert_neq(my_get_void_output(), NULL);
    cr_assert_neq(MY_VOID_OUT, NULL);
    cr_assert_eq(void_output->vtable->read, NULL);
}
