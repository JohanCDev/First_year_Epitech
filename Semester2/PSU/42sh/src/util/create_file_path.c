/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Creates a file path
*/

#include <libmy/ascii.h>
#include <libmy/memory.h>
#include <stdlib.h>

char *sh_create_file_path(
    size_t dir_len, char const *dir_name, char const *file_name)
{
    size_t file_len = my_strlen(file_name);
    int need_sep = dir_name[dir_len - 1] != '/';
    char *result =
        malloc(sizeof(*result) * (dir_len + need_sep + file_len + 1));

    if (!result)
        return NULL;
    my_memcpy(result, dir_name, dir_len);
    if (need_sep)
        result[dir_len] = '/';
    my_memcpy(result + dir_len + need_sep, file_name, file_len);
    result[dir_len + need_sep + file_len] = '\0';
    return result;
}
