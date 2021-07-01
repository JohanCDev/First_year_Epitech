/*
** EPITECH PROJECT, 2020
** B-PSU-100-NAN-1-1-myls-johan.chrillesen
** File description:
** flag_l
*/

#include "my.h"

char *return_time(char *time)
{
    char *ret = malloc(sizeof(char) * 19);
    int x = 0;

    while (x < 12) {
        ret[x] = time[x + 4];
        x++;
    }
    ret[x] = '\0';
    return (ret);
}

int populate_list(char *filepath, struct dirent *di_file, \
struct stat stat_file, s_list *list_s)
{
    char *filepath_tmp = malloc(sizeof(char) * 256);

    list_s->file_master = malloc(sizeof(char) * 256);
    list_s->folder_master = malloc(sizeof(char) * 256);
    list_s->time = malloc(sizeof(char) * 256);
    list_s->name_file = malloc(sizeof(char) * 256);
    list_s->name_low = malloc(sizeof(char) * 256);
    my_strcpy(filepath_tmp, (const char *)filepath);
    my_strcat(filepath_tmp, di_file->d_name);
    (lstat(filepath_tmp, &stat_file)) ? exit(84) : 0;
    rights_file(stat_file, list_s);
    list_s->nlinks = stat_file.st_nlink;
    my_strcpy(list_s->file_master, getpwuid(stat_file.st_uid)->pw_name);
    my_strcpy(list_s->folder_master, getgrgid(stat_file.st_gid)->gr_name);
    list_s->size = stat_file.st_size;
    my_strcpy(list_s->time, return_time(ctime(&stat_file.st_mtime)));
    list_s->elapsed_time = stat_file.st_mtime;
    my_strcpy(list_s->name_file, di_file->d_name);
    my_strcpy(list_s->name_low, my_strlowcase(di_file->d_name));
    return (stat_file.st_blocks / 2);
}

linked_list_s *change_node(linked_list_s **list, linked_list_s **first_node, \
s_list **list_s)
{
    (*list)->data = *list_s;
    (*list)->next = *first_node;
    return (*list);
}

void intialize_stat(char *filepath, struct stat *stat_file, \
linked_list_s **list, s_list **list_s)
{
    lstat(filepath, stat_file);
    *list = malloc(sizeof(s_list *));
    *list_s = (s_list *)malloc(sizeof(s_list));
}

linked_list_s *do_ls(char *filepath, int *nb_total_blocks)
{
    DIR *directory;
    struct dirent *dirent_file;
    struct stat stat_file;
    s_list *list_s = 0;
    linked_list_s *list = 0;
    linked_list_s *first_node = 0;

    (filepath[my_strlen(filepath) - 1] != '/') ?  \
    my_strcat(filepath, "/") : 0;
    (lstat(filepath, &stat_file)) ? exit(84) : 0;
    directory = opendir(filepath);
    while ((dirent_file = readdir(directory))) {
        if (dirent_file->d_name[0] != '.') {
            intialize_stat(filepath, &stat_file, &list, &list_s);
            *nb_total_blocks += populate_list(filepath, dirent_file, \
            stat_file, list_s);
            first_node = change_node(&list, &first_node, &list_s);
        }
    }
    return (first_node);
}