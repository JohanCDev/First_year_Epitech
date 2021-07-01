/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-johan.chrillesen
** File description:
** change_dir
*/

#include "my.h"
#include "minishell.h"

void cd_to_home(s_minishell *minishell)
{
    char *path = NULL;
    int i = 0;

    for (; my_strncmp(minishell->env_tab[i], "HOME", 4); i++);
    path = my_strdup(minishell->env_tab[i]);
    for (int j = 0; j < 5; j++)
        path++;
    chdir(path);
    minishell->path->moved = 1;
}

void check_access_path(s_minishell *minishell, char **array)
{
    struct stat file_stat;

    if (stat(array[1], &file_stat)) {
        my_put_error(array[1]);
        my_put_error(": No such file or directory.\n");
        return;
    }
    get_previous_path(minishell);
    array[1][my_strlen(array[1])] = '\0';
    if (!access(array[1], X_OK) && opendir(array[1])) {
        chdir(array[1]);
        minishell->path->moved = 1;
    } else if (!my_strcmp(array[1], "~"))
        cd_to_home(minishell);
    else
        check_bad_access(array[1], file_stat.st_mode);
}

void change_dir_second(s_minishell *minishell, char **array)
{
    char *tmp = getcwd(NULL, 0);

    if (!my_strcmp(array[1], "-")) {
        if (!minishell->path->moved) {
            minishell->path->moved = 1;
            write(2, ": No such file or directory.\n", 30);
        } else {
            chdir(minishell->path->previous_path);
            minishell->path->previous_path = \
            reset_string(minishell->path->previous_path);
            my_strcpy(minishell->path->previous_path, tmp);
        }
    } else
        check_access_path(minishell, array);
    my_free(tmp);
    return;
}

int check_dir_arguments(char **array)
{
    for (int i = 0; array[i]; i++) {
        if (i > 1) {
            my_put_error("cd: Too many arguments\n");
            array_free(array);
            return (-1);
        }
    }
    return (0);
}

void change_dir(char *line, s_minishell *minishell)
{
    char **array = my_strtok(line, " \t\n");

    if (check_dir_arguments(array) == -1)
        return;
    else if (my_strcmp(array[0], "cd")) {
        my_put_error(array[0]);
        my_put_error(": Command not found.\n");
        my_free(array);
        return;
    } else if (!my_strcmp(array[0], "cd") && !array[1]) {
        get_previous_path(minishell);
        minishell->path->moved = 1;
        chdir(minishell->path->begin_path);
        my_free(array);
        return;
    } else
        change_dir_second(minishell, array);
    my_free(array);
    return;
}