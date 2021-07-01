/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper5-quentin.leroueil
** File description:
** test_check_params
*/

#include <criterion/criterion.h>
#include "hangman.h"

bool check_params(int argc, char **argv, hangman_t *hang);

Test (check_params, not_enough_args)
{
    char **argv = my_str_to_word_array("./hangman", " ");
    int argc = 1;
    hangman_t hang = {NULL, NULL, 0, 0};

    cr_assert_eq(check_params(argc, argv, &hang), 0);
}

Test (check_params, too_much_args)
{
    char **argv = my_str_to_word_array("./hangman file 4 test", " ");
    int argc = 4;
    hangman_t hang = {NULL, NULL, 0, 0};

    cr_assert_eq(check_params(argc, argv, &hang), 0);
}

Test (check_params, third_arg_not_number)
{
    char **argv = my_str_to_word_array("./hangman file z", " ");
    int argc = 3;
    hangman_t hang = {NULL, NULL, 0, 0};

    cr_assert_eq(check_params(argc, argv, &hang), 0);
}

Test (check_params, all_good)
{
    char **argv = my_str_to_word_array("./hangman file 5", " ");
    int argc = 3;
    hangman_t hang = {NULL, NULL, 0, 0};

    cr_assert_eq(check_params(argc, argv, &hang), 1);
}