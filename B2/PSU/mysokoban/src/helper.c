/*
** EPITECH PROJECT, 2021
** B-PSU-200-NAN-2-1-mysokoban-johan.chrillesen
** File description:
** helper
*/

#include "sokoban.h"
#include "my.h"

char **copy_array(char **array)
{
    int i = 0;
    char **new_array = NULL;

    for (i = 0; array[i]; i++);
    new_array = malloc(sizeof(char *) * (i + 1));
    if (new_array == NULL) {
        return (NULL);
    }
    for (i = 0; array[i]; i++) {
        new_array[i] = my_strdup(array[i]);
    }
    return (new_array);
}

int get_nb_x(char **map)
{
    int i = 0;
    int j = 0;
    int nb_x = 0;

    while (map[i]) {
        if (map[i][j] == 'X')
            nb_x++;
        if (map[i][j] == '\0') {
            i++;
            j = 0;
        }
        j++;
    }
    return (nb_x);
}

void print_help(int print)
{
    if (print) {
        my_printf("USAGE\n");
        my_printf("\t./my_sokoban map\n");
        my_printf("DESCRIPTION\n");
        my_printf("\tmap file representing the warehouse map, containing '#'");
        my_printf("for walls,\n\t\t'P' for the player, 'X' for boxes and 'O'");
        my_printf("for storage locations.\n");
    }
}

char **get_map(char *filepath, sokoban_t *sokoban)
{
    struct stat map_stat;
    int fd = 0;

    if (stat(filepath, &map_stat))
        return (NULL);
    if ((fd = open(filepath, O_RDONLY)) == -1) {
        close(fd);
        return (NULL);
    }
    if (add_map_in_struct(sokoban, map_stat.st_size, fd) == -1)
        return (NULL);
    close(fd);
    return (sokoban->map);
}