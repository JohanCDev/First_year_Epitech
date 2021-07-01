/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper1-maxime3.vincent
** File description:
** main
*/

#include "my.h"
#include "game.h"

int main(int argc, char **argv)
{
    game_t *game = NULL;

    if (argc != 3 || my_getnbr(argv[2]) < 0)
        return (84);
    else
        game = check_errors(argv);
    if (game == NULL || game->ret == 84)
        return (84);
    play_game(game, my_getnbr(argv[2]));
    my_printf("%t", game->map);
    return (0);
}