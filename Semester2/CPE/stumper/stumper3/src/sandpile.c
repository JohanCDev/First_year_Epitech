/*
** EPITECH PROJECT, 2021
** Duo-3
** File description:
** sandpile.c
*/
#include "sandpile.h"

void change_sandpile(map_t *map, int y, int x)
{
    int top = y * (map->width - 1) + x * map->height;
    int bottom = y * (map->width + 1) + x * map->height;
    int actual = y * map->width + x * map->height;

    if (map->map[top])
        map->map[top] += 1;
    if (map->map[bottom])
        map->map[bottom] += 1;
    if (x + 1 < map->width && map->map[actual + 1])
        map->map[actual + 1] += 1;
    if (x - 1 < map->width && map->map[actual - 1])
        map->map[actual - 1] += 1;
    map->map[actual] -= 4;
}

void check_change_sandpile(map_t *map, int *y, int *x)
{
    if (map->map[*y * map->height + *x * map->width] >= 4) {
        change_sandpile(map, *y, *x);
        *y = 0;
        *x = 0;
    }
}

void check_if_nb_sup_four(map_t *map)
{
    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            check_change_sandpile(map, &y, &x);
        }
    }
}

int print_sandpile(map_t *map)
{
    char *frame = calloc(sizeof(char), map->width + 3);
    char *line = calloc(sizeof(char), map->width + 1);

    if (!frame || !line)
        return (-1);
    frame[0] = '+';
    for (int i = 0; i < map->height; i++)
        if (strcat(frame, "-") == NULL)
            return (-1);
    frame[strlen(frame)] = "+";
    write(1, frame, strlen(frame));
    for (int y = 0; y < map->height; y++) {
        write(1, "|", 1);
        memset(line, '\0', map->width);
        for (int x = 0; x < map->width; x++)
            line[x] = map->str[map->map[y * map->height + x * map->width]];
        write(1, line, strlen(line));
        write(1, "|", 1);
    }
    write(1, frame, strlen(frame));
    return (0);
}

int sandpile(map_t *map, int nb_cycle)
{
    int i = 0;

    while (i < nb_cycle) {
        check_if_nb_sup_four(map);
        i++;
    }
    return (print_sandpile(map));
}