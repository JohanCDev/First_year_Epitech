/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myrunner-johan.chrillesen
** File description:
** game
*/

#include "my.h"
#include "runner.h"

void switch_key_pressed(game_s *game)
{
    switch (game->window.event.key.code) {
        case sfKeySpace :
            jump(game);
            break;
        case sfKeyC :
            sfSprite_setColor(game->player->sprite, \
            sfColor_fromRGB(rand() % 255, rand() % 255, rand() % 255));
            break;
        case sfKeyE :
            finish_game(game);
            game->ret = 5;
            break;
        case sfKeyW :
            finish_game(game);
            game->ret = 5;
        default :
            break;
    }
}

void switch_event(game_s *game)
{
    switch (game->window.event.type) {
        case sfEvtClosed :
            sfRenderWindow_close(game->window.window);
            break;
        case sfEvtKeyPressed :
            switch_key_pressed(game);
            break;
        default :
            break;
    }
}

void animate_game(game_s *game, sfClock *clock, sfClock *obstacles_clock, \
int read_map)
{
    if (sfClock_getElapsedTime(clock).microseconds > 100000.0) {
        move_rect(&game->player->rect, game->player->rect.width, 240);
        sfSprite_setTextureRect(game->player->sprite, game->player->rect);
        sfClock_restart(clock);
    }
    if (sfClock_getElapsedTime(obstacles_clock).microseconds > 1000000.0) {
        do_obstacles(game, read_map);
        sfClock_restart(obstacles_clock);
    }
}

int start_game(game_s *game)
{
    sfClock *clock = sfClock_create();
    int read_map = 1;
    sfClock *obstacles_clock = sfClock_create();

    game->window = create_window("My_runner");
    create_parallax(game);
    while (sfRenderWindow_isOpen(game->window.window)) {
        while (sfRenderWindow_pollEvent(game->window.window, \
        &game->window.event))
            switch_event(game);
        if (game->ret != 5)
            display_all(game);
        else
            finish_game(game);
        animate_game(game, clock, obstacles_clock, read_map);
        game->score.score++;
    }
    destroy_all(game, clock);
    return (0);
}