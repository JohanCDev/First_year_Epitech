/*
** EPITECH PROJECT, 2021
** prepa_stumper
** File description:
** open_and_read_file
*/

#include "my.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char *get_info_about_file(char *filepath, int fd, struct stat *file_stat)
{
    char *buffer = NULL;

    if (stat(filepath, file_stat)) {
        close(fd);
        return (my_put_error_ret_ptr("Stat failed\n", NULL));
    }
    if ((buffer = malloc(sizeof(char) * (file_stat->st_size + 1))) == NULL) {
        close(fd);
        return (my_put_error_ret_ptr("Malloc failed\n", NULL));
    }
    return (buffer);
}

char *open_and_read_file(char *filepath)
{
    struct stat file_stat;
    int fd = open(filepath, O_RDONLY);
    char *buffer = NULL;
    ssize_t rd = 0;

    if (fd < 0)
        return (my_put_error_ret_ptr("File can't be read\n", NULL));
    if ((buffer = get_info_about_file(filepath, fd, &file_stat)) == NULL)
        return (NULL);
    rd = read(fd, buffer, file_stat.st_size);
    if (rd == -1 || rd == 0) {
        my_free(buffer);
        close(fd);
        return (my_put_error_ret_ptr("Read failed or the file was empty\n", \
        NULL));
    }
    buffer[rd] = 0;
    close(fd);
    return (buffer);
}