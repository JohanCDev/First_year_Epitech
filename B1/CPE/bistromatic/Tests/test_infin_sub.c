/*
** EPITECH PROJECT, 2020
** B-CPE-101-NAN-1-1-bistromatic-johan.chrillesen
** File description:
** test_infin_sub2
*/

#include <criterion/criterion.h>
#include "../include/my.h"

char *my_infin_sub(char *nb1, char *nb2);

char *do_sub(char *nb1, char *nb2, int neg1, int neg2);

Test(my_infin_sub, sub_small_number)
{
    cr_assert_str_eq(my_infin_sub("1000", "11"), "989");
    cr_assert_str_eq(my_infin_sub("-1000", "11"), "-1011");
    cr_assert_str_eq(my_infin_sub("-1000", "-11"), "-989");
    cr_assert_str_eq(my_infin_sub("1000", "-11"), "1011");
    cr_assert_str_eq(my_infin_sub("-11", "-1000"), "989");
    cr_assert_str_eq(my_infin_sub("-11", "1000"), "-1011");
    cr_assert_str_eq(my_infin_sub("989", "109"), "880");
    cr_assert_str_eq(my_infin_sub("109", "989"), "-880");
    cr_assert_str_eq(my_infin_sub("989", "989"), "0");
    cr_assert_str_eq(my_infin_sub("123456789123456", "123456789123455"), "1");
}