/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-johan.chrillesen
** File description:
** get_actual_path
*/

#include "my.h"
#include "minishell.h"

void get_actual_path(s_minishell *minishell)
{
    if (minishell->path->actual_path) {
        free(minishell->path->actual_path);
        minishell->path->actual_path = NULL;
    }
    minishell->path->actual_path = getcwd(NULL, 0);
    minishell->path->actual_path\
    [my_strlen(minishell->path->actual_path)] = '\0';
}

void get_previous_path(s_minishell *minishell)
{
    if (minishell->path->previous_path) {
        free(minishell->path->previous_path);
        minishell->path->previous_path = NULL;
    }
    minishell->path->previous_path = getcwd(NULL, 0);
    minishell->path->previous_path\
    [my_strlen(minishell->path->previous_path)] = '\0';
}