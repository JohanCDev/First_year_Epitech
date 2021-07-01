/*
** EPITECH PROJECT, 2020
** B-CPE-101-NAN-1-1-bistromatic-johan.chrillesen
** File description:
** test_infin_add
*/

#include <criterion/criterion.h>
#include "../include/my.h"

int my_atoi(char *str);

Test(my_atoi, small_number)
{
    char *str = "3";
    cr_assert_eq(my_atoi(str), 3);
}

Test(my_atoi, medium_number)
{
    char *str = "51";
    cr_assert_eq(my_atoi(str), 51);
}

Test(my_atoi, small_number_neg)
{
    char *str = "-3";
    cr_assert_eq(my_atoi(str), -3);
}

Test(my_atoi, medium_number_neg)
{
    char *str = "-51";
    cr_assert_eq(my_atoi(str), -51);
}