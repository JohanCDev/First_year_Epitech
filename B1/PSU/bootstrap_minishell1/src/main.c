/*
** EPITECH PROJECT, 2021
** bsminishell
** File description:
** main
*/

#include "my.h"

#include <sys/wait.h>

char **get_args(char **arg)
{
    char **array = my_str_to_word_array(arg[1]);

    return (array);
}

int get_nb_args(char *args)
{
    int nb_args = 0;

    while (*args) {
        if (*args == ' ')
            nb_args++;
        args++;
    }
    return (nb_args);
}

void my_print_status(int status)
{
    if (WIFSIGNALED(status))
        my_printf("Status: %s\n", strsignal(WTERMSIG(status)));
    else
        my_printf("Status: OK\n");
}

void do_step_4(char **argv, char **args, char **envp)
{
    int pid = 0;
    int status;

    my_printf("Program name: %s\n", args[0]);
    my_printf("Nb args: %d\n", get_nb_args(argv[1]));
    my_printf("PID: %d\n", getpid());
    pid = fork();
    if (pid == 0) {
        my_printf("Child PID: %d\n", getpid());
        execve(args[0], args, envp);
        exit (0);
    }
    waitpid(pid, &status, 0);
    my_printf("Program terminated.\n");
    my_print_status(status);
}

int main(int argc, char **argv, char **env)
{
    (void) argc;
    do_step_4(argv, get_args(argv), env);
    return (0);
}