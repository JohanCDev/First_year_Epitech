/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-bsmatchstick-johan.chrillesen
** File description:
** read_player_move_and_print_updated_board_game
*/

#include "my.h"
#include "matchstick.h"

int ask_and_verify(match_t *match)
{
    int line_chosen = 0;
    int nb_matches = 0;

    line_chosen = get_line_remove(match);
    if (line_chosen == -2)
        return (84);
    if (line_chosen != -1) {
        nb_matches = get_matches(match, line_chosen);
        if (nb_matches == -2)
            return (84);
        if (nb_matches != -1) {
            my_printf("Player removed %d match(es) from line %d\n", \
            nb_matches, line_chosen);
            match->board[line_chosen - 1] -= nb_matches;
            return (1);
        }
    }
    return (0);
}

int make_player_turn(match_t *match)
{
    while (1) {
        match->ret = ask_and_verify(match);
        if (match->ret == 84)
            return (84);
        if (match->ret == 1)
            break;
    }
    print_game_board(match);
    return (0);
}