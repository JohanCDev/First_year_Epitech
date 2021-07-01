/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper3-maxime3.vincent
** File description:
** get_file
*/

#include "my.h"

char *get_map(char const *filepath)
{
    struct stat file_stat;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1 || stat(filepath, &file_stat)) {
        close (fd);
        return (NULL);
    }
}