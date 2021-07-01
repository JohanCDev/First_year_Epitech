/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** allocates memory
*/

#include <stdlib.h>

char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *str;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (str == NULL)
        return (NULL);
    my_strcpy(str, src);
    return (str);
}
