/*
** EPITECH PROJECT, 2021
** main
** File description:
** for stumper 3
*/

#include "pokemon.h"

int main(int argc, char **argv)
{
    pokemon_t *fight_pokemons = NULL;

    if (argc != 3)
        return (84);

    if ((fight_pokemons = pokemon(argv)) == NULL)
        return (84);
    if (fight(fight_pokemons) == -1)
        return (84);
    if (fight_pokemons) {
        free(fight_pokemons);
        fight_pokemons = NULL;
    }
    return (0);
}
