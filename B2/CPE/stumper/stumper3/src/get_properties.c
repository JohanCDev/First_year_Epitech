/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper3-johan.chrillesen
** File description:
** get_properties
*/

#include "get_map.h"

int get_length(char const *buffer, int height)
{
    int cols_base = 0;
    int nb_cols = 0;

    for (int i = 0; buffer[i] != '\n'; i++)
        cols_base++;
    for (int i = 0; i < height; i++) {
        nb_cols++;
        if ((nb_cols = check_length(buffer, i, nb_cols, cols_base)) == -1)
            return (-1);
    }
    return (cols_base);
}

int get_height(char const *buffer)
{
    int height = 0;

    for (int i = 0; buffer[i]; i++)
        if (buffer[i] == '\n')
            height++;
    return (height);
}