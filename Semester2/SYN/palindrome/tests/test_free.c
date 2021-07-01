/*
** EPITECH PROJECT, 2021
** B-SYN-200-NAN-2-1-palindrome-johan.chrillesen
** File description:
** tests_change_base
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "pal.h"
#include "my.h"

void redirect_all_std(void);

Test(free_if_base_is_not_10, test_change_base_to_dec_base_2)
{
    char *str1 = my_strdup("10101");
    char *str2 = my_strdup("10101");
    free_if_base_is_not_10(my_strdup(str1), 2);
    str1 = NULL;
    free_if_base_is_not_10(my_strdup(str2), 10);

    cr_assert_null(str1);
    cr_assert_str_eq(str2, "10101");
}