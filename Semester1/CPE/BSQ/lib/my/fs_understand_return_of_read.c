/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-BSQ-johan.chrillesen
** File description:
** fs_understand_return_of_read
*/

#include "my.h"
#include <unistd.h>

int fs_understand_return_of_read(int fd, char *buffer, int size)
{
    int res = read(fd, buffer, size);
    if (res == -1)
        return (-1);
    else if (res == size)
        return (0);
}