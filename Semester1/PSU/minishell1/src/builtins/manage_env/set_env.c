/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-johan.chrillesen
** File description:
** manage_env
*/

#include "my.h"
#include "minishell.h"

void change_env_var_empty(s_minishell *minishell)
{
    char *str = NULL;
    int j = 0;

    for (j = 0; minishell->env_tab[minishell->env->i][j] != '='; j++);
    str = malloc(sizeof(char) * (j + 2));
    for (int k = 0; k < j; k++)
        str[k] = minishell->env_tab[minishell->env->i][k];
    reset_str(minishell, minishell->env->i);
    my_strcat(str, "=");
    my_strcpy(minishell->env_tab[minishell->env->i], str);
    my_free(str);
}

void change_env_var_other(s_minishell *minishell, char **array)
{
    char *str = NULL;
    int j = 0;

    for (j = 0; minishell->env_tab[minishell->env->i][j] != '='; j++);
    str = malloc(sizeof(char) * (j + my_strlen(array[2])));
    for (int k = 0; k < j; k++)
        str[k] = minishell->env_tab[minishell->env->i][k];
    reset_str(minishell, minishell->env->i);
    my_strcat(str, "=");
    my_strcat(str, array[2]);
    my_strcpy(minishell->env_tab[minishell->env->i], str);
    my_free(str);
}

void create_env_var_no_variable(s_minishell *minishell, char **array)
{
    char *str = NULL;

    str = malloc(sizeof(char) * (my_strlen(array[1]) + 2));
    my_strcpy(str, array[1]);
    my_strcat(str, "=");
    minishell->env_tab = copy_array(minishell->env_tab, str);
    my_free(str);
}

void create_env_var_with_variable(s_minishell *minishell, char **array)
{
    char *str = NULL;

    str = malloc(sizeof(char) * (my_strlen(array[1]) + \
    my_strlen(array[2]) + 2));
    my_strcpy(str, array[1]);
    my_strcat(str, "=");
    my_strcat(str, array[2]);
    minishell->env_tab = copy_array(minishell->env_tab, str);
    my_free(str);
}

void set_env(char *line, s_minishell *minishell)
{
    char **array = my_strtok(line, " \t\n");
    minishell->env->i = 0;
    minishell->env->found = 0;

    if (check_if_errors(array, minishell) == 1)
        return;
    search_for_existing_var(minishell, array);
    if (minishell->env->found == 0) {
        if (!array[2])
            create_env_var_no_variable(minishell, array);
        else
            create_env_var_with_variable(minishell, array);
    } else {
        if (!array[2])
            change_env_var_empty(minishell);
        else
            change_env_var_other(minishell, array);
    }
}