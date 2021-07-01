/*
** EPITECH PROJECT, 2021
** bsminishell
** File description:
** main
*/

#include "my.h"
#include "minishell.h"

int main(int argc, char **argv, char **env)
{
    char *line = NULL;
    s_minishell *minishell = malloc(sizeof(s_minishell));

    (void) argv;
    if (minishell == NULL || argc != 1)
        exit(84);
    initialize_project(minishell, env);
    while (1) {
        line = initialize_loop(minishell, env);
        switch_command(line, minishell);
    }
    return (0);
}