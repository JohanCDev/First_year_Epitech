/*
** EPITECH PROJECT, 2021
** stumper 5
** File description:
** play.c
*/

#include "hangman.h"

int show_word(hangman_t *hang)
{
    printf("%s\nTries: %d\n\n", hang->word_to_find, hang->nb_tries);
    return (0);
}

int get_len(char *args)
{
    int i = 0;

    for (; args[i] != '\n' && args[i] != '\0'; i++);
    if (i != 1)
        return (1);
    return (0);
}

int get_player_move(hangman_t *hang)
{
    char *args = NULL;
    size_t nb = 0;
    int i = 0;

    printf("Your letter: ");
    i = getline(&args, &nb, stdin);
    if (i == -1)
        return (-1);
    if (get_len(args))
        return (1);
    check_letter(args[0], hang);
    free(args);
    return (0);
}

int play(hangman_t *hang)
{
    show_word(hang);
    while (hang->nb_tries > 0) {
        if (!strcmp(hang->word, hang->word_to_find))
            break;
        if (get_player_move(hang) == -1)
            return (0);
        show_word(hang);
    }
    if (!hang->nb_tries)
        printf("You lost!\n");
    else
        printf("Congratulations!\n");
    return (0);
}