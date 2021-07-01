/*
** EPITECH PROJECT, 2020
** B-CPE-101-NAN-1-1-bistromatic-johan.chrillesen
** File description:
** test_infin-div
*/

#include <criterion/criterion.h>
#include "../include/my.h"

char *do_add(char *nb1, char *nb2, char *res);

char *my_infin_add(char *nb1, char *nb2);

char *my_infin_div(char *nb1, char *nb2);

char *my_infin_mod(char *nb1, char *nb2);

int is_nb1_greater(char *nb1, char *nb2);

char *do_sub(char *nb1, char *nb2, char *res);

char *clean_zeros(char *nbr_in_str);

char *my_infin_sub(char *nb1, char *nb2);

Test(my_infin_div, div_small_number)
{
    char nb1[] = "9";
    char nb2[] = "3";

    cr_assert_str_eq(my_infin_div(nb1, nb2), "3");
}

Test(my_infin_div, div_small_number_result_comas)
{
    char nb1[] = "26";
    char nb2[] = "8";

    cr_assert_str_eq(my_infin_div(nb1, nb2), "3");
}

Test(my_infin_div, div_by_zero)
{
    char nb1[] = "26";
    char nb2[] = "0";

    cr_assert_str_eq(my_infin_div(nb1, nb2), "error");
}

Test(my_infin_div, div_zero)
{
    char nb1[] = "0";
    char nb2[] = "16";

    cr_assert_str_eq(my_infin_div(nb1, nb2), "0");
}

Test(my_infin_div, div_medium_number)
{
    char nb1[] = "230";
    char nb2[] = "23";

    cr_assert_str_eq(my_infin_div(nb1, nb2), "10");
}

Test(my_infin_div, div_medium_number_with_commas)
{
    char nb1[] = "252";
    char nb2[] = "23";

    cr_assert_str_eq(my_infin_div(nb1, nb2), "10");
}

Test(my_infin_div, div_big_number)
{
    char nb1[] = "2000000000000";
    char nb2[] = "1000000000000";

    cr_assert_str_eq(my_infin_div(nb1, nb2), "2");
}

Test(my_infin_div, div_verybig_number)
{
    char nb1[] = "99999900";
    char nb2[] = "20";

    cr_assert_str_eq(my_infin_div(nb1, nb2), "4999995");
}

Test(my_infin_div, div_verbig_number)
{
    char nb1[] = "99999900";
    char nb2[] = "0262662";

    cr_assert_str_eq(my_infin_div(nb1, nb2), "380");
}