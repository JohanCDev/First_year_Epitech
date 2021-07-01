/*
** EPITECH PROJECT, 2021
** main
** File description:
** for stumper 3
*/

#include "tictactoe.h"
#include <stdlib.h>

int main(int ac, char **av)
{
    tic_t tic;

    if (argument_handling(&tic, ac, av) == -1)
        return (84);
    if ((tic.map = malloc(sizeof(int) * (tic.size * tic.size))) == NULL)
        return (84);
    for (int i = 0; i < tic.size; i++)
        tic.map[i] = 0;
    return(play_game(&tic));
}
