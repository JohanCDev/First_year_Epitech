/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-johan.chrillesen
** File description:
** do_others
*/

#include "my.h"
#include "minishell.h"

char **get_args(char *str)
{
    char **array = my_str_to_word_array(str);

    // for (int i = 0; array[i]; i++)
    //     my_printf("before : array[%d] = %s\n", i, array[i]);
    if (!array[1])
        return (array);
    for (int i = 2; array[i]; i++) {
        //array[1] = malloc(sizeof(char) * my_strlen(str));
        my_strcat(array[1], " ");
        my_strcat(array[1], array[i]);
    }
    // array[2][0] = 0;
    // for (int i = 0; array[i]; i++)
    //     my_printf("after : array[%d] = %s\n", i, array[i]);
    //my_printf("%t", array);
    return (array);
}

void my_print_status(int status)
{
    if (WIFSIGNALED(status))
        my_printf("%s\n", strsignal(WTERMSIG(status)));
}

void do_step_4(char **args, s_minishell *minishell)
{
    int pid = 0;
    int status;
    char *path = malloc(sizeof(char) * (6 + my_strlen(args[0])));
    char **arguments = NULL;

    if (args[1]) {
        arguments = my_str_to_word_array(args[1]);
        for (int i = 0; arguments[i]; i++)
            my_printf("arguments[%d] = %s\n", i, arguments[i]);
    }
    pid = fork();
    if (pid == 0) {
        my_strcpy(path, "/bin/");
        my_strcat(path, args[0]);
        if (arguments[1])
            execve(path, arguments, minishell->env_tab);
        else
            execve(path, args, minishell->env_tab);
        exit (0);
    }
    waitpid(pid, &status, 0);
    my_print_status(status);
}

void do_others(s_minishell *minishell, char *line)
{
    char **array = get_args(line);

    do_step_4(array, minishell);
}