/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myrunner-johan.chrillesen
** File description:
** initialize_project
*/

#include "my.h"
#include "runner.h"

int detect_args(char **argv, game_s *game, int display)
{
    if (!my_strcmp(argv[1], "-h")) {
        if (display == 1) {
            my_putstr("\nRunner created with CSFML\n\n");
            my_putstr("USAGE\n");
            my_putstr("\t./my_runner map.txt\n\n");
            my_putstr("INTERACTIONS\n");
            my_putstr("\tSPACE\t\tjump\n\n");
            my_putstr("\tC KEY\t\tchange randomly the color of the dino\n\n");
            return (1);
        }
        destroy_musics(game);
        return (1);
    } else {
        game = create_map(game, argv[1]);
        if (game->ret == 84)
            return (84);
        return (2);
    }
}

int check_params(int argc, char **argv, game_s *game, int display)
{
    if (argc == 2) {
        return (detect_args(argv, game, display));
    } else {
        my_put_error("Bad arguments, try with ./my_runner -h\n");
        return (84);
    }
}

int check_problems(int argc, char **argv, game_s *game, int display)
{
    if (game->player == NULL || game->player_win == NULL) {
        my_put_error("Failed to created object\n");
        return (84);
    }
    return (check_params(argc, argv, game, display));
}