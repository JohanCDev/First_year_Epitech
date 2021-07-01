/*
** EPITECH PROJECT, 2021
** stumper4
** File description:
** show_pokemon.c
*/

#include "pokemon.h"

int show_info(char *file, int pos)
{
    for (pos += 1; file[pos] && file[pos] != '\n' && file[pos] != ';'; pos++)
        printf("%c", file[pos]);
    return (pos);
}

void show_pokemon(char *file, int pos)
{
    printf("Pokemon ");
    pos = show_info(file, pos);
    printf(" has ");
    pos = show_info(file, pos);
    printf(" attack, ");
    pos = show_info(file, pos);
    printf(" defense, ");
    pos = show_info(file, pos);
    printf(" speed and ");
    pos = show_info(file, pos);
    printf(" health\n");
}