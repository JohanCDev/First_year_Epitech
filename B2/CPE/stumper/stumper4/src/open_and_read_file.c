/*
** EPITECH PROJECT, 2021
** stumper 4
** File description:
** open_and_read_file.c
*/

#include "pokemon.h"


char *open_and_read_file(char const *filepath)
{
    int i;
    int fd = open(filepath, O_RDONLY);
    struct stat file;
    char *buffer;

    if (!filepath)
        return (NULL);
    i = stat(filepath, &file);
    if (i == -1 || fd == -1)
        return NULL;
    buffer = malloc(sizeof(char) * file.st_size);
    if (!buffer)
        return NULL;
    i = read(fd, buffer, file.st_size);
    if (i == -1)
        return NULL;
    buffer[i] = '\0';
    close(fd);
    return (buffer);
}