/*
** EPITECH PROJECT, 2021
** My_defender
** File description:
** window
*/

#include "defender.h"
#include "my.h"

sfRenderWindow *initialize_window(void)
{
    int width = 1600;
    int height = 900;

    sfVideoMode mode = {width, height, 32};
    sfRenderWindow *window = sfRenderWindow_create\
    (mode, "myDefender", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

void display_buttons_and_objects(s_scene *scene, sfRenderWindow *win)
{
    int i = -1;
    int k = -1;

    while (scene->objs[++k])
        sfRenderWindow_drawSprite(win, scene->objs[k]->sprite, NULL);
    while (scene->buttons[++i])
        sfRenderWindow_drawRectangleShape(win, scene->buttons[i]->rect, NULL);
}

void display_sprites_and_texts(s_game *defender, sfRenderWindow *win)
{
    int i = -1;
    int m = -1;

    while (defender->play_infos->show_menu && \
    defender->play_infos->market_list[++i]) {
        sfRenderWindow_drawSprite(defender->window, \
        defender->play_infos->market_list[i]->sprite, NULL);
    }
    while (defender->play_infos->playing_game->texts[++m]) {
        sfRenderWindow_drawText(win, \
        defender->play_infos->playing_game->texts[m]->text, NULL);
    }
}

void update_playing_game(s_game *defender, sfRenderWindow *win, s_scene *scene)
{
    display_enemies(defender);
    display_towers(defender);
    display_buttons_and_objects(scene, win);
    display_sprites_and_texts(defender, win);
    display_wave_chrono(defender);
}

void update_window(s_game *defender, int display)
{
    sfRenderWindow *win = defender->window;
    s_scene *scene = defender->current_scene;

    sfRenderWindow_clear(win, sfTransparent);
    sfRenderWindow_drawSprite(win, scene->background->sprite, NULL);
    if (scene == defender->play_infos->playing_game)
        update_playing_game(defender, win, scene);
    else
        display_buttons_and_objects(scene, win);
    if (scene == defender->scoreboard)
        sfRenderWindow_drawText(win, \
        defender->scoreboard->texts[0]->text, NULL);
    if (display)
        sfRenderWindow_drawSprite(win, defender->cursor->sprite, NULL);
    sfRenderWindow_display(win);
}