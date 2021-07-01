/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** concenates two strings
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int size = 0;
    int i = 0;

    dest = malloc(sizeof(char) * (my_strlen(dest) +  my_strlen(src) + 2));

    while (dest[size])
        size++;
    while (src[i]) {
        dest[size] = src[i];
        size++;
        i++;
    }
    dest[size] = 0;
    return (dest);
}
