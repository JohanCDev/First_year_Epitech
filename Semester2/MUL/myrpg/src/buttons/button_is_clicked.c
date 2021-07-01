/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-tanguy.bellicha
** File description:
** button_is_clicked
*/


#include "rpg.h"

void do_effect_clicked(button_t *button, game_t *rpg)
{
    sfClock *clock = sfClock_create();
    sfColor colorClicked = {255, 255, 255, 100};
    sfColor colorBase = {255, 255, 255, 255};

    sfRectangleShape_setFillColor(button->rect, colorClicked);
    sfRectangleShape_setScale(button->rect, (sfVector2f) {0.9, 0.9});
    sfRectangleShape_setTextureRect(button->rect, \
    (sfIntRect){483, 0, 243, 230});
    update_window(rpg, 1);
    while (sfClock_getElapsedTime(clock).microseconds < 160000);
    sfRectangleShape_setFillColor(button->rect, colorBase);
    sfRectangleShape_setScale(button->rect, (sfVector2f) {1, 1});
    sfRectangleShape_setTextureRect(button->rect, \
    (sfIntRect){243, 0, 243, 230});
    sfClock_destroy(clock);
}

void switch_button_clicked(button_t *button, game_t *rpg)
{
    do_effect_clicked(button, rpg);
    if (rpg->current_scene == rpg->infos)
        rpg->current_scene = rpg->menu;
    switch (button->button_type) {
    case QUIT_BUTTON :
        rpg->ret = 1;
        break;
    case PLAY_BUTTON :
        rpg->current_scene = rpg->play_infos->playing_game;
        break;
    case HOME_BUTTON :
        reinitialize_all(rpg);
        rpg->current_scene = rpg->menu;
        break;
    default :
        switch_button_clicked_second(button, rpg);
    }
}

void switch_button_clicked_second(button_t *button, game_t *rpg)
{
    switch (button->button_type) {
    case RESUME_BUTTON :
        rpg->current_scene = rpg->play_infos->playing_game;
        break;
    case INFOS_BUTTON :
        rpg->current_scene = rpg->infos;
        break;
    case MUSIC_BUTTON :
        if (sfMusic_getVolume(rpg->musics->main_music) != 0)
            sfMusic_setVolume(rpg->musics->main_music, 0);
        else if (sfMusic_getVolume(rpg->musics->main_music) == 0)
            sfMusic_setVolume(rpg->musics->main_music, 50);
        break;
    default:
        break;
    }
}

bool button_is_clicked(game_t *rpg, button_t *button, \
sfMouseButtonEvent mousePosition)
{
    sfFloatRect button_rect = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfFloatRect_contains(&button_rect, mousePosition.x, mousePosition.y)) {
        switch_button_clicked(button, rpg);
        sfMusic_stop(rpg->musics->button_sound);
        sfMusic_play(rpg->musics->button_sound);
        return (true);
    }
    return (false);
}