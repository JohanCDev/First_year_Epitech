/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-bsmatchstick-johan.chrillesen
** File description:
** print_game_board
*/

#include "my.h"
#include "matchstick.h"

void print_sticks(int nb_sticks)
{
    for (int i = 0; i < nb_sticks; i++)
        my_printf("|");
}

void display_spaces(int nb_spaces)
{
    for (int i = 0; i < nb_spaces; i++)
        my_printf(" ");
}

void print_stars(int nb_stars)
{
    for (int i = 0; i < nb_stars; i++)
        my_printf("*");
    my_printf("\n");
}

void print_line(int nb_line, int current_line, match_t *match)
{
    my_printf("*");
    display_spaces(nb_line - current_line - 1);
    print_sticks(match->board[current_line]);
    if (match->board[current_line] < 0)
        display_spaces(nb_line - current_line - 1 + \
        (match->base_board[current_line]));
    else
        display_spaces(nb_line - current_line - 1 + \
        (match->base_board[current_line] - match->board[current_line]));
    my_printf("*\n");
}

void print_game_board(match_t *match)
{
    print_stars(match->nb_lines * 2 + 1);
    for (int i = 0; i < match->nb_lines; i++)
        print_line(match->nb_lines, i, match);
    print_stars(match->nb_lines * 2 + 1);
}