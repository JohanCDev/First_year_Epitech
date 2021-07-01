/*
** EPITECH PROJECT, 2021
** Duo-7
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "calendar.h"
#include "my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(initialize_employee, test_initialize_employee)
{
    employee_t *emp = initialize_employee();

    cr_assert_null(emp->first_name);
    cr_assert_null(emp->last_name);
    cr_assert_null(emp->next);
    cr_assert_null(emp->position);
    cr_assert_null(emp->zip);
    cr_assert_eq(emp->id, 0);
}

Test(initialize_meeting, test_initialize_meeting)
{
    meeting_t *meet = initialize_meeting();

    cr_assert_null(meet->place);
    cr_assert_null(meet->next);
    cr_assert_null(meet->day);
    cr_assert_eq(meet->id, 0);
}

Test(check_args, test_args_helper, .init = redirect_all_std)
{
    int argc = 2;
    char **argv = my_str_to_word_array("./a.out -h", " ");

    check_args(argc, argv);
    cr_assert_stdout_eq_str(HELPER);
}

Test(check_args, test_args_too_much, .init = redirect_all_std)
{
    int argc = 3;
    char **argv = my_str_to_word_array("./a.out toto tata", " ");

    cr_assert_eq(check_args(argc, argv), -1);
}

Test(check_args, test_args_good_args, .init = redirect_all_std)
{
    int argc = 1;
    char **argv = my_str_to_word_array("./a.out", " ");
    int ret = check_args(argc, argv);

    cr_assert_eq(ret, 1);
}