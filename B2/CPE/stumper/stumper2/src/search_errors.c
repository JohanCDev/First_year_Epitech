/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper2-maxime3.vincent
** File description:
** search_errors
*/


#include "my.h"
#include "game.h"

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

int check_map(char const *buffer, int height)
{
    int nb_columns = 0;
    int nb_columns_base = 0;

    for (int i = 0; buffer[i] != '\n'; i++)
        nb_columns_base++;
    nb_columns_base++;
    for (int i = 0; i < height; i++) {
        nb_columns++;
        if ((nb_columns = check_length(buffer, i, nb_columns, \
            nb_columns_base)) == -1)
            return (-1);
    }
    return (nb_columns_base);
}

int get_height(char const *buffer)
{
    int height = 0;

    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] == '\n')
            height++;
    }
    height++;
    return (height);
}

void get_map(game_t *game, struct stat file_stat, int fd)
{
    char *buffer = malloc(sizeof(char) * (file_stat.st_size + 1));

    game->height = 0;
    game->width = 0;
    game->map = NULL;
    game->next_map = NULL;
    game->ret = 0;
    read(fd, buffer, file_stat.st_size + 1);
    game->height = get_height(buffer);
    if ((game->width = check_map(buffer, game->height)) == -1) {
        game->ret = 84;
        free(buffer);
        close(fd);
        return;
    }
    game->map = my_str_to_word_array(buffer);
    free(buffer);
    close(fd);
}

game_t *check_errors(char **argv)
{
    game_t *game = malloc(sizeof(game_t));
    struct stat file_stat;
    int fd = open(argv[1], O_RDONLY);

    if (game == NULL || fd == -1 || stat(argv[1], &file_stat)) {
        close(fd);
        return (NULL);
    } else
        get_map(game, file_stat, fd);
    return (game);
}
