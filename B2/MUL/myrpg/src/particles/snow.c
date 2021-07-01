/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** snow
*/

#include "rpg.h"

snow_t **init_snow(game_t *rpg)
{
    rpg->snow = malloc(sizeof(snow_t) * 1000);
    for (unsigned int i = 0; i < 1000; i++)
        rpg->snow[i] = create_snow();
    return rpg->snow;
}

void free_snow(snow_t **snow)
{
    for (int i = 0; i < 1000; i++)
        free(snow[i]);
    free(snow);
}

void snow_fall(game_t *rpg, snow_t **snow)
{
    for (int i = 0; i < 1000; i++) {
        snow_update(snow[i]);
        snow_display(snow[i], rpg);
    }
}