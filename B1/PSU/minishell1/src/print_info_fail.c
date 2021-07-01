/*
** EPITECH PROJECT, 2021
** B-PSU-101-NAN-1-1-minishell1-johan.chrillesen
** File description:
** print_info_fail
*/

#include "minishell.h"
#include "my.h"
#include <signal.h>

void my_print_core(int status)
{
    if (__WCOREDUMP(status))
        my_put_error(" (core dumped)");
}

void switch_errors(int status)
{
    switch (WTERMSIG(status)) {
    case 11:
        my_put_error("Segmentation fault");
        break;
    case 8:
        my_put_error("Floating exception");
        break;
    default:
        break;
    }
}

void my_print_status(int status)
{
    if (WIFSIGNALED(status)) {
        switch_errors(status);
        my_print_core(status);
        my_put_error("\n");
    }
}