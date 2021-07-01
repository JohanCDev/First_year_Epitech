/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper4-quentin.leroueil
** File description:
** assign_values
*/

#include "pokemon.h"

int get_values_pok(pokemon_t *pokemon, char *file, char *pokemon_searched)
{
    int i = 0;

    pokemon->name = strdup(pokemon_searched);
    for (; file[i] && file[i] != ';' && file[i] != '\n'; i++);
    i++;
    pokemon->attack = atoi(&file[i]);
    for (; file[i] && file[i] != ';' && file[i] != '\n'; i++);
    i++;
    pokemon->defense = atoi(&file[i]);
    for (; file[i] && file[i] != ';' && file[i] != '\n'; i++);
    i++;
    pokemon->speed = atoi(&file[i]);
    for (; file[i] && file[i] != ';' && file[i] != '\n'; i++);
    i++;
    pokemon->health = atoi(&file[i]);
    pokemon_searched = NULL;
    printf("%s|%d|%d|%d|%d\n", pokemon->name, pokemon->attack, \
    pokemon->defense, pokemon->speed, pokemon->health);
    return (0);
}

int assign_values(pokemon_t *pokemon, char *file, char **pokemon_searched)
{
    int j = 1;
    int k = 0;

    for (int i = 0; file[i]; i++) {
        if (file[i] == '#')
            for (; file[i] && file[i] != '\n'; i++);
        if (file[i] == '\n')
            show_pokemon(file, i);
        i++;
        k = i;
        for (; j < 3; j++) {
            if (!strncmp(&file[k], pokemon_searched[j], strlen(pokemon_searched[j])))
                get_values_pok(&(pokemon[j - 1]), &file[k], pokemon_searched[j]);
            for (; file[k] && file[k] != '\n'; k++);
            k++;
        }
    }
    return (0);
}