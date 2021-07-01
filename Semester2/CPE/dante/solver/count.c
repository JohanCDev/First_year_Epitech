/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-johan.chrillesen
** File description:
** count
*/

#include "solver.h"

int	get_nb_column(char **tab)
{
    int	c = 0;

    while (tab[0][c])
        c++;
    return (c);
}

int	get_array_length(char **tab)
{
    int i = 0;

    while (tab && tab[i])
        i++;
    return (i);
}
