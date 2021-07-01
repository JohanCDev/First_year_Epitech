/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper4-quentin.leroueil
** File description:
** free
*/

#include "pokemon.h"

void free_pokemons(pokemon_t *first, pokemon_t *second)
{
    if (first) {
        free(first);
        first = NULL;
    }
    if (second) {
        free(second);
        second = NULL;
    }
}