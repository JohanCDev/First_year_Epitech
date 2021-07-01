/*
** EPITECH PROJECT, 2021
** B-PSU-200-NAN-2-1-mysokoban-johan.chrillesen
** File description:
** initialize
*/

#include "my.h"
#include "sokoban.h"

int count_everything(char *buffer, sokoban_t *sokoban, int fd)
{
    count_lines(buffer, sokoban);
    for (int i = 0; i < sokoban->height; i++)
        get_width_of_map(buffer, i, sokoban);
    if (check_map(buffer) == -1) {
        close(fd);
        free(buffer);
        return (-1);
    }
    return (0);
}

int check_map(char *buffer)
{
    check_map_t numbers_ch;

    numbers_ch.nb_o = 0;
    numbers_ch.nb_p = 0;
    numbers_ch.nb_x = 0;

    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] == ' ' || buffer[i] == '\n' || buffer[i] == '#' || \
        buffer[i] == 'O' || buffer[i] == 'X' || buffer[i] == 'P') {
            numbers_ch = count_specials_chars(numbers_ch, buffer, i);
        } else
            return (-1);
    }
    if ((numbers_ch.nb_x != numbers_ch.nb_o) || numbers_ch.nb_p != 1)
        return (-1);
    return (0);
}

int add_map_in_struct(sokoban_t *sokoban, int length, int fd)
{
    char *buffer = malloc(sizeof(char) * (length + 1));
    int size = 0;

    if (buffer == NULL)
        return (-1);
    if ((size = read(fd, buffer, length)) == -1) {
        free(buffer);
        close(fd);
        return (-1);
    }
    buffer[size] = 0;
    if (count_everything(buffer, sokoban, fd) == -1)
        return (-1);
    sokoban->map = my_str_to_word_array(buffer);
    sokoban->base_map = my_str_to_word_array(buffer);
    free(buffer);
    close(fd);
    return (0);
}

void initialize_all_values(sokoban_t *sokoban)
{
    sokoban->height = 0;
    sokoban->nb_x = 0;
    sokoban->pos_x = 0;
    sokoban->pos_y = 0;
    sokoban->ret = 0;
    sokoban->width = 0;
}

sokoban_t *initialize(int argc, char **argv, int print)
{
    sokoban_t *sokoban = malloc(sizeof(sokoban_t));

    initialize_all_values(sokoban);
    if (sokoban == NULL)
        return (NULL);
    if (argc != 2) {
        sokoban->ret = 85;
        return (sokoban);
    } else {
        if (!my_strcmp(argv[1], "-h")) {
            print_help(print);
            sokoban->ret = 1;
            return (sokoban);
        } else if (get_map(argv[1], sokoban) == NULL) {
            sokoban->ret = 85;
            return (sokoban);
        }
    }
    sokoban->ret = 0;
    return (sokoban);
}