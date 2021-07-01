/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-johan.chrillesen
** File description:
** init_boats
*/

#include "navy.h"

s_coords_boat init_coords_boat(int x0, int x1, int y0, int y1)
{
    s_coords_boat boat;

    boat.x0 = x0;
    boat.x1 = x1;
    boat.y0 = y0;
    boat.y1 = y1;
    return (boat);
}

char **create_boat(char *coordinates, char **map)
{
    switch (coordinates[0]) {
        case '2' :
            map = place_two_boat(map, coordinates);
            break;
        case '3' :
            map = place_three_boat(map, coordinates);
            break;
        case '4' :
            map = place_four_boat(map, coordinates);
            break;
        case '5' :
            map = place_five_boat(map, coordinates);
            break;
    }
    return (map);
}