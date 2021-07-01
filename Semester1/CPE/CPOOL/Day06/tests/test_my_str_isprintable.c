/*
** EPITECH PROJECT, 2020             
** test_my_str_islower
** File description:
**
*/

#include <criterion/criterion.h>

int *my_str_isprintable(char const *str);

Test(my_str_isprintable, is_a_string_only_printable)
{
    cr_assert_eq(my_str_isprintable("a"), 1);
    cr_assert_eq(my_str_isprintable(""), 0);
    cr_assert_eq(my_str_isprintable("\n"), 0);
    cr_assert_eq(my_str_isprintable("a\n"), 0);
}
