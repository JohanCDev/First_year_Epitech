/*
** EPITECH PROJECT, 2021
** B-CPE-110-NAN-1-1-antman-tanguy.bellicha
** File description:
** uncompress_images
*/

#include "my.h"
#include "giantman.h"

char *check_image_str(char *str)
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
    i = nb_char;
    for (; str[k]; k++) {
        if (!((str[k] >= '0' && str[k] <= '9') || (str[k] >= 'A' \
        && str[k] <= 'F') || str[k] == '\n' || str[k] == '|'))
            return ("Error");
    }
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
    return (check_image_str(str));
}

char *read_compressed_image(struct stat file_stat, int fd)
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
    if (!my_strcmp(str, "Error")) {
        return ("Error");
    }
    return (str);
}

char *my_getstr(char *str)
{
    char *string = malloc(sizeof(str) - 1);
    int i = 0;

    if (!string)
        return ("Error");
    while (str[i] && str[i] != '\n') {
        string[i] = str[i];
        i++;
    }
    return (string);
}

int uncompress_image(char *filepath, s_giantman *giantman)
{
    struct stat image_stat;
    int fd = 0;

    if ((fd = open(filepath, O_RDONLY))== -1) {
        my_put_error("Can't read this file.\n");
        close(fd);
        return (84);
    }
    if (stat(filepath, &image_stat) || S_ISDIR(image_stat.st_mode))
        return (84);
    giantman->file_content = read_compressed_image(image_stat, fd);
    if (!my_strcmp(giantman->file_content, "empty"))
        return (0);
    else if (!my_strcmp(giantman->file_content, "Error") || \
    (print_dec_line(giantman) == 84)) {
        my_printf("%s\n", giantman->file_content);
        return (84);
    }
    close (fd);
    return (0);
}