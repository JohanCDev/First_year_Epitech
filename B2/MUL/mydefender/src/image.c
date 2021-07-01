/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-tanguy.bellicha
** File description:
** image
*/

#include "my.h"
#include "defender.h"

bool get_red_pixel(int *pix, sfImage *map_path, sfSprite *sprite, int pos_x)
{
    while (pix[0] <= pos_x + (int) sfSprite_getGlobalBounds(sprite).width)
        if (sfImage_getPixel(map_path, pix[0]++, pix[1]).r == 255)
            return (false);
    return (true);
}

bool check_placement(int *pix, sfMouseButtonEvent pos, sfSprite *sprite, \
sfImage *map_path)
{
    while (pix[1] <= pos.y + (int) sfSprite_getGlobalBounds(sprite).height) {
        if (!get_red_pixel(pix, map_path, sprite, pos.x))
            return (false);
        pix[0] = pos.x;
        pix[1]++;
    }
    pix[0] = pos.x;
    pix[1] = pos.y;
    return (true);
}

void draw_tower_on_image(int *pix, sfMouseButtonEvent pos, sfSprite *sprite, \
sfImage *map_path)
{
    while (pix[1] <= pos.y + (int) sfSprite_getGlobalBounds(sprite).height) {
        while (pix[0] <= pos.x + (int) sfSprite_getGlobalBounds(sprite).width)
            sfImage_setPixel(map_path, pix[0]++, pix[1], \
            (sfColor){255, 0, 0, 255});
        pix[0] = pos.x;
        pix[1]++;
    }
}

bool can_tower_be_placed(sfImage *map_path, sfSprite *sprite, \
sfMouseButtonEvent pos)
{
    int *pix = malloc(sizeof(int) * 2);
    pix[0] = pos.x;
    pix[1] = pos.y;

    if (!check_placement(pix, pos, sprite, map_path))
        return (false);
    draw_tower_on_image(pix, pos, sprite, map_path);
    return (true);
}