/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper4-quentin.leroueil
** File description:
** helpers
*/

#include "pokemon.h"

int jump_until_next_step(char *file, int i)
{
    while (file[i]) {
        if (file[i] == '\n' || file[i] == ';')
            return (i);
        i++;
    }
    return (i);
}