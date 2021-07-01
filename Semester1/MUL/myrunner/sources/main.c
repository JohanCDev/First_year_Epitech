/*
** EPITECH PROJECT, 2020
** bsmyrunner
** File description:
** main
*/

#include "my.h"
#include "runner.h"

int switch_problems(int argc, char **argv, game_s *game, int display)
{
    switch (check_problems(argc, argv, game, display)) {
        case 1 :
            return (0);
        case 84 :
            return (84);
        default :
            return (1);
    }
}

void initialize_music(game_s *game)
{
    game->game_over = sfMusic_createFromFile("resources/sounds/game_over.flac");
    game->music = sfMusic_createFromFile("resources/sounds/sound.flac");
    game->jump_sound = sfMusic_createFromFile("resources/sounds/jump.flac");
    game->win_music = sfMusic_createFromFile("resources/sounds/win_sound.flac");
    sfMusic_play(game->music);
    sfMusic_setLoop(game->music, sfTrue);
    sfMusic_setLoop(game->win_music, sfTrue);
    sfMusic_setLoop(game->game_over, sfTrue);
    sfMusic_setVolume(game->music, 75);
    sfMusic_setVolume(game->game_over, 75);
    sfMusic_setVolume(game->win_music, 75);
}

int main(int argc, char **argv)
{
    game_s *game = malloc(sizeof(*game));
    game->enemies = malloc(sizeof(*game->enemies));
    game->score.score = 0;
    game->win = 2;

    game->player = create_object("resources/images/player/player.png", \
    create_vector(250 , 850), create_rect(0, 0, 80 , 86), create_vector(1, 1));
    game->player_win = create_object("resources/images/player/dino_win.png", \
    create_vector(250 , 850), create_rect(0, 0, 80 , 112), \
    create_vector(1, 1));
    initialize_music(game);
    if (switch_problems(argc, argv, game, 1) != 1)
        return (switch_problems(argc, argv, game, 0));
    start_game(game);
    return (0);
}