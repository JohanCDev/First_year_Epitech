/*
** EPITECH PROJECT, 2021
** B-CPE-110-NAN-1-1-antman-tanguy.bellicha
** File description:
** check_images
*/

#include "my.h"
#include "antman.h"

char *check_all_chars(char *str)
{
    int i = 0;
    int k = 0;
    int nb_char = 0;

    while (i < 3) {
        if (str[k] == '\n')
            i++;
        k++;
        nb_char++;
    }
    for (; str[k]; k++)
        if (!((str[k] >= '0' && str[k] <= '9') || str[k] == '\n'))
            return ("Error");
    return (str);
}

char *get_image_str(int fd, char *buffer, char *str, int length)
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
    return (check_all_chars(str));
}

char *read_image(struct stat file_stat, int fd)
{
    char *str = NULL;
    char *buffer = NULL;

    if (((str = malloc(sizeof(char) * file_stat.st_size)) == NULL) || \
    ((buffer = malloc(sizeof(char) * file_stat.st_size)) == NULL))
        return ("Error");
    if (str == NULL || buffer == NULL)
        return ("Error");
    if (file_stat.st_size == 0)
        return ("empty");
    str = get_image_str(fd, buffer, str, file_stat.st_size);
    if (!my_strcmp(str, "Error"))
        return ("Error");
    return (str);
}

int compress_image(char *filepath, s_antman *antman)
{
    struct stat image_stat;
    int fd = 0;

    if ((fd = open(filepath, O_RDONLY)) == -1) {
        my_put_error("Can't read this file.\n");
        close(fd);
        return (84);
    }
    if (stat(filepath, &image_stat) || S_ISDIR(image_stat.st_mode)) {
        return (84);
    }
    antman->file_content = read_image(image_stat, fd);
    if (!my_strcmp(antman->file_content, "empty"))
        return (0);
    else if (!my_strcmp(antman->file_content, "Error") || \
    (print_hexa_line(antman) == 84))
        return (84);
    close (fd);
    return (0);
}

int my_skipline(char *str, int i)
{
    while (str[i] && str[i] != '\n')
        i++;
    i++;
    return (i);
}