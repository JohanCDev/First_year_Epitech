/*
** EPITECH PROJECT, 2021
** sandpile.h
** File description:
** sandpile.h
*/


#ifndef __POKEMON__
#define __POKEMON__

//-----NEEDED-INCLUDE------
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <fcntl.h>
//-----MACROS--------------

//-----STRUCTURE-----------
typedef struct s_pokemon
{
    char *name;
    int attack;
    int defense;
    int speed;
    unsigned int health;
} pokemon_t;

//-----PROTOTYPES----------

//pokemon.c
pokemon_t *pokemon(char **argv);
int read_dir(DIR *d, pokemon_t *pokemon_fight, char **argv, struct dirent *dir);
int get_pokemon_value(pokemon_t *pokemon, char *file_name, \
char **pokemon_searched);
int assign_values(pokemon_t *pokemon, char *file, char **pokemon_searched);
char *get_filepath(char *path, char *file_name);

//show_pokemon.c
void show_pokemon(char *file, int pos);
int show_info(char *file, int pos);

//open_and_read_file.c
char *open_and_read_file(char const *filepath);

//fight.c
int fight(pokemon_t *fight_pokemons);
void proceed_fight(pokemon_t *first, pokemon_t *second);
void start_fight(pokemon_t *first, pokemon_t *second, bool turn);
void act_on_game(pokemon_t *attack, pokemon_t *defend);

//free.c
void free_pokemons(pokemon_t *first, pokemon_t *second);

//helpers.c
int jump_until_next_step(char *file, int i);

#endif