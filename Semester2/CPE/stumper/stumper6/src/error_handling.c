/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** error_handling
*/

#include "tictactoe.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int argument_handling_part_two(tic_t *tic, int ac, char **av)
{
    if (ac >= 3) {
        if (strlen(av[2]) != 1 || av[1][0] == av[2][0]) {
            write(2, ERROR_ARGUMENT, strlen(ERROR_ARGUMENT));
            return (-1);
        }
        tic->p_two = av[2][0];
        if (!is_a_valid_character(tic->p_two))
            return (-1);
    }
    if (ac >= 4) {
        if (!str_is_num(av[3])) {
            write(2, ERROR_ARGUMENT, strlen(ERROR_ARGUMENT));
            return (-1);
        }
        tic->size = atoi(av[3]);
        if (tic->size < 1)
            return (-1);
    }
    return (0);
}

int argument_handling(tic_t *tic, int ac, char **av)
{
    if (ac > 4) {
        write(2, ERROR_ARGUMENT, strlen(ERROR_ARGUMENT));
        return (-1);
    }
    tic->size = 3;
    tic->p_one = 'X';
    tic->p_two = 'O';
    if (ac >= 2) {
        if (strlen(av[1]) != 1) {
            write(2, ERROR_ARGUMENT, strlen(ERROR_ARGUMENT));
            return (-1);
        }
        tic->p_one = av[1][0];
        if (!is_a_valid_character(tic->p_one))
            return (-1);
    }
    return (argument_handling_part_two(tic, ac, av));
}

