/*
** EPITECH PROJECT, 2020
** test_my_str_islower
** File description:
**
*/

#include <criterion/criterion.h>

int *my_str_islower(char const *str);

Test(my_str_islower, is_a_string_only_lowercase)
{
    cr_assert_eq(my_str_islower("h"), 1);
    cr_assert_eq(my_str_islower("H"), 0);
    cr_assert_eq(my_str_islower(""), 0);
    cr_assert_eq(my_str_islower("5"), 0);
    cr_assert_eq(my_str_islower("{"), 0);
}
