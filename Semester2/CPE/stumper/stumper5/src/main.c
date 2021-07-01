/*
** EPITECH PROJECT, 2021
** main
** File description:
** for stumper 3
*/

#include "hangman.h"

int main(int argc, char **argv)
{
    hangman_t *hang = init_and_check(argc, argv);

    if (hang == NULL)
        return (84);
    play(hang);
    free_struct(hang);
    return (0);
}
