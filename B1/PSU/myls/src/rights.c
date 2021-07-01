/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myls-johan.chrillesen
** File description:
** rights
*/

#include "my.h"

void rights_types(struct stat stat_file, s_list *list_s)
{
    if (S_ISDIR(stat_file.st_mode))
        list_s->rights[0] = 'd';
    else if (S_ISLNK(stat_file.st_mode))
        list_s->rights[0] = 'l';
    else
        list_s->rights[0] = '-';
}

void rights_file(struct stat stat_file, s_list *list_s)
{
    list_s->rights = malloc(sizeof(char) * 11);
    rights_types(stat_file, list_s);
    list_s->rights[1] = (stat_file.st_mode & S_IRUSR ? 'r' : '-');
    list_s->rights[2] = (stat_file.st_mode & S_IWUSR ? 'w' : '-');
    list_s->rights[3] = (stat_file.st_mode & S_IXUSR ? 'x' : '-');
    list_s->rights[4] = (stat_file.st_mode & S_IRGRP ? 'r' : '-');
    list_s->rights[5] = (stat_file.st_mode & S_IWGRP ? 'w' : '-');
    list_s->rights[6] = (stat_file.st_mode & S_IXGRP ? 'x' : '-');
    list_s->rights[7] = (stat_file.st_mode & S_IROTH ? 'r' : '-');
    list_s->rights[8] = (stat_file.st_mode & S_IWOTH ? 'w' : '-');
    list_s->rights[9] = (stat_file.st_mode & S_IXOTH ? 'x' : '-');
    list_s->rights[10] = '\0';
}