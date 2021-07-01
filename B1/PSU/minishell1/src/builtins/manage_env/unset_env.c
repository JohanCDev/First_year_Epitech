/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-johan.chrillesen
** File description:
** unset_env
*/

#include "minishell.h"
#include "my.h"

void search_for_string(s_minishell *minishell, char *string)
{
    int length_env = 0;

    for (int j = 0; minishell->env_tab[minishell->env->i][j] != '='; j++)
        length_env++;
    if (!my_strncmp(string, minishell->env_tab[minishell->env->i], \
    my_strlen(string)) && \
    length_env == my_strlen(string)) {
        minishell->env->found = 1;
        return;
    }
}

void check_every_env(char **array, s_minishell *minishell, int h)
{
    minishell->env->found = 0;

    for (minishell->env->i = 0; minishell->env_tab[minishell->env->i]; \
    minishell->env->i++) {
        search_for_string(minishell, array[h]);
        if (minishell->env->found == 1)
            break;
    }
    if (minishell->env->found == 1) {
        for (int j = 0; minishell->env_tab[minishell->env->i][j]; j++)
            minishell->env_tab[minishell->env->i][j] = 0;
        minishell->env_tab[minishell->env->i][0] = '\t';
    }
}

void unset_env(char *line, s_minishell *minishell)
{
    char **array = my_strtok(line, " \t\n");

    if (!array[1])
        my_printf("%s: Too few arguments.\n", array[0]);
    for (int h = 1; array[h]; h++) {
        check_every_env(array, minishell, h);
    }
    if (minishell->env->found == 1)
        my_free(array);
}