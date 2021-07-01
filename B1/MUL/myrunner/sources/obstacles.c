/*
** EPITECH PROJECT, 2021
** B-MUL-100-NAN-1-1-myrunner-johan.chrillesen
** File description:
** obstacles
*/

#include "my.h"
#include "runner.h"

void switch_map_part2(game_s *game)
{
    sfVector2f size = {1.2, 1.2};

    switch (*game->map) {
        case '3' :
            add_in_linked_list(game, create_object(\
            "resources/images/enemies/bird.png",
            create_vector(1955, 865), create_rect(0, 0, 88, 60), size));
            break;
        case '4' :
            add_in_linked_list(game, create_object( \
            "resources/images/enemies/bird.png", \
            create_vector(1955, 769), create_rect(0, 0, 84, 47), size));
            break;
        case '5' :
            game->win = 1;
            finish_game(game);
            break;
        default :
            break;
    }
}

void switch_map(game_s *game)
{
    sfVector2f size = {1.5, 1.5};

    switch (*game->map) {
        case '1' :
            add_in_linked_list(game, create_object(\
            "./resources/images/enemies/small_cactus.png", \
            create_vector(1955, 834), create_rect(0, 0, 31, 68), size));
            break;
        case '2' :
            add_in_linked_list(game, create_object(\
            "./resources/images/enemies/big_cactus.png", \
            create_vector(1955, 800), create_rect(0, 0, 46, 96), size));
            break;
        default :
            switch_map_part2(game);
    }
}

void do_obstacles(game_s *game, int read_map)
{
    if (read_map) {
        switch_map(game);
        game->map++;
    }
}