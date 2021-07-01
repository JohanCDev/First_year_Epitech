/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-tanguy.bellicha
** File description:
** button_is_clicked
*/

#include "my.h"
#include "defender.h"

void do_effect_clicked(s_button *button, s_game *defender)
{
    sfClock *clock = sfClock_create();
    sfColor colorClicked = {255, 255, 255, 100};
    sfColor colorBase = {255, 255, 255, 255};

    sfRectangleShape_setFillColor(button->rect, colorClicked);
    sfRectangleShape_setScale(button->rect, (sfVector2f) {0.9, 0.9});
    update_window(defender, 1);
    while (sfClock_getElapsedTime(clock).microseconds < 160000);
    sfRectangleShape_setFillColor(button->rect, colorBase);
    sfRectangleShape_setScale(button->rect, (sfVector2f) {1, 1});
    sfClock_destroy(clock);
}

void switch_button_clicked(s_button *button, s_game *defender)
{
    if (button->button_type != BOX_BUTTON)
        do_effect_clicked(button, defender);
    if (defender->current_scene == defender->infos)
        defender->current_scene = defender->menu;
    switch (button->button_type) {
    case QUIT_BUTTON :
        defender->ret = 1;
        break;
    case PLAY_BUTTON :
        defender->current_scene = defender->play_infos->playing_game;
        break;
    case HOME_BUTTON :
        reinitialize_all(defender);
        defender->current_scene = defender->menu;
        break;
    default :
        switch_button_clicked_second(button, defender);
    }
}

void switch_button_clicked_second(s_button *button, s_game *defender)
{
    switch (button->button_type) {
    case RESUME_BUTTON :
        defender->current_scene = defender->play_infos->playing_game;
        break;
    case INFOS_BUTTON :
        defender->current_scene = defender->infos;
        break;
    case MUSIC_BUTTON :
        if (sfMusic_getVolume(defender->musics->main_music) != 0)
            sfMusic_setVolume(defender->musics->main_music, 0);
        else if (sfMusic_getVolume(defender->musics->main_music) == 0)
            sfMusic_setVolume(defender->musics->main_music, 50);
        break;
    case BOX_BUTTON :
        use_box(defender);
        break;
    }
}

void button_is_clicked(s_game *defender, s_button *button, \
sfMouseButtonEvent mousePosition)
{
    sfFloatRect button_rect = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfFloatRect_contains(&button_rect, mousePosition.x, mousePosition.y)) {
        switch_button_clicked(button, defender);
        sfMusic_stop(defender->musics->button_sound);
        sfMusic_play(defender->musics->button_sound);
    }
}