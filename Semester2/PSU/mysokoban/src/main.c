/*
** EPITECH PROJECT, 2021
** B-PSU-200-NAN-2-1-mysokoban-johan.chrillesen
** File description:
** main
*/

#include "my.h"
#include "sokoban.h"

int main(int argc, char **argv)
{
    sokoban_t *sokoban = initialize(argc, argv, 1);

    if (sokoban == NULL)
        return (84);
    if (sokoban->ret)
        return (sokoban->ret - 1);
    initialize_ncurses();
    while (1) {
        clear();
        display_game(sokoban);
        act_on_game(sokoban);
        if (sokoban->ret == 0 || sokoban->ret == 1 || sokoban->ret == 84) {
            display_game(sokoban);
            endwin();
            return (sokoban->ret);
        }
    }
    endwin();
    return (0);
}