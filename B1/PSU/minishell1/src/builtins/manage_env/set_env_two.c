/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-johan.chrillesen
** File description:
** set_env_two
*/

#include "my.h"
#include "minishell.h"

int check_if_errors(char **array, s_minishell *minishell)
{
    int i = 0;

    for (i = 0; array[i]; i++) {
        if (i > 2) {
            my_put_error("setenv: Too many arguments.\n");
            return (1);
        }
    }
    if (i == 1) {
        my_printf("%t", minishell->env_tab);
        return (1);
    }
    if (!check_name_var(array[1])) {
        return (1);
    }
    return (0);
}

int search_for_existing_var(s_minishell *minishell, char **array)
{
    for (minishell->env->i = 0; minishell->env_tab[minishell->env->i]; \
    minishell->env->i++) {
        search_for_string(minishell, array[1]);
        if (minishell->env->found == 1)
            return (1);
    }
    return (0);
}