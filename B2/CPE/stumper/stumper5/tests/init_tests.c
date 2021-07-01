/*
** EPITECH PROJECT, 2021
** stumper5
** File description:
** init_tests.c
*/

#include "hangman.h"

void init_tests(hangman_t *hang, char *word)
{
    hang->word = strdup(word);
    hang->word_to_find = strdup(word);
    for (int i = 0; hang->word_to_find[i]; i++)
        hang->word_to_find[i] = '*';
}