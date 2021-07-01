/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-johan.chrillesen
** File description:
** do_others_two
*/

#include "my.h"
#include "minishell.h"

char *search_for_existing_path(char **path, char *filepath, char *command)
{
    struct stat file_stat;

    for (int i = 0; path[i]; i++) {
        filepath = reset_string(filepath);
        filepath = assemble_filepath(filepath, path[i], command);
        if (!stat(filepath, &file_stat))
            break;
    }
    filepath[my_strlen(filepath)] = 0;
    return (filepath);
}

char **create_array_path(s_minishell *minishell)
{
    int i = 0;
    char **path = malloc(sizeof(*path) * 25);

    path[i] = strtok(minishell->PATH_VAR, "=:\n");
    while (path[i]) {
        i++;
        path[i] = strtok(NULL, "=:\n");
    }
    return (path);
}

char *assemble_filepath(char *filepath, char *path, char *command)
{
    my_strcpy(filepath, path);
    my_strcat(filepath, "/");
    my_strcat(filepath, command);
    return (filepath);
}

char *check_filepath(char *filepath)
{
    struct stat file_stat;

    if (!stat(filepath, &file_stat))
        return (filepath);
    else {
        my_put_error(filepath);
        my_put_error(": Command not found.\n");
        return ("Error");
    }
}

char *check_permission(char *filepath)
{
    struct stat file_stat;

    if (!stat(filepath, &file_stat) && access(filepath, X_OK) == 1) {
        write(2, "Permission denied.\n", 20);
        return ("Error");
    }
    return (filepath);
}