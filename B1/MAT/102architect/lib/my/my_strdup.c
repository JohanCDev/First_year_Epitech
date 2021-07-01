/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** allocates memory
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *str;
    int i;

    str = malloc(1 * (my_strlen(src) + 1));
    my_strcpy(str, src);
    return (str);
}
