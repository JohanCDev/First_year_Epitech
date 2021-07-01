/*
** EPITECH PROJECT, 2020
** B-CPE-101-NAN-1-1-bistromatic-johan.chrillesen
** File description:
** test_infin_mult
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(my_infin_mult, mult_small_number)
{
    char nb1[] = "-3";
    char nb2[] = "-7";

    cr_assert_str_eq(my_infin_mult(nb1, nb2), "21");
}

Test(my_infin_mult, mult_small_number1)
{
    char nb1[] = "10";
    char nb2[] = "100";

    cr_assert_str_eq(my_infin_mult(nb1, nb2), "1000");
}

Test(my_infin_mult, mult_small_number2)
{
    char nb1[] = "-3";
    char nb2[] = "7";

    cr_assert_str_eq(my_infin_mult(nb1, nb2), "-21");
}

Test(my_infin_mult, mult_small_number3)
{
    char nb1[] = "3";
    char nb2[] = "-7";

    cr_assert_str_eq(my_infin_mult(nb1, nb2), "-21");
}
Test(my_infin_mult, mult_small_number4)
{
    char nb1[] = "3";
    char nb2[] = "7";

    cr_assert_str_eq(my_infin_mult(nb1, nb2), "21");
}

Test(my_infin_mult, mult_big_number1)
{
    char nb1[] = "1000000";
    char nb2[] = "10000";

    cr_assert_str_eq(my_infin_mult(nb1, nb2), "10000000000");
}

Test(my_infin_mult, mult_big_number2)
{
    char nb1[] = "985678";
    char nb2[] = "8274";

    cr_assert_str_eq(my_infin_mult(nb1, nb2), "8155499772");
}

Test(my_infin_mult, mult_big_number3)
{
    char nb1[] = "00000000985678";
    char nb2[] = "8274";

    cr_assert_str_eq(my_infin_mult(nb1, nb2), "8155499772");
}

Test(my_infin_mult, mult_big_number4)
{
    char nb1[] = "985678";
    char nb2[] = "000000000008274";

    cr_assert_str_eq(my_infin_mult(nb1, nb2), "8155499772");
}

Test(my_infin_mult, mult_big_number5)
{
    char nb1[] = "000000985678";
    char nb2[] = "000000000008274";

    cr_assert_str_eq(my_infin_mult(nb1, nb2), "8155499772");
}

Test(my_infin_mult, mult_big_number6)
{
    char nb1[] = "-985678";
    char nb2[] = "000000000008274";

    cr_assert_str_eq(my_infin_mult(nb1, nb2), "-8155499772");
}

Test(my_infin_mult, mult_big_number7)
{
    char nb1[] = "000000985678";
    char nb2[] = "-000000000008274";

    cr_assert_str_eq(my_infin_mult(nb1, nb2), "-8155499772");
}

Test(my_infin_mult, mult_big_number8)
{
    char nb1[] = "33";
    char nb2[] = "33";

    cr_assert_str_eq(my_infin_mult(nb1, nb2), "1089");
}