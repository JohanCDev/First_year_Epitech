/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-1.4-1-myrpg-tanguy.bellicha
** File description:
** events
*/

#include "rpg.h"

void escape_is_pressed(game_t *rpg)
{
    if (rpg->current_scene == rpg->play_infos->playing_game)
        rpg->current_scene = rpg->pause_menu;
    else if (rpg->current_scene == rpg->pause_menu)
        rpg->current_scene = rpg->play_infos->playing_game;
}

void mouse_is_moved(game_t *rpg)
{
    mouse_moved_in_menu(rpg, rpg->current_scene);
    if ((rpg->event.mouseMove.x > 1) && (rpg->event.mouseMove.x \
        < (int) sfRenderWindow_getSize(rpg->window).x) && \
        (rpg->event.mouseMove.y > 1) && (rpg->event.mouseMove.y \
        < (int) sfRenderWindow_getSize(rpg->window).y))
        sfSprite_setPosition(rpg->cursor->sprite, (sfVector2f) \
        {rpg->event.mouseMove.x, rpg->event.mouseMove.y});
    else
        sfSprite_setPosition(rpg->cursor->sprite, \
        (sfVector2f) {-50, -50});
}