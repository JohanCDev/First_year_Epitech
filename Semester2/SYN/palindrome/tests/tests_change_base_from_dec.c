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

int get_value(char c);
void redirect_all_std(void);

Test(change_base_from_dec, test_change_base_from_dec_base_2)
{
    char *new_nb = change_base_from_dec(1234, 2);
    char *new_nb2 = change_base_from_dec(1, 2);
    char *new_nb3 = change_base_from_dec(9876, 2);
    char *new_nb4 = change_base_from_dec(5432, 2);

    cr_assert_str_eq(new_nb, "10011010010");
    cr_assert_str_eq(new_nb2, "1");
    cr_assert_str_eq(new_nb3, "10011010010100");
    cr_assert_str_eq(new_nb4, "1010100111000");
}

Test(change_base_from_dec, test_change_base_from_dec_base_3)
{
    char *new_nb = change_base_from_dec(1234, 3);
    char *new_nb2 = change_base_from_dec(1, 3);
    char *new_nb3 = change_base_from_dec(9876, 3);
    char *new_nb4 = change_base_from_dec(5432, 3);

    cr_assert_str_eq(new_nb, "1200201");
    cr_assert_str_eq(new_nb2, "1");
    cr_assert_str_eq(new_nb3, "111112210");
    cr_assert_str_eq(new_nb4, "21110012");
}

Test(change_base_from_dec, test_change_base_from_dec_base_4)
{
    char *new_nb = change_base_from_dec(1234, 4);
    char *new_nb2 = change_base_from_dec(1, 4);
    char *new_nb3 = change_base_from_dec(9876, 4);
    char *new_nb4 = change_base_from_dec(5432, 4);

    cr_assert_str_eq(new_nb, "103102");
    cr_assert_str_eq(new_nb2, "1");
    cr_assert_str_eq(new_nb3, "2122110");
    cr_assert_str_eq(new_nb4, "1110320");
}

Test(change_base_from_dec, test_change_base_from_dec_base_5)
{
    char *new_nb = change_base_from_dec(1234, 5);
    char *new_nb2 = change_base_from_dec(1, 5);
    char *new_nb3 = change_base_from_dec(9876, 5);
    char *new_nb4 = change_base_from_dec(5432, 5);

    cr_assert_str_eq(new_nb, "14414");
    cr_assert_str_eq(new_nb2, "1");
    cr_assert_str_eq(new_nb3, "304001");
    cr_assert_str_eq(new_nb4, "133212");
}

Test(change_base_from_dec, test_change_base_from_dec_base_6)
{
    char *new_nb = change_base_from_dec(1234, 6);
    char *new_nb2 = change_base_from_dec(1, 6);
    char *new_nb3 = change_base_from_dec(9876, 6);
    char *new_nb4 = change_base_from_dec(5432, 6);

    cr_assert_str_eq(new_nb, "5414");
    cr_assert_str_eq(new_nb2, "1");
    cr_assert_str_eq(new_nb3, "113420");
    cr_assert_str_eq(new_nb4, "41052");
}

Test(change_base_from_dec, test_change_base_from_dec_base_7)
{
    char *new_nb = change_base_from_dec(1234, 7);
    char *new_nb2 = change_base_from_dec(1, 7);
    char *new_nb3 = change_base_from_dec(9876, 7);
    char *new_nb4 = change_base_from_dec(5432, 7);

    cr_assert_str_eq(new_nb, "3412");
    cr_assert_str_eq(new_nb2, "1");
    cr_assert_str_eq(new_nb3, "40536");
    cr_assert_str_eq(new_nb4, "21560");
}

Test(change_base_from_dec, test_change_base_from_dec_base_8)
{
    char *new_nb = change_base_from_dec(1234, 8);
    char *new_nb2 = change_base_from_dec(1, 8);
    char *new_nb3 = change_base_from_dec(9876, 8);
    char *new_nb4 = change_base_from_dec(5432, 8);

    cr_assert_str_eq(new_nb, "2322");
    cr_assert_str_eq(new_nb2, "1");
    cr_assert_str_eq(new_nb3, "23224");
    cr_assert_str_eq(new_nb4, "12470");
}

Test(change_base_from_dec, test_change_base_from_dec_base_9)
{
    char *new_nb = change_base_from_dec(1234, 9);
    char *new_nb2 = change_base_from_dec(1, 9);
    char *new_nb3 = change_base_from_dec(9876, 9);
    char *new_nb4 = change_base_from_dec(5432, 9);

    cr_assert_str_eq(new_nb, "1621");
    cr_assert_str_eq(new_nb2, "1");
    cr_assert_str_eq(new_nb3, "14483");
    cr_assert_str_eq(new_nb4, "7405");
}

Test(change_base_from_dec, test_change_base_from_dec_other_base)
{
    char *new_nb = change_base_from_dec(1234, -1);
    char *new_nb2 = change_base_from_dec(1, 65);
    char *new_nb3 = change_base_from_dec(9876, 10);
    char *new_nb4 = change_base_from_dec(5432, 24);

    cr_assert_str_eq(new_nb, "1234");
    cr_assert_str_eq(new_nb2, "1");
    cr_assert_str_eq(new_nb3, "9876");
    cr_assert_str_eq(new_nb4, "5432");
}

Test(get_value, test_get_value_correct)
{
    cr_assert_eq(get_value('8'), 8);
    cr_assert_eq(get_value('0'), 0);
    cr_assert_eq(get_value('9'), 9);
    cr_assert_eq(get_value('A'), 10);
    cr_assert_eq(get_value('/'), -1);
}