/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-tanguy.bellicha
** File description:
** events
*/

#include "my.h"
#include "defender.h"

void escape_is_pressed(s_game *defender)
{
    if (defender->current_scene == defender->play_infos->playing_game)
        defender->current_scene = defender->pause_menu;
    else if (defender->current_scene == defender->pause_menu)
        defender->current_scene = defender->play_infos->playing_game;
}

void mouse_is_moved(s_game *defender)
{
    mouse_moved_in_menu(defender, defender->current_scene);
    if ((defender->event.mouseMove.x > 1) && (defender->event.mouseMove.x \
        < (int) sfRenderWindow_getSize(defender->window).x) && \
        (defender->event.mouseMove.y > 1) && (defender->event.mouseMove.y \
        < (int) sfRenderWindow_getSize(defender->window).y))
        sfSprite_setPosition(defender->cursor->sprite, (sfVector2f) \
        {defender->event.mouseMove.x, defender->event.mouseMove.y});
    else
        sfSprite_setPosition(defender->cursor->sprite, \
        (sfVector2f) {-50, -50});
}