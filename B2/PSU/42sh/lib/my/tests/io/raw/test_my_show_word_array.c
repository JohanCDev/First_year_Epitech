/*
** EPITECH PROJECT, 2020
** LibMy unit tests
** File description:
** Tests the my_show_word_array function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "libmy/io.h"

static void redirect_all_output(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_show_word_array, null_tab)
{
    cr_assert_eq(my_show_word_array(NULL), -1);
}

Test(my_show_word_array, empty_tab)
{
    char *tab[] = { NULL };

    cr_assert_eq(my_show_word_array(tab), 0);
}

Test(my_show_word_array, one_str_tab, .init=redirect_all_output)
{
    char *tab[] = { "test.", NULL };

    cr_assert_eq(my_show_word_array(tab), 0);
    cr_assert_stdout_eq_str("test.\n", "");
}

Test(my_show_word_array, multi_str_tab, .init=redirect_all_output)
{
    char *tab[] = { "This", "is", "a", "test.", NULL };

    cr_assert_eq(my_show_word_array(tab), 0);
    cr_assert_stdout_eq_str("This\nis\na\ntest.\n", "");
}
