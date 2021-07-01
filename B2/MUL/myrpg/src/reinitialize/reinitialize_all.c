/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-johan.chrillesen
** File description:
** reinitialize_all
*/

#include "rpg.h"

void reset_player(player_t *player)
{
    player->life = 100;
    player->attack_value = 25;
    player->map_pos = (sfVector2f){1726, 970};
    player->pos = (sfVector2f){0, 120};
    sfSprite_setPosition(player->sprite, player->pos);
    sfSprite_setScale(player->sprite, (sfVector2f){0.75, 0.75});
}

void reset_view(game_t *rpg)
{
    sfView_destroy(rpg->play_infos->map_view);
    rpg->play_infos->map_view = \
    sfView_createFromRect((sfFloatRect) {0, 0, 3453, 1941});
    sfView_setCenter(rpg->play_infos->map_view, (sfVector2f){0, 120});
    sfView_zoom(rpg->play_infos->map_view, 1/6.0);
    sfRenderWindow_setView(rpg->window, rpg->play_infos->map_view);
}

void reset_enemies(game_t *rpg)
{
    enemies_t *current = rpg->play_infos->enemies;

    while (current != NULL) {
        if (current->enemie_info->mob->rect.width == 33) {
            current->enemie_info->life = 50;
        } else
            current->enemie_info->life = 200;
        current = current->next;
    }
}

void reinitialize_all(game_t *rpg)
{
    reset_view(rpg);
    reset_player(rpg->play_infos->player);
    reset_enemies(rpg);
    reset_quests(rpg->quests, rpg);
    reset_inventory(rpg);
}