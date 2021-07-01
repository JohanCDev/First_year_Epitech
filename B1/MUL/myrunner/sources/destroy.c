/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myrunner-johan.chrillesen
** File description:
** destroy
*/

#include "runner.h"
#include "my.h"

void destroy_musics(game_s *game)
{
    sfMusic_destroy(game->music);
    sfMusic_destroy(game->jump_sound);
    sfMusic_destroy(game->game_over);
    sfMusic_destroy(game->win_music);
}

void destroy_object(object_s *object)
{
    sfSprite_destroy(object->sprite);
    sfTexture_destroy(object->texture);
    free(object);
}

void destroy_all(game_s *game, sfClock *clock)
{
    destroy_object(game->player);
    destroy_object(game->front_bg);
    destroy_object(game->mid_bg);
    destroy_object(game->player_win);
    destroy_object(game->ground);
    destroy_musics(game);
    sfRenderWindow_destroy(game->window.window);
    free(game);
    sfClock_destroy(clock);
}