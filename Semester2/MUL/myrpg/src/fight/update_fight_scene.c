/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-johan.chrillesen
** File description:
** update_fight_scene
*/

#include "rpg.h"

void display_fight_particles(game_t *rpg, enemie_info_t *enemie_info)
{
    if (rpg->particles->display == true) {
        sfClock_restart(rpg->particles->clock);
        rpg->particles->current_sprite = 0;
        while (rpg->particles->current_sprite < 12) {
            move_rectangles_for_fight(rpg, enemie_info);
            sfRenderWindow_drawSprite(rpg->window, \
            rpg->particles->particle->sprite, NULL);
            sfRenderWindow_display(rpg->window);
        }
    }
}

void update_fight_scene(game_t *rpg, enemie_info_t *enemie_info)
{
    sfRenderWindow_clear(rpg->window, sfTransparent);
    sfRenderWindow_setView(rpg->window, rpg->play_infos->default_view);
    sfText_setString(rpg->fight->texts[1]->text, my_itoa(enemie_info->life));
    sfText_setString(rpg->fight->texts[0]->text, \
    my_itoa(rpg->play_infos->player->life));
    sfRenderWindow_drawSprite(rpg->window, \
    rpg->fight->background->sprite, NULL);
    for (int i = 0; i < 3; i++) {
        sfText_setColor(rpg->fight->texts[i]->text, sfRed);
        sfRenderWindow_drawText(rpg->window, rpg->fight->texts[i]->text, NULL);
    }
    move_rectangles_for_fight(rpg, enemie_info);
    sfRenderWindow_drawSprite(rpg->window, rpg->play_infos->player->sprite, \
    NULL);
    sfRenderWindow_drawSprite(rpg->window, enemie_info->mob->sprite, NULL);
    display_fight_particles(rpg, enemie_info);
    sfRenderWindow_display(rpg->window);
}