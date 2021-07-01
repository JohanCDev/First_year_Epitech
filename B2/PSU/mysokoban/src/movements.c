/*
** EPITECH PROJECT, 2021
** B-PSU-200-NAN-2-1-mysokoban-johan.chrillesen
** File description:
** movements
*/

#include "my.h"
#include "sokoban.h"

void move_up(sokoban_t *sokoban)
{
    if (sokoban->map[sokoban->pos_y - 1][sokoban->pos_x] != '#') {
        if ((sokoban->map[sokoban->pos_y - 1][sokoban->pos_x] == 'X') && \
        (sokoban->map[sokoban->pos_y - 2][sokoban->pos_x] != '#') && \
        (sokoban->map[sokoban->pos_y - 2][sokoban->pos_x] != 'X')) {
            sokoban->map[sokoban->pos_y - 1][sokoban->pos_x] = 'P';
            sokoban->map[sokoban->pos_y - 2][sokoban->pos_x] = 'X';
            sokoban->map[sokoban->pos_y][sokoban->pos_x] = ' ';
        } else if (sokoban->map[sokoban->pos_y - 1][sokoban->pos_x] != 'X') {
            sokoban->map[sokoban->pos_y - 1][sokoban->pos_x] = 'P';
            sokoban->map[sokoban->pos_y][sokoban->pos_x] = ' ';
        }
    }
}

void move_down(sokoban_t *sokoban)
{
    if (sokoban->map[sokoban->pos_y + 1][sokoban->pos_x] != '#') {
        if ((sokoban->map[sokoban->pos_y + 1][sokoban->pos_x] == 'X') && \
        (sokoban->map[sokoban->pos_y + 2][sokoban->pos_x] != '#') && \
        (sokoban->map[sokoban->pos_y + 2][sokoban->pos_x] != 'X')) {
            sokoban->map[sokoban->pos_y + 1][sokoban->pos_x] = 'P';
            sokoban->map[sokoban->pos_y + 2][sokoban->pos_x] = 'X';
            sokoban->map[sokoban->pos_y][sokoban->pos_x] = ' ';
        } else if (sokoban->map[sokoban->pos_y + 1][sokoban->pos_x] != 'X') {
            sokoban->map[sokoban->pos_y + 1][sokoban->pos_x] = 'P';
            sokoban->map[sokoban->pos_y][sokoban->pos_x] = ' ';
        }
    }
}

void move_left(sokoban_t *sokoban)
{
    if (sokoban->map[sokoban->pos_y][sokoban->pos_x - 1] != '#') {
        if ((sokoban->map[sokoban->pos_y][sokoban->pos_x - 1] == 'X') && \
        (sokoban->map[sokoban->pos_y][sokoban->pos_x - 2] != '#') && \
        (sokoban->map[sokoban->pos_y][sokoban->pos_x - 2] != 'X')) {
            sokoban->map[sokoban->pos_y][sokoban->pos_x - 1] = 'P';
            sokoban->map[sokoban->pos_y][sokoban->pos_x - 2] = 'X';
            sokoban->map[sokoban->pos_y][sokoban->pos_x] = ' ';
        } else if (sokoban->map[sokoban->pos_y][sokoban->pos_x - 1] != 'X') {
            sokoban->map[sokoban->pos_y][sokoban->pos_x - 1] = 'P';
            sokoban->map[sokoban->pos_y][sokoban->pos_x] = ' ';
        }
    }
}

void move_right(sokoban_t *sokoban)
{
    if (sokoban->map[sokoban->pos_y][sokoban->pos_x + 1] != '#') {
        if ((sokoban->map[sokoban->pos_y][sokoban->pos_x + 1] == 'X') && \
        (sokoban->map[sokoban->pos_y][sokoban->pos_x + 2] != '#') && \
        (sokoban->map[sokoban->pos_y][sokoban->pos_x + 2] != 'X')) {
            sokoban->map[sokoban->pos_y][sokoban->pos_x + 1] = 'P';
            sokoban->map[sokoban->pos_y][sokoban->pos_x + 2] = 'X';
            sokoban->map[sokoban->pos_y][sokoban->pos_x] = ' ';
        } else if (sokoban->map[sokoban->pos_y][sokoban->pos_x + 1] != 'X') {
            sokoban->map[sokoban->pos_y][sokoban->pos_x + 1] = 'P';
            sokoban->map[sokoban->pos_y][sokoban->pos_x] = ' ';
        }
    }
}