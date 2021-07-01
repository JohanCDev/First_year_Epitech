/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper2-maxime3.vincent
** File description:
** helper
*/

#include "my.h"
#include "game.h"

void array_free(char **array)
{
    for (int i = 0; array[i]; i++) {
        if (array[i]) {
            free(array[i]);
            array[i] = NULL;
        }
    }
    if (array) {
        free(array);
        array = NULL;
    }
}

char **copy_array(char **array, int free, int height)
{
    int i = 0;
    char **new_array = NULL;

    for (i = 0; array[i]; i++);
    new_array = malloc(sizeof(char *) * i);
    if (new_array == NULL) {
        array[0][0] = '&';
        return (array);
    }
    i = i;
    for (i = 0; i < height - 1; i++) {
        new_array[i] = my_strdup(array[i]);
    }
    if (free)
        array_free(array);
    return (new_array);
}