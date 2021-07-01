/*
** EPITECH PROJECT, 2021
** stumper 5
** File description:
** check_letter.c
*/

#include "hangman.h"

int check_letter(char c, hangman_t *hang)
{
    int find = 0;

    for (int i = 0; hang->word[i]; i++) {
        if (hang->word[i] == c) {
            hang->word_to_find[i] = hang->word[i];
            find = 1;
        }
    }
    if (!find) {
        hang->nb_tries--;
        printf("%c: is not in this word\n", c);
    }
    return (0);
}