/*
** EPITECH PROJECT, 2021
** B-PSU-200-NAN-2-1-mysokoban-johan.chrillesen
** File description:
** check_lost_game
*/

#include "my.h"
#include "sokoban.h"

int check_border_up(sokoban_t *sokoban, int i)
{
    int count = 0;
    int nb_wall = 0;

    for (count = 0; sokoban->map[i][count] != '\n'; count++);
    for (int j = 0; j <= count; j++)
        if (sokoban->map[i][j] == 'O')
            return (0);
    i = i;
    for (int j = 1; j <= count; j++)
        if (sokoban->map[i - 1][j] == '#')
            nb_wall++;
    if ((nb_wall - 1) == count)
        return (1);
    return (0);
}

int check_placement_around_x(char **map, int i, int j)
{
    if (map[i][j] == 'X') {
        if ((((map[i - 1][j] == '#') || (map[i - 1][j] == 'X')) && \
        ((map[i][j - 1] == '#') || (map[i][j - 1] == 'X'))) || \
        (((map[i + 1][j] == '#') || (map[i + 1][j] == 'X')) && \
        ((map[i][j + 1] == '#') || (map[i][j + 1] == 'X'))) || \
        (((map[i - 1][j] == '#') || (map[i - 1][j] == 'X')) && \
        ((map[i][j + 1] == '#') || (map[i][j + 1] == 'X'))) || \
        (((map[i + 1][j] == '#') || (map[i + 1][j] == 'X')) && \
        ((map[i][j - 1] == '#') || (map[i][j -1] == 'X'))))
            return (1);
    }
    return (0);
}

int verify_each_x(char **map, int i, int j, lose_t *lost)
{
    if (check_placement_around_x(map, i, j) == 1) {
        lost->nb_blocked_x++;
        if (lost->nb_blocked_x == lost->nb_x)
            return (0);
    }
    return (1);
}

int check_if_lose(sokoban_t *sokoban)
{
    int i = 0;
    int j = 0;
    lose_t *lost = malloc(sizeof(*lost));

    if (lost == NULL)
        return (84);
    lost->nb_x = get_nb_x(sokoban->base_map);
    lost->nb_blocked_x = 0;
    while (sokoban->base_map[i]) {
        if (verify_each_x(sokoban->map, i, j, lost) == 0)
            return (1);
        if (sokoban->base_map[i][j] == '\0') {
            i++;
            j = 0;
        }
        j++;
    }
    return (0);
}