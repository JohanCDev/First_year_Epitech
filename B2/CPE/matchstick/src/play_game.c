/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-johan.chrillesen
** File description:
** play_game
*/

#include "my.h"
#include "matchstick.h"

int check_end_game(int *board, int nb_lines)
{
    for (int i = 0; i < nb_lines; i++)
        if (board[i] != 0)
            return (0);
    return (1);
}

int play_game(match_t *match)
{
    my_printf("\nYour turn:\n");
    if (make_player_turn(match) == 84)
        return (0);
    if (check_end_game(match->board, match->nb_lines) == 1) {
        my_printf("You lost, too bad...\n");
        return (2);
    }
    my_printf("\nAI's turn...\n");
    play_computer(match);
    if (check_end_game(match->board, match->nb_lines) == 1) {
        my_printf("I lost... snif... but I'll get you next time!!\n");
        return (1);
    }
    return (-1);
}