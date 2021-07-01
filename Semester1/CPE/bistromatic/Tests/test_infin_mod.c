/*
** EPITECH PROJECT, 2020
** B-CPE-101-NAN-1-1-bistromatic-johan.chrillesen
** File description:
** test_infin_add
*/

#include <criterion/criterion.h>
#include "../include/my.h"

char *my_infin_mod(char *nb1, char *nb2);

char *do_add(char *nb1, char *nb2, char *res);

Test(my_infin_mod, small_numbers)
{
    char nb1[] = "5";
    char nb2[] = "3";

    cr_assert_str_eq(my_infin_mod(nb1, nb2), "2");
}

Test(my_infin_mod, small_numbers1)
{
    char nb1[] = "3";
    char nb2[] = "5";

    cr_assert_str_eq(my_infin_mod(nb1, nb2), "3");
}

Test(my_infin_mod, small_numbers2)
{
    char nb1[] = "5";
    char nb2[] = "5";

    cr_assert_str_eq(my_infin_mod(nb1, nb2), "0");
}


Test(my_infin_mod, small_numbers3)
{
    char nb1[] = "47";
    char nb2[] = "28";

    cr_assert_str_eq(my_infin_mod(nb1, nb2), "19");
}

Test(my_infin_mod, small_numbers4)
{
    char nb1[] = "89687";
    char nb2[] = "768";

    cr_assert_str_eq(my_infin_mod(nb1, nb2), "599");
}

Test(my_infin_mod, big_numbers)
{
    char nb1[] = "1000000000000000";
    char nb2[] = "648958090";

    cr_assert_str_eq(my_infin_mod(nb1, nb2), "361418210");
}

Test(my_infin_mod, big_numbers1)
{
    char nb1[] = "-4";
    char nb2[] = "-2";

    cr_assert_str_eq(my_infin_mod(nb1, nb2), "0");
}

Test(my_infin_mod, big_numbers2)
{
    char nb1[] = "-8";
    char nb2[] = "3";

    cr_assert_str_eq(my_infin_mod(nb1, nb2), "-2");
}

Test(my_infin_mod, big_numbers3)
{
    char nb1[] = "-8";
    char nb2[] = "-3";

    cr_assert_str_eq(my_infin_mod(nb1, nb2), "2");
}

Test(my_infin_mod, divide_by_zero)
{
    char nb1[] = "8";
    char nb2[] = "0";

    cr_assert_str_eq(my_infin_mod(nb1, nb2), "error");
}

Test(my_infin_mod, mod_or_zero)
{
    char nb1[] = "0";
    char nb2[] = "8";

    cr_assert_str_eq(my_infin_mod(nb1, nb2), "0");
}