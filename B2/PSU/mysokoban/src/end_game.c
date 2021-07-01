/*
** EPITECH PROJECT, 2021
** B-PSU-200-NAN-2-1-mysokoban-johan.chrillesen
** File description:
** end_game
*/

#include "sokoban.h"

int verify_nb_o(sokoban_t *sokoban, int i, int j, int nb_o)
{
    if (sokoban->base_map[i][j] == 'O' && sokoban->map[i][j] == 'X') {
        nb_o--;
        if (nb_o == 0)
            return (-1);
    }
    return (nb_o);
}

int check_if_win(sokoban_t *sokoban)
{
    int nb_o = count_o_base(sokoban->base_map);
    int i = 0;
    int j = 0;

    while (sokoban->base_map[i]) {
        nb_o = verify_nb_o(sokoban , i, j, nb_o);
        if (nb_o == -1) {
            print_map(sokoban);
            return (0);
        }
        if (sokoban->base_map[i][j] == '\0') {
            i++;
            j = 0;
        }
        j++;
    }
    return (1);
}

void check_if_game_end(sokoban_t *sokoban)
{
    sokoban->ret = check_if_win(sokoban);
    if (sokoban->ret == 0)
        return;
    sokoban->ret = check_if_lose(sokoban);
    if (sokoban->ret == 1)
        return;
    if (sokoban->ret == 84)
        return;
    sokoban->ret = 2;
    return;
}