/*
** EPITECH PROJECT, 2021
** RPG
** File description:
** particles
*/

#include "rpg.h"

sfCircleShape *create_circle_shape(snow_t *snow)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfCircleShape_setPosition(circle, snow->pos);
    sfCircleShape_setFillColor(circle, snow->color);
    sfCircleShape_setRadius(circle, snow->radius);
    return circle;
}

snow_t *snow_random(snow_t *snow)
{
    snow->pos.x = random_float(-1726.5, 1726.5);
    snow->pos.y = random_float(-970.5, 970.5);
    snow->speed.y = random_float(0.5, 1.5);
    snow->speed.x = random_float(0.1, 1.1);
    snow->color = sfWhite;
    snow->radius = random_float(0.2, 3.0);
    snow->circle = create_circle_shape(snow);
    return snow;
}

snow_t *create_snow(void)
{
    snow_t *snow = malloc(sizeof(snow_t));

    snow_random(snow);
    return snow;
}

void snow_update(snow_t *snow)
{
    if (sfCircleShape_getPosition(snow->circle).y > 1078.0)
        snow = snow_random(snow);
}

void snow_display(snow_t *snow, game_t *rpg)
{
    sfCircleShape_move(snow->circle, snow->speed);
    sfRenderWindow_drawCircleShape(rpg->window, snow->circle, NULL);
}