/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-johan.chrillesen
** File description:
** change_maps
*/

#include "navy.h"
#include "my.h"

extern s_glob_var glob_var;

char **fill_target(char **map, char *input, int hit)
{
    int x = input[0] - 65 + input[0] - 63;
    int y = input[1] - 47;

    if (hit == 0) {
        map[y][x] = 'x';
        my_printf("%s: hit\n\n", input);
    } else {
        map[y][x] = 'o';
        my_printf("%s: missed\n\n", input);
    }
    return (map);
}

char **fill_shoot(char **map, int char_x, int char_y)
{
    if (map[char_y + 1][char_x * 2] == '.' || \
    map[char_y + 1][char_x * 2] == 'o') {
        kill(glob_var.pid_enemy, SIGUSR1);
        usleep(40);
        map[char_y + 1][char_x * 2] = 'o';
        my_printf("%c%d: missed\n\n", char_x + 64, char_y);
    }
    else if (map[char_y + 1][char_x * 2] >= '2' \
    && map[char_y + 1][char_x * 2] <= '5') {
        kill(glob_var.pid_enemy, SIGUSR2);
        usleep(40);
        map[char_y + 1][char_x * 2] = 'x';
        my_printf("%c%d: hit\n\n", char_x + 64, char_y);
    }
    return (map);
}