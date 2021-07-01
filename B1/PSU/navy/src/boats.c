/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** boats
*/

#include "my.h"
#include "navy.h"

char **place_two_boat(char **map, char *position)
{
    int x0 = position[2] - 65 + position[2] - 63;
    int y0 = position[3] - 47;
    int x1 = position[5] - 65 + position[5] - 63;
    int y1 = position[6] - 47;
    s_coords_boat boat;

    boat = init_coords_boat(x0, x1, y0, y1);

    if ((x1 - x0 == 2 || y1 - y0 == 1) && check_availabality(boat, map)) {
        map[y0][x0] = '2';
        map[y1][x1] = '2';
    } else
        my_put_error("bad boat placement");
    return (map);
}

char **place_three_boat(char **map, char *position)
{
    int x0 = position[2] - 65 + position[2] - 63;
    int y0 = position[3] - 47;
    int x1 = position[5] - 65 + position[5] - 63;
    int y1 = position[6] - 47;
    s_coords_boat boat;

    boat = init_coords_boat(x0, x1, y0, y1);
    if ((x1 - x0 == 4 || y1 - y0 == 2) && check_availabality(boat, map)) {
        if (x0 == x1)
            map[y0 + 1][x0] = '3';
        else if (y0 == y1)
            map[y0][x0 + 2] = '3';
        map[y0][x0] = '3';
        map[y1][x1] = '3';
    } else
        my_put_error("bad boat placement");
    return (map);
}

char **place_four_boat(char **map, char *position)
{
    int x0 = position[2] - 65 + position[2] - 63;
    int y0 = position[3] - 47;
    int x1 = position[5] - 65 + position[5] - 63;
    int y1 = position[6] - 47;
    s_coords_boat boat;

    boat = init_coords_boat(x0, x1, y0, y1);
    if ((x1 - x0 == 6 || y1 - y0 == 3) && check_availabality(boat, map)) {
        if (x0 == x1) {
            map[y0 + 1][x0] = '4';
            map[y0 + 2][x0] = '4';
        } else if (y0 == y1) {
            map[y0][x0 + 2] = '4';
            map[y0][x0 + 4] = '4';
        }
        map[y0][x0] = '4';
        map[y1][x1] = '4';
    } else
        my_put_error("bad boat placement");
    return (map);
}

char **place_five_boat(char **map, char *position)
{
    int x0 = position[2] - 65 + position[2] - 63;
    int y0 = position[3] - 47;
    int x1 = position[5] - 65 + position[5] - 63;
    int y1 = position[6] - 47;
    s_coords_boat boat;

    boat = init_coords_boat(x0, x1, y0, y1);
    if ((x1 - x0 == 8 || y1 - y0 == 4) && check_availabality(boat, map)) {
        if (x0 == x1) {
            map[y0 + 1][x0] = '5';
            map[y0 + 2][x0] = '5';
            map[y0 + 3][x0] = '5';
        } else if (y0 == y1) {
            map[y0][x0 + 2] = '5';
            map[y0][x0 + 4] = '5';
            map[y0][x0 + 6] = '5';
        }
        map[y0][x0] = '5';
        map[y1][x1] = '5';
    } else
        my_put_error("bad boat placement");
    return (map);
}

int check_availabality(s_coords_boat boat, char **map)
{
    int x = boat.x0;
    int y = boat.y0;

    while (x != boat.x1 && x < 20) {
        if (map[y][x] != '.')
            return (0);
        x += 2;
    }
    while (y != boat.y1 && y < 10) {
        if (map[y][x] != '.')
            return (0);
        y++;
    }
    return (1);
}