/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-johan.chrillesen
** File description:
** initialize_and_end_fight
*/

#include "rpg.h"

void end_fight(game_t *rpg, t_tmp_fight tmp, enemie_info_t *enemy_info)
{
    sfSprite_setScale(rpg->play_infos->player->sprite, tmp.tmp_sc_player);
    sfSprite_setPosition(rpg->play_infos->player->sprite, tmp.tmp_pos_player);
    sfSprite_setScale(enemy_info->mob->sprite, tmp.tmp_sc_enn);
    sfSprite_setPosition(enemy_info->mob->sprite, tmp.tmp_pos_enn);
    sfRenderWindow_setView(rpg->window, rpg->play_infos->map_view);
}

t_tmp_fight initialize_fight(game_t *rpg, enemie_info_t *enemie_info, \
sfVector2f scale)
{
    t_tmp_fight tmp = {sfSprite_getScale(rpg->play_infos->player->sprite), \
        sfSprite_getScale(enemie_info->mob->sprite), \
        sfSprite_getPosition(rpg->play_infos->player->sprite), \
        sfSprite_getPosition(enemie_info->mob->sprite)};

    zoom_before_fight(rpg, enemie_info);
    sfSprite_setPosition(rpg->play_infos->player->sprite, \
    (sfVector2f){350, 750});
    sfSprite_setPosition(enemie_info->mob->sprite, (sfVector2f){1500, 850});
    sfSprite_setScale(rpg->play_infos->player->sprite, \
    (sfVector2f){4.0, 4.0});
    if (scale.x == 0.75)
        sfSprite_setScale(enemie_info->mob->sprite, (sfVector2f){-4.0, 4.0});
    else if (scale.x == 1.5)
        sfSprite_setScale(enemie_info->mob->sprite, (sfVector2f){-6.0, 6.0});
    rpg->current_scene = rpg->fight;
    return (tmp);
}

void move_other_rectangles(game_t *rpg)
{
    if (sfClock_getElapsedTime(rpg->particles->clock).microseconds > 90000) {
        move_rect(&rpg->particles->particle->rect, 90, 1440);
        sfSprite_setTextureRect(rpg->particles->particle->sprite, \
        rpg->particles->particle->rect);
        sfClock_restart(rpg->particles->clock);
        rpg->particles->current_sprite++;
    }
}

void move_rectangles_for_fight(game_t *rpg, enemie_info_t *enemie_info)
{
    if (sfClock_getElapsedTime(rpg->play_infos->player->clock).microseconds > \
    100000) {
        move_rect(&rpg->play_infos->player->rect, \
        rpg->play_infos->player->offset, rpg->play_infos->player->max_value);
        sfSprite_setTextureRect(rpg->play_infos->player->sprite, \
        rpg->play_infos->player->rect);
        sfClock_restart(rpg->play_infos->player->clock);
    }
    if (sfClock_getElapsedTime(enemie_info->clock).microseconds > 100000) {
        if (enemie_info->mob->rect.width == 33)
            move_rect(&enemie_info->mob->rect, 33, 132);
        else if (enemie_info->mob->rect.width == 26)
            move_rect(&enemie_info->mob->rect, 26, 104);
        sfSprite_setTextureRect(enemie_info->mob->sprite, \
        enemie_info->mob->rect);
        sfClock_restart(enemie_info->clock);
    }
    move_other_rectangles(rpg);
}
