/*
** EPITECH PROJECT, 2021
** B-MUL-100-NAN-1-1-myrunner-johan.chrillesen
** File description:
** helper
*/

#include "runner.h"

sfVector2f create_vector(int x, int y)
{
    sfVector2f vector = {x, y};
    return (vector);
}

sfIntRect create_rect(int top, int left, int width, int height)
{
    sfIntRect rect = {top, left, width, height};
    return (rect);
}