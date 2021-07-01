/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share
** File description:
** destroy
*/

#include "rpg.h"

void destroy_player(player_t *player)
{
    sfClock_destroy(player->clock);
    sfSprite_destroy(player->sprite);
    destroy_object(player->heart);
    sfTexture_destroy(player->textures->idle);
    sfTexture_destroy(player->textures->run);
    if (player->textures != NULL) {
        free(player->textures);
        player->textures = NULL;
    }
}

void destroy_object(game_object_t *object)
{
    sfSprite_destroy(object->sprite);
    sfTexture_destroy(object->texture);
    if (object != NULL) {
        free(object);
        object = NULL;
    }
}

void destroy_backgrounds(game_t *rpg)
{
    destroy_object(rpg->menu->background);
    destroy_object(rpg->play_infos->playing_game->background);
    destroy_object(rpg->infos->background);
    destroy_object(rpg->fight->background);
}

void free_quests(game_t *rpg)
{
    free(rpg->quests->travel);
    free(rpg->quests);
}

void destroy_all(game_t *rpg)
{
    destroy_musics(rpg->musics);
    free(rpg->musics);
    destroy_backgrounds(rpg);
    destroy_scene(rpg->menu, 1, 0, 0);
    destroy_object(rpg->cursor);
    destroy_enemies(rpg->play_infos->enemies);
    destroy_game(rpg->play_infos);
    destroy_scene(rpg->pause_menu, 1, 0, 0);
    destroy_scene(rpg->infos, 0, 0, 0);
    destroy_scene(rpg->fight, 1, 1, 0);
    destroy_scene(rpg->inventory, 0, 1, 1);
    sfImage_destroy(rpg->map_path);
    destroy_particles(rpg->particles);
    free(rpg->particles);
    free_quests(rpg);
    sfRenderWindow_close(rpg->window);
    sfRenderWindow_destroy(rpg->window);
    free_snow(rpg->snow);
    free(rpg);
}