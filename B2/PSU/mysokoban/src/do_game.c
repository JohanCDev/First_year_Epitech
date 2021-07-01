/*
** EPITECH PROJECT, 2021
** B-PSU-200-NAN-2-1-mysokoban-johan.chrillesen
** File description:
** print_map
*/

#include "sokoban.h"
#include "my.h"

int switch_key_next(int key, sokoban_t *sokoban)
{
    switch (key) {
        case -1 :
            return (84);
        case 32 :
            sokoban->map = copy_array(sokoban->base_map);
            return (1);
        default :
            return (0);
    }
}

int switch_key(int key, sokoban_t *sokoban)
{
    get_position_p(sokoban);
    switch (key) {
        case KEY_UP :
            move_up(sokoban);
            break;
        case KEY_DOWN :
            move_down(sokoban);
            break;
        case KEY_LEFT :
            move_left(sokoban);
            break;
        case KEY_RIGHT :
            move_right(sokoban);
            break;
        default :
            return (switch_key_next(key, sokoban));
    }
    return (0);
}

void act_on_game(sokoban_t *sokoban)
{
    switch_key(getch(), sokoban);
    if (sokoban->map == NULL) {
        sokoban->ret = 84;
        return;
    }
    change_map_add_o(sokoban);
    check_if_game_end(sokoban);
    if (sokoban->ret == 84)
        return;
    refresh();
}

void display_game(sokoban_t *sokoban)
{
    if (LINES < sokoban->height || COLS < sokoban->width) {
        mvprintw(LINES / 2, COLS / 2 - \
        my_strlen("Enlarge the terminal to play") / 2, \
        "Enlarge the terminal to play");
    } else
        print_map(sokoban);
}

void print_map(sokoban_t *sokoban)
{
    for (int i = 0; sokoban->map[i]; i++) {
        mvprintw(LINES / 2 - (sokoban->height / 2) + i, \
        COLS / 2 - sokoban->width / 2, sokoban->map[i]);
    }
    refresh();
}