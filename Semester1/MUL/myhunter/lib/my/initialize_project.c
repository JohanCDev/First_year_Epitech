/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myhunter-johan.chrillesen
** File description:
** initialize_project
*/

#include "my.h"

int look_params(int argc, char **argv)
{
    char const *help = "-h";

    if (argc == 2) {
        if (!my_strcmp(argv[1], help)) {
            my_putstr("Help :\n");
            my_putstr("Use your mouse to aim, left click to shoot\n");
            my_putstr("Usage ./my_hunter\n");
            return (0);
        } else
            return (84);
    } else
        return (84);
}