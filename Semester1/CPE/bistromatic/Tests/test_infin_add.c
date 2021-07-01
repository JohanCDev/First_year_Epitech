/*
** EPITECH PROJECT, 2020
** B-CPE-101-NAN-1-1-bistromatic-johan.chrillesen
** File description:
** test_infin_add
*/

#include <criterion/criterion.h>
#include "../include/my.h"

char *my_infin_add(char *nb1, char *nb2);

char *do_add(char *nb1, char *nb2, char *res);

Test(my_infin_add, add_small_number)
{
    char nb1[] = "3";
    char nb2[] = "5";

    cr_assert_str_eq(my_infin_add(nb1, nb2), "8");
}

Test(my_infin_add, add_big_number)
{
    char nb1[] = "7654567893";
    char nb2[] = "1974382691";

    cr_assert_str_eq(my_infin_add(nb1, nb2), "9628950584");
}

Test(my_infin_add, add_number_diff_size)
{
    char nb1[] = "193379493";
    char nb2[] = "1325";

    cr_assert_str_eq(my_infin_add(nb1, nb2), "193380818");
}

Test(my_infin_add, add_number_carry_one)
{
    char nb1[] = "1000";
    char nb2[] = "10000000";

    cr_assert_str_eq(my_infin_add(nb1, nb2), "10001000");
}

Test(my_infin_add, add_number_close_ten)
{
    char nb1[] = "1";
    char nb2[] = "9999";

    cr_assert_str_eq(my_infin_add(nb1, nb2), "10000");
}

Test(my_infin_add, add_number_zero)
{
    char nb1[] = "0";
    char nb2[] = "667";

    cr_assert_str_eq(my_infin_add(nb1, nb2), "667");
}

Test(my_infin_add, add_number_with_zero_1)
{
    char nb1[] = "00000068";
    char nb2[] = "32";

    cr_assert_str_eq(my_infin_add(nb1, nb2), "100");
}

Test(my_infin_add, add_number_with_zero_2)
{
    char nb1[] = "57";
    char nb2[] = "000000409";

    cr_assert_str_eq(my_infin_add(nb1, nb2), "466");
}

Test(my_infin_add, add_number_with_zero_3)
{
    char nb1[] = "9";
    char nb2[] = "8";

    cr_assert_str_eq(my_infin_add(nb1, nb2), "17");
}

Test(my_infin_add, add_neg_number)
{
    char nb1[] = "-9";
    char nb2[] = "5";

    cr_assert_str_eq(my_infin_add("-9", "5"), "-4");
}

Test(my_infin_add, add_neg_number_different_length)
{
    char nb1[] = "-9";
    char nb2[] = "17";

    cr_assert_str_eq(my_infin_add("-9", "17"), "8");
}

Test(my_infin_add, add_neg_number_over_0)
{
    char nb1[] = "1000";
    char nb2[] = "-1111";

    cr_assert_str_eq(my_infin_add("1000", "-1111"), "-111");
}