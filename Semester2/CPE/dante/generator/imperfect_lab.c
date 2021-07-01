/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-johan.chrillesen
** File description:
** imperfect_lab
*/

#include "generator.h"

void make_imperfect(t_generator *gen)
{
    int	line = rand() % gen->y;
    int	column = rand() % gen->x;

    if (gen->tab[line][column] == 0) {
        if (column > 0 && column < (gen->x - 1) && line >= 0 \
            && gen->tab[line][column + 1] != gen->tab[line][column])
            gen->tab[line][column] = gen->tab[line][column + 1];
    } else
        make_imperfect(gen);
}
