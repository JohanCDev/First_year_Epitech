/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share
** File description:
** events
*/

#include "rpg.h"

void reset_after_movement(game_t *rpg, sfVector2f move)
{
    rpg->play_infos->player->offset = 45;
    rpg->play_infos->player->max_value = 360;
    sfView_move(rpg->play_infos->map_view, move);
    sfSprite_move(rpg->play_infos->player->sprite, move);
}

sfVector2f execute_movement(game_t *rpg)
{
    sfVector2f move = {0, 0};
    if (rpg->play_infos->key_pressed.go_up)
        move.y = -5;
    if (rpg->play_infos->key_pressed.go_right)
        move.x = 5;
    if (rpg->play_infos->key_pressed.go_down)
        move.y = 5;
    if (rpg->play_infos->key_pressed.go_left)
        move.x = -5;
    if (check_if_can_move(rpg->play_infos->map_view, \
        rpg->play_infos->hitboxes, move, rpg) == 0)
        return ((sfVector2f) {0, 0});
    if (rpg->play_infos->player->rect.width != 45) {
        rpg->play_infos->player->rect.left = 0;
        rpg->play_infos->player->rect = create_rect(0, 0, 45, 54);
    } rpg->play_infos->player->offset = 45;
    rpg->play_infos->player->max_value = 360;
    sfView_move(rpg->play_infos->map_view, move);
    sfSprite_move(rpg->play_infos->player->sprite, move);
    return (move);
}

void key_is_released(game_t *rpg)
{
    rpg->play_infos->player->rect = create_rect(0, 0, 31, 54);
    rpg->play_infos->player->offset = 31;
    rpg->play_infos->player->max_value = 248;
    sfSprite_setTexture(rpg->play_infos->player->sprite, \
    rpg->play_infos->player->textures->idle, sfFalse);
    if (rpg->event.key.code == sfKeyZ)
        rpg->play_infos->key_pressed.go_up = false;
    if (rpg->event.key.code == sfKeyD)
        rpg->play_infos->key_pressed.go_right = false;
    if (rpg->event.key.code == sfKeyS)
        rpg->play_infos->key_pressed.go_down = false;
    if (rpg->event.key.code == sfKeyQ)
        rpg->play_infos->key_pressed.go_left = false;
}