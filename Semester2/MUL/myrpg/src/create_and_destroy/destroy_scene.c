/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-johan.chrillesen
** File description:
** destroy_scene
*/

#include "rpg.h"

void destroy_buttons_texts_objs_array(scene_t *scene, bool buttons, \
bool texts, bool objs)
{
    if (buttons)
        for (int i = 0; scene->buttons[i]; i++) {
            sfRectangleShape_destroy(scene->buttons[i]->rect);
            sfTexture_destroy(scene->buttons[i]->texture);
        }
    if (texts)
        for (int i = 0; scene->texts[i]; i++) {
            sfText_destroy(scene->texts[i]->text);
            sfFont_destroy(scene->texts[i]->font);
        }
    if (objs)
        for (int i = 0; scene->objs[i]; i++)
            destroy_object(scene->objs[i]);
}

void destroy_scene(scene_t *scene, bool buttons, bool texts, bool objs)
{
    destroy_buttons_texts_objs_array(scene, buttons, texts, objs);
    if (scene->buttons != NULL) {
        free(scene->buttons);
        scene->buttons = NULL;
    }
    if (scene->texts != NULL) {
        free(scene->texts);
        scene->texts = NULL;
    }
    if (scene->objs != NULL) {
        free(scene->objs);
        scene->objs = NULL;
    }
    if (scene != NULL) {
        free(scene);
        scene = NULL;
    }
}

void destroy_enemies(enemies_t *enemy)
{
    enemies_t *current = enemy;

    while (current != NULL) {
        sfClock_destroy(current->enemie_info->clock);
        destroy_object(current->enemie_info->mob);
        free(current->enemie_info);
        current = current->next;
    }
    free(current);
}

void destroy_game(s_playing *playing_game)
{
    destroy_scene(playing_game->playing_game, 0, 0, 0);
    sfView_destroy(playing_game->map_view);
    sfImage_destroy(playing_game->hitboxes);
    destroy_player(playing_game->player);
    if (playing_game->player != NULL) {
        free(playing_game->player);
        playing_game->player = NULL;
    }
    sfClock_destroy(playing_game->main_clock);
    if (playing_game != NULL) {
        free(playing_game);
        playing_game = NULL;
    }
}