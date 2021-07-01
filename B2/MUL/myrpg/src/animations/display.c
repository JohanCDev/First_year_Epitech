/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** display
*/

#include "rpg.h"

void change_rects_enemies(enemies_t *iterator)
{
    if (iterator->enemie_info->mob->rect.width == 33)
        move_rect(&iterator->enemie_info->mob->rect, 33, 132);
    else if (iterator->enemie_info->mob->rect.width == 26)
        move_rect(&iterator->enemie_info->mob->rect, 26, 104);
}

void display_enemies(game_t *rpg)
{
    enemies_t *iterator = rpg->play_infos->enemies;

    while (iterator != NULL) {
        if (sfClock_getElapsedTime(iterator->enemie_info->clock).\
        microseconds > 160000) {
            change_rects_enemies(iterator);
            sfSprite_setTextureRect(iterator->enemie_info->mob->sprite,
            iterator->enemie_info->mob->rect);
            sfClock_restart(iterator->enemie_info->clock);
        }
        if (iterator->enemie_info->life > 0)
            sfRenderWindow_drawSprite(rpg->window, \
            iterator->enemie_info->mob->sprite, NULL);
        iterator = iterator->next;
    }
}

void display_other(game_t *rpg, sfRenderWindow *win)
{
    sfRenderWindow_setMouseCursorVisible(rpg->window, 0);
    sfRenderWindow_drawSprite(win, rpg->cursor->sprite, NULL);
}