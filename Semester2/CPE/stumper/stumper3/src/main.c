/*
** EPITECH PROJECT, 2021
** main
** File description:
** for stumper 3
*/

#include "get_map.h"

int main(int ac, char **av)
{
    map_t map = get_map(av[2], av[1]);

    if (map.ret == 84)
        return (84);
    return (0);
}
