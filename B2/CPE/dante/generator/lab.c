/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-johan.chrillesen
** File description:
** lab
*/

#include "generator.h"

int check_if_is_end(t_generator *gen, int line, int nb)
{
    int column = 0;

    while (column < gen->x) {
        if (gen->tab[line][column] != 0 && gen->tab[line][column] != nb)
            return (0);
        column++;
    }
    return (1);
}

int	check_end(t_generator *gen)
{
    int line = 0;
    int	nb = gen->tab[0][0];

    while (line < gen->y) {
        if (check_if_is_end(gen, line, nb) == 0)
            return (0);
        line++;
    }
    return (1);
}

void calculate_multiple(t_generator *gen, int line, int nb, int nb2)
{
    int column = 0;

    while (column < gen->x) {
        if (gen->tab[line][column] == nb2)
            gen->tab[line][column] = nb;
        column++;
    }
}

void multiple(t_generator *gen, int nb, int nb2)
{
    int line = 0;

    while (line < gen->y) {
        calculate_multiple(gen, line, nb, nb2);
        line++;
    }
}

void merge_cells(t_generator *gen)
{
    int	line = (rand() % gen->y);
    int column = (rand() % gen->x);

    if (gen->tab[line][column] == 0) {
        if (column > 0 && column < (gen->x - 1) && line >= 0 &&
        gen->tab[line][column + 1] != gen->tab[line][column - 1] &&
        gen->tab[line][column + 1] != 0 && gen->tab[line][column - 1] != 0) {
            multiple(gen, gen->tab[line][column + 1], \
            gen->tab[line][column - 1]);
            gen->tab[line][column] = gen->tab[line][column + 1];
        }
        if (line > 0 && line < (gen->y - 1) && column >= 0 &&
        gen->tab[line - 1][column] != gen->tab[line + 1][column] &&
        gen->tab[line - 1][column] != 0 && gen->tab[line + 1][column] != 0) {
            multiple(gen, gen->tab[line + 1][column], \
            gen->tab[line - 1][column]);
            gen->tab[line][column] = gen->tab[line + 1][column];
        }
    }
}
