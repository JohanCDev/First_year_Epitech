/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-johan.chrillesen
** File description:
** start_loop
*/

#include "my.h"
#include "minishell.h"

void exit_read_failed(void)
{
    if (isatty(0))
        my_printf("exit\n");
}

char *initialize_loop(s_minishell *minishell, char **env)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    copy_path(minishell, env);
    if (isatty(0))
        my_printf("$> ");
    read = getline(&line, &len, stdin);
    if (my_strlen(line) == 1 && !isatty(0)) {
        free_all(minishell, line);
        exit(0);
    }
    line[read] = 0;
    if (read == -1) {
        exit_read_failed();
        free_all(minishell, line);
        exit(0);
    }
    return (line);
}