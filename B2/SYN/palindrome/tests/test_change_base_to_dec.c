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
int check_before_starting_conversion_to_base(char *str_to_return, int number);

Test(change_base_to_dec, test_change_base_to_dec_base_2)
{
    char *new_nb = change_base_to_dec(my_strdup("10101"), 2);
    char *new_nb2 = change_base_to_dec(my_strdup("1"), 2);
    char *new_nb3 = change_base_to_dec(my_strdup("11001110"), 2);
    char *new_nb4 = change_base_to_dec(my_strdup("001101101"), 2);

    cr_assert_str_eq(new_nb, "21");
    cr_assert_str_eq(new_nb2, "1");
    cr_assert_str_eq(new_nb3, "206");
    cr_assert_str_eq(new_nb4, "109");
}

Test(change_base_to_dec, test_change_base_to_dec_base_3)
{
    char *new_nb = change_base_to_dec(my_strdup("210"), 3);
    char *new_nb2 = change_base_to_dec(my_strdup("1"), 3);
    char *new_nb3 = change_base_to_dec(my_strdup("21122"), 3);
    char *new_nb4 = change_base_to_dec(my_strdup("11001"), 3);

    cr_assert_str_eq(new_nb, "21");
    cr_assert_str_eq(new_nb2, "1");
    cr_assert_str_eq(new_nb3, "206");
    cr_assert_str_eq(new_nb4, "109");
}

Test(change_base_to_dec, test_change_base_to_dec_base_4)
{
    char *new_nb = change_base_to_dec(my_strdup("111"), 4);
    char *new_nb2 = change_base_to_dec(my_strdup("1"), 4);
    char *new_nb3 = change_base_to_dec(my_strdup("3032"), 4);
    char *new_nb4 = change_base_to_dec(my_strdup("1231"), 4);

    cr_assert_str_eq(new_nb, "21");
    cr_assert_str_eq(new_nb2, "1");
    cr_assert_str_eq(new_nb3, "206");
    cr_assert_str_eq(new_nb4, "109");
}

Test(change_base_to_dec, test_change_base_to_dec_base_5)
{
    char *new_nb = change_base_to_dec(my_strdup("41"), 5);
    char *new_nb2 = change_base_to_dec(my_strdup("1"), 5);
    char *new_nb3 = change_base_to_dec(my_strdup("1311"), 5);
    char *new_nb4 = change_base_to_dec(my_strdup("414"), 5);

    cr_assert_str_eq(new_nb, "21");
    cr_assert_str_eq(new_nb2, "1");
    cr_assert_str_eq(new_nb3, "206");
    cr_assert_str_eq(new_nb4, "109");
}

Test(change_base_to_dec, test_change_base_to_dec_base_6)
{
    char *new_nb = change_base_to_dec(my_strdup("33"), 6);
    char *new_nb2 = change_base_to_dec(my_strdup("1"), 6);
    char *new_nb3 = change_base_to_dec(my_strdup("542"), 6);
    char *new_nb4 = change_base_to_dec(my_strdup("301"), 6);

    cr_assert_str_eq(new_nb, "21");
    cr_assert_str_eq(new_nb2, "1");
    cr_assert_str_eq(new_nb3, "206");
    cr_assert_str_eq(new_nb4, "109");
}

Test(change_base_to_dec, test_change_base_to_dec_base_7)
{
    char *new_nb = change_base_to_dec(my_strdup("30"), 7);
    char *new_nb2 = change_base_to_dec(my_strdup("1"), 7);
    char *new_nb3 = change_base_to_dec(my_strdup("413"), 7);
    char *new_nb4 = change_base_to_dec(my_strdup("214"), 7);

    cr_assert_str_eq(new_nb, "21");
    cr_assert_str_eq(new_nb2, "1");
    cr_assert_str_eq(new_nb3, "206");
    cr_assert_str_eq(new_nb4, "109");
}

Test(change_base_to_dec, test_change_base_to_dec_base_8)
{
    char *new_nb = change_base_to_dec(my_strdup("25"), 8);
    char *new_nb2 = change_base_to_dec(my_strdup("1"), 8);
    char *new_nb3 = change_base_to_dec(my_strdup("316"), 8);
    char *new_nb4 = change_base_to_dec(my_strdup("155"), 8);

    cr_assert_str_eq(new_nb, "21");
    cr_assert_str_eq(new_nb2, "1");
    cr_assert_str_eq(new_nb3, "206");
    cr_assert_str_eq(new_nb4, "109");
}

Test(change_base_to_dec, test_change_base_to_dec_base_9)
{
    char *new_nb = change_base_to_dec(my_strdup("23"), 9);
    char *new_nb2 = change_base_to_dec(my_strdup("1"), 9);
    char *new_nb3 = change_base_to_dec(my_strdup("248"), 9);
    char *new_nb4 = change_base_to_dec(my_strdup("131"), 9);

    cr_assert_str_eq(new_nb, "21");
    cr_assert_str_eq(new_nb2, "1");
    cr_assert_str_eq(new_nb3, "206");
    cr_assert_str_eq(new_nb4, "109");
}

Test(change_base_to_dec, test_change_base_to_dec_base_other_base)
{
    char *new_nb = change_base_to_dec(my_strdup("21"), -1);
    char *new_nb2 = change_base_to_dec(my_strdup("1"), 0);
    char *new_nb3 = change_base_to_dec(my_strdup("206"), 1);
    char *new_nb4 = change_base_to_dec(my_strdup("109"), 10);

    cr_assert_str_eq(new_nb, "21");
    cr_assert_str_eq(new_nb2, "1");
    cr_assert_str_eq(new_nb3, "206");
    cr_assert_str_eq(new_nb4, "109");
}

Test(check_before_starting_conversion_to_base, test_with_null)
{
    int n1 = check_before_starting_conversion_to_base(NULL, 5);
    int n2 = check_before_starting_conversion_to_base("5", -1);

    cr_assert_eq(n1, -1);
    cr_assert_eq(n2, -1);
}