/*
** EPITECH PROJECT, 2021
** LibMy unit tests
** File description:
** Tests the my_str_csplit_iter function
*/

#include <criterion/criterion.h>
#include "libmy/ascii.h"

Test(my_str_csplit_iter, empty_str)
{
    char const *str = "";
    char const *begin = str;
    char const *end = NULL;

    cr_assert_eq(my_str_csplit_iter(&begin, &end, 'x'), 0);
    cr_assert_eq(begin, str);
    cr_assert_eq(end, begin);
    cr_assert_eq(my_str_csplit_iter(&begin, &end, 'x'), -1);
    cr_assert_eq(begin, NULL);
    cr_assert_eq(end, NULL);
    cr_assert_eq(my_str_csplit_iter(&begin, &end, 'x'), -1);
    cr_assert_eq(begin, NULL);
    cr_assert_eq(end, NULL);
}

Test(my_str_csplit_iter, no_separator)
{
    char const *str = "This is a test";
    char const *begin = str;
    char const *end = NULL;

    cr_assert_eq(my_str_csplit_iter(&begin, &end, 'x'), 14);
    cr_assert_eq(begin, str);
    cr_assert_eq(end, begin + 14);
    cr_assert_eq(my_str_csplit_iter(&begin, &end, 'x'), -1);
    cr_assert_eq(begin, NULL);
    cr_assert_eq(end, NULL);
    cr_assert_eq(my_str_csplit_iter(&begin, &end, 'x'), -1);
    cr_assert_eq(begin, NULL);
    cr_assert_eq(end, NULL);
}

Test(my_str_csplit_iter, normal)
{
    char const *str = "xbox is a conxxole";
    char const *begin = str;
    char const *end = NULL;

    cr_assert_eq(my_str_csplit_iter(&begin, &end, 'x'), 0);
    cr_assert_eq(begin, str);
    cr_assert_eq(end, begin);
    cr_assert_eq(my_str_csplit_iter(&begin, &end, 'x'), 2);
    cr_assert_eq(begin, str + 1);
    cr_assert_eq(end, str + 3);
    cr_assert_eq(my_str_csplit_iter(&begin, &end, 'x'), 9);
    cr_assert_eq(begin, str + 4);
    cr_assert_eq(end, str + 13);
    cr_assert_eq(my_str_csplit_iter(&begin, &end, 'x'), 0);
    cr_assert_eq(begin, str + 14);
    cr_assert_eq(end, str + 14);
    cr_assert_eq(my_str_csplit_iter(&begin, &end, 'x'), 3);
    cr_assert_eq(begin, str + 15);
    cr_assert_eq(end, str + 18);
    cr_assert_eq(my_str_csplit_iter(&begin, &end, 'x'), -1);
}
