/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-BSQ-johan.chrillesen
** File description:
** bsq
*/

#include "my.h"
#include "mybsq.h"
#include <unistd.h>
#include <stdlib.h>

int check_map(char **array, int x, int y, int length)
{
    if ((array[y][x] == '\n' && x != length)) {
        my_put_error("Different length\n");
        return (84);
    }
    if (array[y][x] != '\n' && array[y][x] != 'o' && \
        array[y][x] != '.' && array[y][x] != '\0') {
        my_put_error("Invalid character\n");
        return (84);
    }
    return (0);
}

int check_dimensions(char **array, int length, int width)
{
    int x = 0;
    int y = 0;

    while (array[y][x]) {
        if (check_map(array, x, y, length) == 84)
            return (84);
        if ((y + 1) == width && x == length)
            return (0);
        if (x == length) {
            y++;
            x = 0;
        }
        x++;
    }
    return (0);
}

int look_for_errors(position square)
{
    int error = 0;
    if (square.error == -1) {
        error = -1;
    }
    return (error);
}