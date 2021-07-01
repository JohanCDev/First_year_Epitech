/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** test_eval_expr
*/

#include <criterion/criterion.h>

char *eval_expr(char const *base, char const *ops, \
char const *expr, unsigned int size);

Test(eval_expr, small_pos_add)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "3+3", 3), "6");
}

Test(eval_expr, small_pos_sub)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "12-9", 4), "3");
}

Test(eval_expr, small_pos_mult)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "44*1", 4), "44");
}

Test(eval_expr, small_pos_div)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "9/3", 3), "3");
}

Test(eval_expr, small_pos_mod)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "9%2", 3), "1");
}

Test(eval_expr, small_pos_mod_res_0)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "9%3", 3), "0");
}

Test(eval_expr, small_pos_div_with_arrounded_result)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "9/4", 3), "2");
}

Test(eval_expr, small_return_0_with_sub)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "3-3", 3), "0");
}

Test(eval_expr, small_first_neg)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "-3-3", 4), "0");
}

Test(eval_expr, simple_priority)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "4*2+3", 7), "11");
}

Test(eval_expr, should_return_error_cause_div_by_zero)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "(4*2+3)/0", 9), "error");
}

Test(eval_expr, should_return_error_cause_mod_zero)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "(4*2)%(4-4)", 11), "error");
}

Test(eval_expr, calc_with_two_fact)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "4*2/4", 5), "2");
}

Test(eval_expr, calc_with_fact_and_sum)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "4*2+4", 5), "12");
}

Test(eval_expr, calc_with_fact_and_sum_par_in_first)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "(4+2)*4", 7), "24");
}

Test(eval_expr, calc_with_fact_and_sum_par_after)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "4*(2+4)", 7), "24");
}

Test(eval_expr, big_pos_add)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "999999999999999999999+2", 3), "1000000000000000000001");
}

Test(eval_expr, big_pos_sub)
{
    cr_assert_str_eq(eval_expr("0123456789", "()+-*/%", "1000000000000000000001-2", 3), "999999999999999999999");
}