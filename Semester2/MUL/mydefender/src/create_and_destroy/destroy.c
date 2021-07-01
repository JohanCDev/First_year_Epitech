/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share
** File description:
** destroy
*/

#include "defender.h"
#include "my.h"

void destroy_menu(s_game *defender)
{
    for (int i = 0; defender->menu->buttons[i]; i++) {
        sfRectangleShape_destroy(defender->menu->buttons[i]->rect);
        sfTexture_destroy(defender->menu->buttons[i]->texture);
    }
    if (defender->menu->buttons != NULL) {
        free(defender->menu->buttons);
        defender->menu->buttons = NULL;
    }
    if (defender->menu != NULL) {
        free(defender->menu);
        defender->menu = NULL;
    }
}

void destroy_object(s_game_object *object)
{
    sfSprite_destroy(object->sprite);
    sfTexture_destroy(object->texture);
    if (object != NULL) {
        free(object);
        object = NULL;
    }
}

void destroy_musics(s_musics *musics)
{
    if (musics->button_sound)
        sfMusic_destroy(musics->button_sound);
    if (musics->main_music)
        sfMusic_destroy(musics->main_music);
    if (musics->buying_sound)
        sfMusic_destroy(musics->buying_sound);
}

void destroy_all(s_game *defender)
{
    destroy_musics(defender->musics);
    destroy_menu(defender);
    destroy_object(defender->cursor);
    sfRenderWindow_close(defender->window);
    sfRenderWindow_destroy(defender->window);
}