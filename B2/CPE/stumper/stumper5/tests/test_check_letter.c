/*
** EPITECH PROJECT, 2021
** stumper5
** File description:  bah yes
** test_check_letter.c
*/

#include "hangman.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std (void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(check_letter, letter_in_word_1)
{
    hangman_t *hang = malloc(sizeof(hangman_t));

    init_tests(hang, "test");
    check_letter('t', hang);
    cr_assert_str_eq("t**t", hang->word_to_find);
    free_struct(hang);
}
//Test(check_letter, letter_not_in_word_1, .init = redirect_all_std)
//{
//    hangman_t *hang = malloc(sizeof(hangman_t));
//
//    init_tests(hang, "test");
//    check_letter('v', hang);
//    cr_assert_stdout_eq_str("v: is not in this word\n");
//    free_struct(hang);
//}