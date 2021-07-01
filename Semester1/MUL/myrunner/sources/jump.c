/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myrunner-johan.chrillesen
** File description:
** jump
*/

#include "my.h"
#include "runner.h"

void display_jump(game_s *game, int i, int up)
{
    move_rect(&game->player->rect, game->player->rect.width, 240);
    sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    if (up) {
        game->player->position = change_position(game->player->position.x, \
        game->player->position.y - i * 2);
    } else {
        game->player->position = change_position(game->player->position.x, \
        game->player->position.y + i * 2);
    }
    sfSprite_setPosition(game->player->sprite, game->player->position);
    game->score.score++;
    display_all(game);
}

void jump(game_s *game)
{
    sfMusic_play(game->jump_sound);
    for (int i = 10; i < 20; i++) {
        display_jump(game, i, 1);
    }
    sfMusic_stop(game->jump_sound);
    for (int i = 10; i < 20; i++) {
        display_jump(game, i, 0);
    }
    do_obstacles(game, 1);
}