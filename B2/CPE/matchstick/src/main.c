/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-bsmatchstick-johan.chrillesen
** File description:
** main
*/

#include "my.h"
#include "matchstick.h"

int main(int argc, char **argv)
{
    match_t *match = initialize_game(argc, argv);
    int ret = 0;

    if (match == NULL || match->ret == 84)
        return (84);
    print_game_board(match);
    while (1) {
        match->ret = play_game(match);
        if (match->ret == 0 || match->ret == 1 || match->ret == 2) {
            ret = match->ret;
            free_all(match);
            return (ret);
        }
    }
    return (0);
}