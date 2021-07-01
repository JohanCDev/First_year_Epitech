/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-tanguy.bellicha
** File description:
** get
*/

#include "my.h"
#include "defender.h"
#include <stdio.h>

void move_horizontally(s_game *defender, s_enemie_info *enemie_info, \
unsigned int x, unsigned int y)
{
    if (sfImage_getPixel(defender->map_path, x, y - 1).b == 255)
        enemie_info->direction = (sfVector2f) {0, -1};
    else if (sfImage_getPixel(defender->map_path, x, y + 1).b == 255)
        enemie_info->direction = (sfVector2f) {0, 1};
}

void move_vertically(s_game *defender, s_enemie_info *enemie_info, \
unsigned int x, unsigned int y)
{
    if (sfImage_getPixel(defender->map_path, x + 1, y).b == 255)
        enemie_info->direction = (sfVector2f) {1, 0};
    else if (sfImage_getPixel(defender->map_path, x - 1, y).b == 255)
        enemie_info->direction = (sfVector2f) {-1, 0};
}

sfVector2f check_next_direction(s_game *defender, s_enemie_info *enemie_info)
{
    unsigned int x = sfSprite_getPosition(enemie_info->mob->sprite).x;
    unsigned int y = sfSprite_getPosition(enemie_info->mob->sprite).y;

    if (x >= 1700)
        return ((sfVector2f){1, 0});
    if (enemie_info->direction.x != 0)
        move_horizontally(defender, enemie_info, x, y);
    else if (enemie_info->direction.y != 0)
        move_vertically(defender, enemie_info, x, y);
    return (enemie_info->direction);
}

float get_start_y(s_game *defender, int pos_x)
{
    unsigned int y = -1;

    if (pos_x < 0)
        pos_x = 0;
    while (sfImage_getPixel(defender->map_path, \
    (unsigned int) pos_x, ++y).b != 255);
    return (y);
}