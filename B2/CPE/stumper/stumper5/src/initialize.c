/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper5-quentin.leroueil
** File description:
** initialize
*/

#include "hangman.h"

bool check_params(int argc, char **argv, hangman_t *hang)
{
    if (argc != 2 && argc != 3)
        return (0);
    if (argc == 3) {
        if (my_str_isnum(argv[2]) == 0)
            return (0);
        hang->nb_tries = atoi(argv[2]);
    }
    return (1);
}

hangman_t *initialize_struct(void)
{
    hangman_t *hang = malloc(sizeof(hangman_t));

    if (hang == NULL)
        return (NULL);
    hang->word = NULL;
    hang->word_to_find = NULL;
    hang->nb_tries = 10;
    hang->ret = 0;
    return (hang);
}

hangman_t *init_and_check(int argc, char **argv)
{
    hangman_t *hang = initialize_struct();

    if (hang == NULL)
        return (NULL);
    if (check_params(argc, argv, hang) == 0) {
        free(hang);
        return (NULL);
    }
    if (get_word_in_file(hang, argv) == 0)
        return (NULL);
    return (hang);
}