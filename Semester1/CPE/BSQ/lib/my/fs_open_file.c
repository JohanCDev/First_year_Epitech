/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-BSQ-johan.chrillesen
** File description:
** bootstrap_two
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include <unistd.h>
#include <stdlib.h>

int fs_open_file(char const *filepath)
{
    int file = open(filepath, O_RDONLY);
    return (file);
}