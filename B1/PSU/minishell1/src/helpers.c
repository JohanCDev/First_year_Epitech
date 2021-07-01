/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-johan.chrillesen
** File description:
** my_str_isalphanum
*/

#include "my.h"
#include "minishell.h"

int check_name_var(char const *str)
{
    if (!((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a' && str[0] <= 'z') \
    || str[0] == '_')) {
        my_put_error("setenv: Variable name must begin with a letter.\n");
        return (0);
    }
    for (int i = 1; str[i]; i++) {
        if (!((str[i] >= 'A' && str[i] <= 'Z') || \
        (str[i] >= 'a' && str[i] <= 'z') || \
        (str[i] >= '0' && str[i] <= '9') || str[i] == '_' || str[i] == '.')) {
            my_put_error("setenv: Variable name must contain ");
            my_put_error("alphanumeric characters.\n");
            return (0);
        }
    }
    return (1);
}

char **copy_array(char **array, char *string_add)
{
    int len = 0;
    int y = 0;
    char **new_array = NULL;

    for (len = 0; array[len]; len++);
    new_array = malloc(sizeof(char *) * len + 1);
    if (new_array == NULL)
        return (NULL);

    for (int x = 0; x < len; x++) {
        new_array[x] = malloc(sizeof(char) * (my_strlen(array[x]) + 1));
        for (y = 0; array[x][y]; y++)
            new_array[x][y] = array[x][y];
        new_array[x][y + 1] = 0;
    }
    if (string_add) {
        new_array[len] = my_strdup(string_add);
        new_array[len + 1] = 0;
    }
    return (new_array);
}

void reset_str(s_minishell *minishell, int i)
{
    for (int k = 0; minishell->env_tab[i][k]; k++)
        minishell->env_tab[i][k] = 0;
}

char **my_strtok(char *line, char *separators)
{
    char **array = malloc(sizeof(*array) * 10);
    int i = 0;

    array[i] = strtok(line, separators);
    while (array[i]) {
        i++;
        array[i] = strtok(NULL, separators);
    }
    return (array);
}

char *reset_string(char *str)
{
    for (int i = 0; i < (my_strlen(str) - 1); i++)
        str[i] = 0;
    return (str);
}