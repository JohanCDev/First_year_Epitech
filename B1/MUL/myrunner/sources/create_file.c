/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myrunner-johan.chrillesen
** File description:
** create_file
*/

#include "my.h"
#include "runner.h"

char *populate_array(info_map map_info, char *buff)
{
    char *map;
    int x = 0;
    int i = 0;

    map = malloc(sizeof(char) * (map_info.nb_columns));
    while (buff[i] != '\n')
        map[x++] = buff[i++];
    map[x] = '\0';
    return (map);
}

info_map get_file_size(info_map map_info, char const *filepath)
{
    struct stat file_stat;

    map_info.fd = open(filepath, O_RDONLY);
    if (map_info.fd == -1 || lstat(filepath, &file_stat)) {
        my_put_error("No file found\n");
        map_info.ret = 84;
        return (map_info);
    }
    map_info.size = file_stat.st_size;
    return (map_info);
}

info_map count(info_map map_info, char *buff)
{
    for (int i = 0; buff[i]; i++) {
        if (buff[i] == '\n')
            map_info.nb_lines++;
    }
    for (int i = 0; buff[i] != '\n'; i++)
        map_info.nb_columns++;
    return (map_info);
}

void free_and_close(info_map map_info, char *buff)
{
    close(map_info.fd);
    free(buff);
}

game_s *create_map(game_s *game, char *filepath)
{
    info_map map_info = {0, 0, 0, 0, 0};
    char *buff;

    map_info = get_file_size(map_info, filepath);
    if (map_info.ret == 84) {
        game->ret = 84;
        return (game);
    }
    buff = malloc(sizeof(char) * (map_info.size + 1));
    read(map_info.fd, buff, map_info.size + 1);
    map_info.nb_lines = 0;
    map_info.nb_columns = 0;
    map_info = count(map_info, buff);
    game->map = malloc(sizeof(char) * (map_info.nb_columns - 1));
    game->map = populate_array(map_info, buff);
    free_and_close(map_info, buff);
    return (game);
}