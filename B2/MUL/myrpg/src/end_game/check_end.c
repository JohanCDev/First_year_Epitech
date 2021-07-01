/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-johan.chrillesen
** File description:
** check_end
*/

#include "rpg.h"

void display_final_text(game_t *rpg, char const *str, sfColor color)
{
    sfClock *clock = sfClock_create();
    text_t *text = init_text_str("./resources/font.ttf", \
    (sfVector2f){750, 500}, (char *)str, 100);

    sfText_setColor(text->text, color);
    sfRenderWindow_setView(rpg->window, rpg->play_infos->default_view);
    while (sfClock_getElapsedTime(clock).microseconds < 5000000) {
        sfRenderWindow_clear(rpg->window, sfTransparent);
        sfRenderWindow_drawSprite(rpg->window, rpg->menu->background->sprite, \
        NULL);
        sfRenderWindow_drawText(rpg->window, text->text, NULL);
        sfRenderWindow_display(rpg->window);
    }
    destroy_texts(text);
    reinitialize_all(rpg);
    rpg->current_scene = rpg->menu;
}

void check_boss_is_dead(game_t *rpg)
{
    enemies_t *current = rpg->play_infos->enemies;
    int ret = 0;

    while (current) {
        if (current->enemie_info->mob->rect.width < 30 && \
            current->enemie_info->life <= 0)
            ret = 1;
        else if (current->enemie_info->mob->rect.width < 30 && \
            current->enemie_info->life > 0 && \
            rpg->play_infos->player->life <= 0)
            ret = 2;
        current = current->next;
    }
    if (ret == 1)
        display_final_text(rpg, "You won OMG", sfGreen);
    else if (ret == 2)
        display_final_text(rpg, "You lost snif", sfRed);
}