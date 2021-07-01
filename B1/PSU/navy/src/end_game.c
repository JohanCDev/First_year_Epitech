/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-johan.chrillesen
** File description:
** end_game
*/

#include "my.h"
#include "navy.h"

int check_end_game(char **map)
{
    int x = 0;
    int y = 0;
    int nb_touch = 0;

    while (map[y][x]) {
        if (map[y][x] == 'x')
            nb_touch++;
        if (nb_touch == 14)
            return (1);
        x++;
        if (y == 9 && x == 17)
            return (0);
        if (map[y][x] == '\n') {
            y++;
            x = 0;
        }
    }
    return (0);
}