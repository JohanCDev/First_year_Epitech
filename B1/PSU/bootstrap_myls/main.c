/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-bsmyls-johan.chrillesen
** File description:
** main
*/

#include "include/my_printf.h"
#include "include/my.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

char *get_name(char *filepath)
{
    int i = 0;
    int j = 0;

    while (filepath[i]) {
        j = i;
        while (filepath[i] != '/' && filepath != 0)
            i++;
        if (filepath[i] == '/')
            i++;
    }
    return (filepath + j);
}

char get_type(mode_t st_mode)
{
    if (S_ISREG(st_mode))
        return ('f');
    if (S_ISDIR(st_mode))
        return ('d');
    if (S_ISLNK(st_mode))
        return ('l');
    if (S_ISBLK(st_mode))
        return ('b');
    if (S_ISCHR(st_mode))
        return ('c');
    if (S_ISFIFO(st_mode))
        return ('p');
    else
        return (' ');
}

int get_info_file(char *filepath)
{
    struct stat stat_file;

    if (lstat(filepath, &stat_file)) {
        my_put_error("Failed stat\n");
        return (84);
    }
    my_printf("Name: %s\n", get_name(filepath));
    my_printf("Type: %c\n", get_type(stat_file.st_mode));
    my_printf("Inode: %d\n", stat_file.st_ino);
    my_printf("Hard link: %d\n", stat_file.st_nlink);
    my_printf("Size: %d\n", stat_file.st_size);
    my_printf("Allocated space: %d\n", stat_file.st_blocks * 512);
    if (S_ISBLK(stat_file.st_mode))
        my_printf("Major: %d\n", stat_file.st_dev);
    else
        my_printf("Major: N/A\n");
    if (S_ISCHR(stat_file.st_mode))
        my_printf("Minor: %d\n", stat_file.st_dev);
    else
        my_printf("Minor: N/A\n");
    my_printf("UID: %d\n", stat_file.st_uid);
    my_printf("GID: %d\n", stat_file.st_gid);
    return (0);
}

int main(int argc, char **argv)
{
    char *filepath = "";

    if (argc != 2) {
        my_put_error("Error arguments");
        return (84);
    }
    filepath = argv[1];
    get_info_file(filepath);
    return (0);
}