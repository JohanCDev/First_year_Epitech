/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper5-quentin.leroueil
** File description:
** free_all
*/

#include "hangman.h"

void free_struct(hangman_t *hang)
{
    if (hang->word) {
        free(hang->word);
        hang->word = NULL;
    }
    if (hang->word_to_find) {
        free(hang->word_to_find);
        hang->word_to_find = NULL;
    }
    if (hang) {
        free(hang);
        hang = NULL;
    }
}

void free_array(char **array)
{
    for (int i = 0; array[i]; i++) {
        if (array[i] != NULL) {
            free(array[i]);
            array[i] = NULL;
        }
    }
    if (array != NULL) {
        free(array);
        array = NULL;
    }
}