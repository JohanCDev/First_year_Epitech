/*
** EPITECH PROJECT, 2021
** B-PSU-200-NAN-2-1-mysokoban-johan.chrillesen
** File description:
** initialize_ncurses
*/

#include "sokoban.h"

void initialize_ncurses(void)
{
    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    refresh();
}