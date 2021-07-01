/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-matchstick-johan.chrillesen
** File description:
** computer_turn
*/

#include "my.h"
#include "matchstick.h"
#include <math.h>

int calculate_nb_sticks(match_t *match)
{
    int moves_left = 0;
    bool is_odd = false;
    int max_size = 0;

    for (int i = 0; match->board[i] <= match->nb_sticks_max \
    && i < match->nb_lines; i++) {
        if (match->board[i] > max_size)
            max_size = match->board[i];
    }
    for (int i = 0; match->board[i] < match->nb_sticks_max \
        && i < match->nb_lines; i++)
        moves_left += (match->board[i] > 0);
    is_odd = (moves_left % 2);
    return (max_size - (int)is_odd);
}

void print_result(int nb_sticks, int max_size, match_t *match)
{
    my_printf("AI removed %d match(es) from line %d\n", \
    nb_sticks, max_size + 1);
    print_game_board(match);
}

void play_computer(match_t *match)
{
    int nb_sticks = calculate_nb_sticks(match);
    int target_size = 0;
    int max_size = 0;

    for (int i = 0; i < match->nb_lines; i++) {
        target_size = my_pow(match->board[i], nb_sticks);
        if (target_size > match->board[i])
            break;
    }
    if (nb_sticks == 0)
        nb_sticks++;
    for (int i = 0; i < match->nb_lines; i++) {
        if (match->board[i] > max_size)
            max_size = i;
        if (match->board[i] - nb_sticks == 1)
            break;
    }
    match->board[max_size] -= nb_sticks;
    print_result(nb_sticks, max_size, match);
}