/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-johan.chrillesen
** File description:
** tab
*/

#include "generator.h"

void my_put_tab(t_generator *gen)
{
    int line = 0;
    int column = 0;

    while (line < gen->y) {
        column = 0;
        while (column < gen->x) {
            printf("%d ", gen->tab[line][column]);
            column++;
        }
        printf("\n");
        line++;
    }
}

void modulo_tab(t_generator *gen, int line, int column, int nb)
{
    if (((line % 2) == 1) || (column % 2 == 1))
        gen->tab[line][column] = 0;
    else
        gen->tab[line][column] = nb;
}

int fill_int_array(t_generator *gen)
{
    int line = 0;
    int column = 0;
    int nb = 1;

    if ((gen->tab = malloc(sizeof(int *) * gen->y)) == NULL)
        return (84);
    while (line < gen->y) {
        column = 0;
        if ((gen->tab[line] = malloc(sizeof(int) * gen->x)) == NULL)
            return (84);
        while (column < gen->x) {
            modulo_tab(gen, line, column, nb);
            gen->tab[line][column] ? nb++ : 0;
            column++;
        }
        line++;
    }
    return (0);
}
