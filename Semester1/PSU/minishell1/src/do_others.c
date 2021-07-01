/*
** EPITECH PROJECT, 2021
** bsminishell
** File description:
** main
*/

#include "my.h"
#include "minishell.h"
#include <stdbool.h>

char *check_if_directory(mode_t file_mode, char *filepath, char *command)
{
    if (S_ISDIR(file_mode)) {
        my_put_error(command);
        my_put_error(": Permission denied.\n");
        return ("Error");
    }
    return (check_filepath(filepath));
}

char *verify_path_exists(s_minishell *minishell, char **args)
{
    struct stat file_stat;
    char *filepath = malloc(sizeof(char) * 25);
    char **path = create_array_path(minishell);

    filepath = search_for_existing_path(path, filepath, args[0]);
    if (stat(filepath, &file_stat)) {
        filepath = reset_string(filepath);
        filepath = assemble_filepath(filepath, getcwd(NULL, 0), args[0]);
        if (!stat(filepath, &file_stat))
            return (check_if_directory(file_stat.st_mode, filepath, args[0]));
        else {
            filepath = reset_string(filepath);
            my_strcpy(filepath, args[0]);
            return (check_filepath(filepath));
        }
        my_put_error(filepath);
        my_put_error(": Command not found.\n");
        return ("Error");
    }
    return (check_permission(filepath));
}

void do_execution(s_minishell *minishell, char **args)
{
    int pid = 0;
    int status;
    char *path = verify_path_exists(minishell, args);

    if (!my_strcmp(path, "Error"))
        return;
    pid = fork();
    if (pid == 0) {
        execve(path, args, minishell->env_tab);
        my_printf("%s: Exec format error. Binary file not found\n", path);
        exit(0);
    }
    waitpid(pid, &status, 0);
    my_print_status(status);
    my_free(path);
}

void do_others(s_minishell *minishell, char *line)
{
    char **array = malloc(sizeof(*array) * 10);
    int i = 0;

    array[i] = strtok(line, " \t\n");
    while (array[i]) {
        i++;
        array[i] = strtok(NULL, " \t\n");
    }
    do_execution(minishell, array);
    my_free(array);
}