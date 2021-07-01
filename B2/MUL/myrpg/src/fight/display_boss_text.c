/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-johan.chrillesen
** File description:
** display_boss_text
*/

#include "rpg.h"

void display_boss_text_not_enough(game_t *rpg, enemie_info_t *enemie_info, \
text_t *text)
{
    sfClock *clock = sfClock_create();

    while (sfClock_getElapsedTime(clock).microseconds < 3000000) {
        sfRenderWindow_clear(rpg->window, sfTransparent);
        sfRenderWindow_drawSprite(rpg->window, \
        rpg->current_scene->background->sprite, NULL);
        sfRenderWindow_drawSprite(rpg->window, \
        rpg->play_infos->player->sprite, NULL);
        sfRenderWindow_drawSprite(rpg->window, enemie_info->mob->sprite, \
        NULL);
        sfRenderWindow_drawText(rpg->window, text->text, NULL);
        sfRenderWindow_display(rpg->window);
    }
    sfClock_destroy(clock);
    destroy_texts(text);
}

int check_boss_fight(game_t *rpg, enemie_info_t *enemie_info)
{
    sfVector2f pos_text = {-1600, -15};
    text_t *text = init_text_str("./resources/font.ttf", \
    pos_text, "You didn't kill enough goblins", 20);

    sfText_setColor(text->text, sfBlack);
    if (!is_inventory_full(rpg->play_infos->player->inv) && \
    enemie_info->mob->rect.width < 30) {
        display_boss_text_not_enough(rpg, enemie_info, text);
        return (0);
    }
    return (1);
}