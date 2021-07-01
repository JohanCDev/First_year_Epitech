/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-BSQ-johan.chrillesen
** File description:
** initialisation
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "mybsq.h"
#include <unistd.h>
#include <stdlib.h>

int look_errors(int size, int fd)
{
    if (size == 0) {
        my_put_error("Empty file\n");
        return (84);
    }
    if (fd == -1) {
        my_put_error("Invalid file\n");
        return (84);
    }
    return (0);
}

int get_length(char const *buffer, int i)
{
    while (buffer[i] != '\n')
        i++;
    return (i);
}

char *skip_first_line(char *buffer)
{
    while (*buffer != '\n')
        buffer++;
    buffer++;
    return (buffer);
}

char **populate_array(char *buffer, int size)
{
    int x = 0;
    int y = 0;
    int i = 0;
    char **array = malloc(sizeof(char **) * (size + 1));

    while (buffer[i] != '\0') {
        array[y] = malloc(sizeof(char *) * get_length(buffer, i) + 1);
        while (buffer[i] != '\n') {
            array[y][x] = buffer[i];
            x++;
            i++;
        }
        array[y][x] = '\n';
        array[y][x + 1] = '\0';
        i++;
        y++;
        x = 0;
    }
    return (array);
}

int get_size_file(char const *filepath)
{
    struct stat stat_file;
    int size = 0;

    if (lstat(filepath, &stat_file)) {
        my_put_error("Failed stat\n");
        return (84);
    }
    size = stat_file.st_size;
    return (size);
}
