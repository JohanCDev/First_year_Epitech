/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper1-maxime3.vincent
** File description:
** game
*/

#include "my.h"
#include "game.h"

int check_x(int y, int x, game_t *game)
{
    int nb_x = 0;

    if (y < game->height && x > 0 && game->map[y + 1][x - 1] == 'X')
        nb_x++;
    if (y < game->height && game->map[y + 1][x] == 'X')
        nb_x++;
    if (y < game->height && x < game->width && game->map[y + 1][x + 1] == 'X')
        nb_x++;
    if (x > 0 && game->map[y][x - 1] == 'X')
        nb_x++;
    if (x < game->width && game->map[y][x + 1] == 'X')
        nb_x++;
    if (y > 0 && x > 0 && game->map[y - 1][x - 1] == 'X')
        nb_x++;
    if (y > 0 && game->map[y - 1][x] == 'X')
        nb_x++;
    if (y > 0 && x < game->width && game->map[y - 1][x + 1] == 'X')
        nb_x++;
    return (nb_x);
}

void make_round(game_t *game)
{
    int y = 0;
    int x = 0;
    int length = 0;

    game->next_map = malloc(sizeof(char *) * game->height);
    for (int i = 0; i < game->height; i++)
        game->next_map[i] = malloc(sizeof(char) * game->width);
    for (int i = 0; game->map[i]; i++)
        for (int j = 0; game->map[i][j]; j++)
            length++;
    for (int i = 0; i < length; i++) {
        if (x == game->width - 1) {
            x = 0;
            y++;
        }
        my_printf("Hey loop %d\n", i);
        if(check_x(y, x, game) == 3 || (check_x(y, x, game) == 2 && game->map[y][x] == 'X'))
            game->next_map[y][x] = 'X';
        else if (check_x(y, x, game) < 2 || check_x(y, x, game) > 3)
            game->next_map[y][x] = '.';
        else
            game->next_map[y][x] = game->map[y][x];
        x++;
    }
}

void play_game(game_t *game, int nb_rounds)
{
    for (int i = 0; i <= nb_rounds; i++) {
        my_printf("Hey %d\n", i);
        make_round(game);
        my_printf("%t", game->next_map);
        game->map = copy_array(game->next_map, 0, game->height);
        array_free(game->next_map);
    }
}