/*
** EPITECH PROJECT, 2021
** B-SYN-200-NAN-2-1-palindrome-johan.chrillesen
** File description:
** tests_requirement
*/


#include <criterion/criterion.h>
#include <criterion/redirect.h>

int my_factrec_synthesis(int nb);
int my_squareroot_synthesis(int nb);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_factrec_synthesis, test_my_factrec_synthesis)
{
    int res = my_factrec_synthesis(0);
    int res2 = my_factrec_synthesis(1);
    int res3 = my_factrec_synthesis(2);
    int res4 = my_factrec_synthesis(3);
    int res5 = my_factrec_synthesis(4);
    int res6 = my_factrec_synthesis(5);
    int res7 = my_factrec_synthesis(6);
    int res8 = my_factrec_synthesis(7);

    cr_assert_eq(res, 1);
    cr_assert_eq(res2, 1);
    cr_assert_eq(res3, 2);
    cr_assert_eq(res4, 6);
    cr_assert_eq(res5, 24);
    cr_assert_eq(res6, 120);
    cr_assert_eq(res7, 720);
    cr_assert_eq(res8, 5040);
}

Test(my_factrec_synthesis, test_my_factrec_synthesis_next)
{
    int res9 = my_factrec_synthesis(8);
    int res10 = my_factrec_synthesis(9);
    int res11 = my_factrec_synthesis(10);
    int res12 = my_factrec_synthesis(11);
    int res13 = my_factrec_synthesis(12);
    int res14 = my_factrec_synthesis(13);
    int res15 = my_factrec_synthesis(-1);

    cr_assert_eq(res9, 40320);
    cr_assert_eq(res10, 362880);
    cr_assert_eq(res11, 3628800);
    cr_assert_eq(res12, 39916800);
    cr_assert_eq(res13, 479001600);
    cr_assert_eq(res14, 0);
    cr_assert_eq(res15, 0);
}

Test(my_squareroot_synthesis, test_my_squareroot_synthesis)
{
    int res1 = my_squareroot_synthesis(-1);
    int res2 = my_squareroot_synthesis(0);
    int res3 = my_squareroot_synthesis(1);
    int res4 = my_squareroot_synthesis(3);
    int res5 = my_squareroot_synthesis(9);
    int res6 = my_squareroot_synthesis(16);
    int res7 = my_squareroot_synthesis(25);
    int res8 = my_squareroot_synthesis(28);
    int res9 = my_squareroot_synthesis(2147395600);
    int res10 = my_squareroot_synthesis(548741);

    cr_assert_eq(res1, -1);
    cr_assert_eq(res2, 0);
    cr_assert_eq(res3, 1);
    cr_assert_eq(res4, -1);
    cr_assert_eq(res5, 3);
    cr_assert_eq(res6, 4);
    cr_assert_eq(res7, 5);
    cr_assert_eq(res8, -1);
    cr_assert_eq(res9, 46340);
    cr_assert_eq(res10, -1);
}