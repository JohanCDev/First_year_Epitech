/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-johan.chrillesen
** File description:
** free
*/

#include "my.h"
#include "minishell.h"

void my_free(void *object)
{
    if (object) {
        free(object);
        object = NULL;
    }
}

void array_free(char **array)
{
    for (int i = 0; array[i]; i++) {
        if (array[i]) {
            free(array[i]);
            array[i] = NULL;
        }
    }
}

void free_all(s_minishell *minishell, char *line)
{
    my_free(line);
    my_free(minishell->path->actual_path);
    my_free(minishell->path->previous_path);
    my_free(minishell->path->begin_path);
    my_free(minishell->path);
    my_free(minishell);
}