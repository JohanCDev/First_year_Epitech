/*
** EPITECH PROJECT, 2021
** pokemon
** File description:
** for stumper 4
*/

#include "pokemon.h"

char *get_filepath(char *path, char *file_name)
{
    int size = strlen(path) + strlen(file_name);
    char *filepath = malloc(sizeof(char *) * (size + 1));

    if (!filepath)
        return (NULL);
    if (!strcat(filepath, path) || !strcat(filepath, file_name)) {
        free(filepath);
        return (NULL);
    }
    filepath[size] = '\0';
    return (filepath);
}

int get_pokemon_value(pokemon_t *pokemon, char *file_name, \
char **pokemon_searched)
{
    char *file = open_and_read_file(get_filepath("pokecfg/", file_name));

    if (file_name[0] == '.')
        return (0);
    if (!file)
        return (-1);
    assign_values(pokemon, file, pokemon_searched);
    free(file);
    return (1);
}

int read_dir(DIR *d, pokemon_t *pokemon_fight, char **argv, struct dirent *dir)
{
    while ((dir = readdir(d)) != NULL) {
        if (get_pokemon_value(pokemon_fight, dir->d_name, argv) == -1)
            return (-1);
    }
    return (0);
}

pokemon_t *pokemon(char **argv)
{
    pokemon_t *pokemon_fight = malloc(sizeof(pokemon_t) * 2);
    DIR *d = NULL;
    struct dirent *dir = NULL;
    int i = 0;

    if (!pokemon_fight)
        return (NULL);
    d = opendir("./pokecfg");
    if (d == NULL)
        return (NULL);
    i = read_dir(d, pokemon_fight, argv, dir);
    if (i == -1)
        return (NULL);
    closedir(d);
    return (pokemon_fight);
}