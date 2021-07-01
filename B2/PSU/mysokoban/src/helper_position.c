/*
** EPITECH PROJECT, 2021
** B-PSU-200-NAN-2-1-mysokoban-johan.chrillesen
** File description:
** helper_position
*/

#include "sokoban.h"

void update_position_p(sokoban_t *sokoban, int i, int j)
{
    if (sokoban->map[i][j] == 'P') {
        sokoban->pos_x = j;
        sokoban->pos_y = i;
        return;
    }
}

void get_position_p(sokoban_t *sokoban)
{
    for (int i = 0; sokoban->map[i]; i++) {
        for (int j = 0; sokoban->map[i][j]; j++)
            update_position_p(sokoban, i, j);
    }
}