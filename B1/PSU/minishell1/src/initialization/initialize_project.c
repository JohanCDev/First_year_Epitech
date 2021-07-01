/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-johan.chrillesen
** File description:
** initialize_project
*/

#include "my.h"
#include "minishell.h"

void get_real_path(s_minishell *minishell)
{
    int counter = 0;
    int i = 0;

    for (i = 0; counter != 3; i++) {
        if (minishell->path->begin_path[i] == '/')
            counter++;
    }
    minishell->path->begin_path[i] = 0;
}

void copy_path(s_minishell *minishell, char **env)
{
    int i = 0;

    while (my_strncmp(env[i], "PATH=", 5))
        i++;
    minishell->PATH_VAR = malloc(sizeof(char) * (my_strlen(env[i]) + 5));
    my_strcpy(minishell->PATH_VAR, env[i]);
}

void initialize_project(s_minishell *minishell, char **env)
{
    minishell->path = malloc(sizeof(s_path));
    if (minishell->path == NULL)
        exit(84);
    minishell->path->begin_path = getcwd(NULL, 0);
    get_real_path(minishell);
    if (minishell->path->begin_path == NULL)
        exit(84);
    minishell->path->actual_path = getcwd(NULL, 0);
    if (minishell->path->actual_path == NULL)
        exit(84);
    minishell->path->previous_path = getcwd(NULL, 0);
    if (minishell->path->previous_path == NULL)
        exit(84);
    if ((minishell->env = malloc(sizeof(s_env))) == NULL)
        exit(84);
    minishell->env_tab = copy_array(env, NULL);
    copy_path(minishell, env);
}