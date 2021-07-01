/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-johan.chrillesen
** File description:
** commands
*/

#include "my.h"
#include "minishell.h"

void switch_command_fourth(char *line, s_minishell *minishell)
{
    if (!my_strncmp(line, "setenv", 6))
        set_env(line, minishell);
    else if (!my_strncmp(line, "unsetenv", 8)) {
        unset_env(line, minishell);
    } else {
        do_others(minishell, line);
    }
}

void switch_command_third(char *line, s_minishell *minishell)
{
    if (!my_strcmp(line, "\n"));
    else
        switch_command_fourth(line, minishell);
}

void switch_command_second(char *line, s_minishell *minishell)
{
    if (!my_strcmp(line, "env\n")) {
        my_printf("%t", minishell->env_tab);
    } else
        switch_command_third(line, minishell);
}

void switch_command(char *line, s_minishell *minishell)
{
    if (!my_strcmp(line, "exit\n")) {
        my_printf("exit\n");
        free_all(minishell, line);
        exit(0);
    }
    else if (!my_strncmp(line, "cd", 2))
        change_dir(line, minishell);
    else
        switch_command_second(line, minishell);
}