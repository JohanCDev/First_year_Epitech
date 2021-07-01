/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper5-quentin.leroueil
** File description:
** get_word
*/

#include "hangman.h"

int initialize_words(hangman_t *hang, char **array, int nb_rand)
{
    hang->word = strdup(array[nb_rand]);
    if (hang->word == NULL) {
        return (-1);
    }
    hang->word_to_find = strdup(array[nb_rand]);
    if (hang->word_to_find == NULL) {
        free(hang->word);
        return (-1);
    }
    return (0);
}

int pick_random_word(hangman_t *hang, char *file)
{
    char **array = my_str_to_word_array(file, " \n\t");
    int nb_rand = 0;
    int nb_words = 0;

    if (array == NULL)
        return (-1);
    srand(time(NULL));
    for (; array[nb_words]; nb_words++);
    nb_rand = rand() % nb_words;
    if (initialize_words(hang, array, nb_rand) == -1) {
        free_array(array);
        return (-1);
    }
    for (int i = 0; hang->word_to_find[i]; i++)
        hang->word_to_find[i] = '*';
    free_array(array);
    return (0);
}

bool get_word_in_file(hangman_t *hang, char **argv)
{
    char *file = open_and_read_file(argv[1]);

    if (file == NULL) {
        free(hang);
        return (0);
    }
    if (pick_random_word(hang, file) == -1) {
        free(hang);
        free(file);
        return (0);
    }
    free(file);
    return (1);
}
