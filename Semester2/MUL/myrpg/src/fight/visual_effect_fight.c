/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** visual_effect_fight
*/

#include "rpg.h"

void modify_view_for_fight(sfView *zoom_view, game_t *rpg, enemie_info_t \
*enemie_info, int i)
{
    sfView_zoom(zoom_view, 0.95);
    sfSprite_setScale(rpg->play_infos->player->sprite, (sfVector2f) \
    {0.75 + (float) i / 80, 0.75 + (float) i / 80});
    sfSprite_setScale(enemie_info->mob->sprite, (sfVector2f) \
    {0.75 + (float) i / 80, 0.75 + (float) i / 80});
    sfView_setRotation(zoom_view, sfView_getRotation(zoom_view) + 9);
    sfRenderWindow_setView(rpg->window, zoom_view);
}

void zoom_before_fight(game_t *rpg, enemie_info_t *enemie_info)
{
    sfView *zoom_view = sfView_createFromRect((sfFloatRect) {0, 0, 3453, 1941});

    sfView_setCenter(zoom_view, sfView_getCenter(rpg->play_infos->map_view));
    sfView_zoom(zoom_view, 1/6.0);
    for (int i = 0; i < 20; i++) {
        sfRenderWindow_clear(rpg->window, sfTransparent);
        modify_view_for_fight(zoom_view, rpg, enemie_info, i);
        sfRenderWindow_drawSprite(rpg->window, \
        rpg->play_infos->playing_game->background->sprite, NULL);
        sfRenderWindow_drawSprite(rpg->window, \
        rpg->play_infos->player->sprite, NULL);
        sfRenderWindow_drawSprite(rpg->window, enemie_info->mob->sprite, NULL);
        sfRenderWindow_display(rpg->window);
    }
    sfRenderWindow_setView(rpg->window, rpg->play_infos->map_view);
    sfView_destroy(zoom_view);
}