/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** get_input
*/

#include "mydb.h"
#include <stdio.h>
#include <sys/types.h>

char *get_input(FILE *stream)
{
    char *str = NULL;
    size_t len = 0;
    ssize_t rd = 0;

    rd = getline(&str, &len, stream);
    if (rd == -1)
        return (NULL);
    return (str);
}