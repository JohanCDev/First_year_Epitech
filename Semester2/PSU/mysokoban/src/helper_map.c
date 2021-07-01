/*
** EPITECH PROJECT, 2021
** B-PSU-200-NAN-2-1-mysokoban-johan.chrillesen
** File description:
** helper
*/

#include "my.h"
#include "sokoban.h"

void count_lines(char *buffer, sokoban_t *sokoban)
{
    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] == '\n')
            sokoban->height++;
    }
}

int get_width_of_map(char *buffer, int i, sokoban_t *sokoban)
{
    int length = 0;

    for (; buffer[i] != '\n'; length++)
        i++;
    length > sokoban->width ? sokoban->width = length : 0;
    return (length);
}

int count_o_base(char **map)
{
    int i = 0;
    int j = 0;
    int nb_o = 0;

    while (map[i]) {
        if (map[i][j] == 'O')
            nb_o++;
        if (map[i][j] == '\0') {
            i++;
            j = 0;
        }
        j++;
    }
    return (nb_o);
}

void change_map_add_o(sokoban_t *sokoban)
{
    int i = 0;
    int j = 0;

    while (sokoban->base_map[i]) {
        if (sokoban->base_map[i][j] == 'O' && sokoban->map[i][j] != 'P' \
        && sokoban->map[i][j] != 'X')
            sokoban->map[i][j] = 'O';
        if (sokoban->base_map[i][j] == '\0') {
            i++;
            j = 0;
        }
        j++;
    }
}

check_map_t count_specials_chars(check_map_t numbers_ch, char *buffer, int i)
{
    if (buffer[i] == 'P')
        numbers_ch.nb_p++;
    if (buffer[i] == 'X')
        numbers_ch.nb_x++;
    else if (buffer[i] == 'O')
        numbers_ch.nb_o++;
    return (numbers_ch);
}