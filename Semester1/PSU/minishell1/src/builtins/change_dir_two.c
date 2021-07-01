/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-johan.chrillesen
** File description:
** change_dir_second
*/

#include "my.h"
#include "minishell.h"

void check_bad_access(char *path, mode_t mode)
{
    if ((access(path, X_OK) || access(path, R_OK)) && S_ISDIR(mode)) {
        my_put_error(path);
        my_put_error(": Permission denied.\n");
        return;
    } else if (!S_ISDIR(mode)) {
        my_put_error(path);
        my_put_error(": Not a directory.\n");
    }
}