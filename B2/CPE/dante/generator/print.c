/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-johan.chrillesen
** File description:
** print
*/

#include "generator.h"

void put_start_end(t_generator *gen)
{
    int line = 0;
    int column = 0;

    while (line < gen->y) {
        column = 0;
        while (column < gen->x)
            column++;
        line++;
    }
    gen->tab[line - 1][column - 2] = 1;
    gen->tab[line - 1][column - 1] = 1;
}

void print_chars(t_generator *gen, int line)
{
    int column = 0;

    while (column < gen->x) {
        if (gen->tab[line][column] != 0)
            write(1, "*", 1);
        else if (gen->tab[line][column] == 0)
            write(1, "X", 1);
        column++;
    }
}

void display_maze(t_generator *gen)
{
    int line = 0;

    while (line < gen->y) {
        print_chars(gen, line);
        if (gen->tab[line + 1] != NULL)
            write(1, "\n", 1);
        line++;
    }
}
