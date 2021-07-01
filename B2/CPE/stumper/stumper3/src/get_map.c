/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper3-johan.chrillesen
** File description:
** get_map
*/

#include "get_map.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

map_t fill_map(map_t map, char const *buff, int size)
{
    map.map = malloc(sizeof(int) * (size - map.height));

    printf("height : %d | width : %d\n", map.height, map.width);
    if (map.map == NULL) {
        map.ret = -1;
        return (map);
    }
    for (int i = 0; buff[i]; i++) {
        if (buff[i] == map.str[0])
            map.map[i] = 0;
        else if (buff[i] == map.str[1])
            map.map[i] = 1;
        else if (buff[i] == map.str[2])
            map.map[i] = 2;
        else if (buff[i] == map.str[3])
            map.map[i] = 3;
        else if (buff[i] != '\n') {
            map.ret = -1;
            return (map);
        }
    }
    return (map);
}

int check_length(char const *buffer, int i, int nb_columns, \
int nb_columns_base)
{
    if (buffer[i] == '\n') {
        if (nb_columns != nb_columns_base)
            return (-1);
        nb_columns = 0;
    }
    return (nb_columns);
}

map_t check_map(map_t map, int size, int fd)
{
    char *buff = malloc(sizeof(char) * (size + 1));

    if (buff == NULL) {
        map.ret = 84;
        free(buff);
        return (map);
    }
    read(fd, buff, size + 1);
    map.height = get_height(buff);
    map.width = get_length(buff, map.height);
    if (map.height != map.width) {
        map.ret = -1;
        free(buff);
        return (map);
    }
    map = fill_map(map, buff, size);
    return (map);
}

map_t get_map(char const *filepath, char const *characters)
{
    map_t map = {0, 0, 0, 0, NULL};
    struct stat file_stat;
    int fd = open(filepath, O_RDONLY);

    map.str = strdup(characters);
    if (fd == -1 || stat(filepath, &file_stat)) {
        close(fd);
        map.ret = -1;
        return (map);
    } else
        map = check_map(map, (int)file_stat.st_size, fd);
    if (map.ret == -1)
        close(fd);
    return (map);
}