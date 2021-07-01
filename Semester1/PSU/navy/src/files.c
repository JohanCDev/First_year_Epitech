/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** files
*/

#include "my.h"
#include "navy.h"

char *populate_str(int fd, char *buffer, char *str)
{
    int size = 1;
    int i_buf = 0;
    int tempo = 0;
    int i = 0;

    while (size != 0) {
        i_buf = 0;
        size = read(fd, buffer, 32);
        tempo = size;
        while (tempo-- > 0)
            str[i++] = buffer[i_buf++];
    }
    return (str);
}

char *get_line_of_file(char *filepath, int i_line)
{
    char *file;
    char *line = malloc(sizeof(char) * 8);
    int i_file = 0;
    int i_str = 0;

    file = read_file(open(filepath, O_RDONLY), filepath);
    while (i_line > 0) {
        if (*file++ == '\n')
            i_line--;
        i_file++;
    }
    while (*file != '\n' && *file != '\0')
        line[i_str++] = *file++;
    return (line);
}

char *read_file(int fd, char *filepath)
{
    char buffer[32];
    struct stat file_stat;
    char *str;

    if (lstat(filepath, &file_stat))
        return ("Error");
    str = malloc(sizeof(char) * file_stat.st_size);
    if (str == NULL)
        return ("Error");
    str = populate_str(fd, buffer, str);
    if (check_placements(str) == 84) {
        my_put_error("Format isn't compatible.\n");
        return ("Error");
    }
    return (str);
}

int get_file(char *filepath)
{
    int fd = 0;
    char *message = malloc(sizeof(char) * 128);

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        my_put_error("Can't read this file.\n");
        close(fd);
        return (84);
    }
    message = read_file(fd, filepath);
    close(fd);
    if (!my_strcmp(message, "Error"))
        return (84);
    return (0);
}