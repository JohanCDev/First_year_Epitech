/*
** EPITECH PROJECT, 2021
** B-CPE-110-NAN-1-1-antman-tanguy.bellicha
** File description:
** files
*/

#include "my.h"
#include "antman.h"

char *populate_str(int fd, char *buffer, char *str, int length)
{
    int size = 1;
    int tempo = 0;
    int i_buf = 0;
    int i = 0;

    while (size > 0) {
        i_buf = 0;
        if ((size = read(fd, buffer, length)) == -1)
            return ("Error");
        tempo = size;
        while (tempo-- > 0)
            str[i++] = buffer[i_buf++];
    }
    str[i] = 0;
    return (str);
}

char *read_file(struct stat file_stat, int fd)
{
    char *str = NULL;
    char *buffer = NULL;

    if (((str = malloc(sizeof(char) * file_stat.st_size)) == NULL) || \
    ((buffer = malloc(sizeof(char) * file_stat.st_size)) == NULL))
        return ("Error");
    if (str == NULL || buffer == NULL || file_stat.st_size == 0)
        return ("Error");
    str = populate_str(fd, buffer, str, file_stat.st_size);
    if (!my_strcmp(str, "Error"))
        return ("Error");
    return (str);
}

int check_file(char *filepath, s_antman *antman)
{
    struct stat file_stat;
    int fd = 0;

    if ((fd = open(filepath, O_RDONLY)) == -1) {
        my_put_error("Can't read this file.\n");
        close(fd);
        return (84);
    }
    if (stat(filepath, &file_stat) || S_ISDIR(file_stat.st_mode))
        return (84);
    antman->file_content = read_file(file_stat, fd);
    if (!my_strcmp(antman->file_content, "Error"))
        return (84);
    close(fd);
    return (0);
}