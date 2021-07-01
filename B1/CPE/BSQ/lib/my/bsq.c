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

position look_up(char **array, position square)
{
    int i = 0;
    square.y = square.big_y;
    square.x = square.big_x;

    while (i != (square.size - 1) && square.error != -1) {
        square.y--;
        if (array[square.y][square.x] == 'o')
            square.error = -1;
        i++;
    }
    return (square);
}

position look_left(char **array, position square)
{
    int i = 0;
    square.y = square.big_y;
    square.x = square.big_x;

    while (i != (square.size - 1) && square.error != -1) {
        square.x--;
        if (array[square.y][square.x] == 'o')
            square.error = -1;
        i++;
    }
    return (square);
}

position look_for_square(char **array, position square)
{
    while (array[square.big_y][square.big_x] != 'o' && !square.error) {
        square.size++;
        square.big_x++;
        square.big_y++;
        square = look_up(array, square);
        look_for_errors(square);
        square = look_left(array, square);
        look_for_errors(square);
    }
    return (square);
}

position check_for_backline(char **array, position square)
{
    if (array[square.big_y][square.big_x] == '\n') {
        square.big_x = 0;
        square.big_y++;
    }
    return (square);
}

int do_bsq(char **array, int length, int width)
{
    position actual_square = {0, 0, 1, 0, 0, 0};
    int error = 0;
    int i = 0;

    while (!error) {
        if (array[actual_square.big_y][actual_square.big_x] == '.') {
            actual_square = look_for_square(array, actual_square);
            error = look_for_errors(actual_square);
        } else if (array[actual_square.big_y][actual_square.big_x] == 'o') {
            actual_square.size = 1;
            actual_square.big_x++;
            actual_square = check_for_backline(array, actual_square);
        }
    }
    if (actual_square.error == -1) {
        return (actual_square.size - 1);
    }
    return (actual_square.size);
}