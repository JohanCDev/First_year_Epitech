/*
** EPITECH PROJECT, 2021
** My_rpg
** File description:
** window
*/

#include "rpg.h"

void display_buttons_and_objects(scene_t *scene, sfRenderWindow *win)
{
    int i = -1;
    int k = -1;

    while (scene->objs[++k])
        sfRenderWindow_drawSprite(win, scene->objs[k]->sprite, NULL);
    while (scene->buttons[++i])
        sfRenderWindow_drawRectangleShape(win, scene->buttons[i]->rect, NULL);
}

void display_sprites_and_texts(game_t *rpg, sfRenderWindow *win)
{
    int m = -1;

    while (rpg->play_infos->playing_game->texts[++m]) {
        sfRenderWindow_drawText(win, \
        rpg->play_infos->playing_game->texts[m]->text, NULL);
    }
}

void update_playing_game(game_t *rpg, sfRenderWindow *win)
{
    player_t *player = rpg->play_infos->player;

    if (sfClock_getElapsedTime(player->clock).microseconds > 100000) {
        move_rect(&player->rect, player->offset, player->max_value);
        sfSprite_setTextureRect(player->sprite, player->rect);
        sfClock_restart(player->clock);
    }
    snow_fall(rpg, rpg->snow);
    sfRenderWindow_drawSprite(win, player->sprite, NULL);
    display_enemies(rpg);
}

void update_window(game_t *rpg, int display)
{
    sfRenderWindow *win = rpg->window;
    scene_t *scene = rpg->current_scene;

    if (rpg->current_scene == rpg->fight)
        return;
    sfRenderWindow_clear(win, sfTransparent);
    if (scene == rpg->play_infos->playing_game)
        sfRenderWindow_setView(win, rpg->play_infos->map_view);
    else
        sfRenderWindow_setView(win, rpg->play_infos->default_view);
    sfRenderWindow_drawSprite(win, scene->background->sprite, NULL);
    if (scene == rpg->play_infos->playing_game)
        update_playing_game(rpg, win);
    display_buttons_and_objects(scene, win);
    if (scene == rpg->inventory)
        display_inventory(rpg, rpg->play_infos->player->inv, win);
    if (display && scene != rpg->play_infos->playing_game)
        display_other(rpg, win);
    else if (scene == rpg->play_infos->playing_game)
        sfRenderWindow_setMouseCursorVisible(rpg->window, 1);
    sfRenderWindow_display(win);
}