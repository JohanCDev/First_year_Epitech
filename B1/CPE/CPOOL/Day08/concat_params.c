/*
** EPITECH PROJECT, 2020
** concat_params
** File description:
** 
*/

#include "my.h"
#include <stdlib.h>

char *concat_params(int argc, char **argv)
{
    int size = 0;
    char *jump_line = "\n";
    char *str;

    for (int i = 0; i < argc; i++)
        size = my_strlen(argv[i]) + 1;
    str = malloc(sizeof(char) * size);
    str[0] = 0;
    for (int i = 0; i < argc; i++) {
        my_strcat(str, argv[i]);
        if (i < argc - 1)
            my_strcat(str, jump_line);
    }
    return (str);
}