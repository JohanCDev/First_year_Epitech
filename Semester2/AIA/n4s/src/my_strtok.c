/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** my_strtok
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int count_words(char *line, char *sep)
{
    int nb = 1;

    while (*line) {
        for (int i = 0; sep[i]; i++)
            sep[i] == *line ? nb++ : 0;
        line++;
    }
    return (nb);
}

char **my_strtok(char *line, char *separators)
{
    char **array = malloc(sizeof(*array) * (count_words(line, separators) + 1));
    int i = 0;

    array[i] = strtok(line, separators);
    while (array[i]) {
        i++;
        array[i] = strtok(NULL, separators);
    }
    return (array);
}