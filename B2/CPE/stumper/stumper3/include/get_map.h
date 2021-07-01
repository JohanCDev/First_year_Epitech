/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper3-johan.chrillesen
** File description:
** get_map
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct s_map {
    int height;
    int width;
    int *map;
    int ret;
    char *str;
} map_t;

int get_length(char const *buffer, int height);
int get_height(char const *buffer);

map_t get_map(char const *filepath, char const *characters);
map_t check_map(map_t map, int size, int fd);
int check_length(char const *buffer, int i, int nb_columns, \
int nb_columns_base);
map_t fill_map(map_t map, char const *buff, int size);