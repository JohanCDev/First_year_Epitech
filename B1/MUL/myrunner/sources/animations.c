/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myrunner-johan.chrillesen
** File description:
** animations
*/

#include "my.h"
#include "runner.h"

sfVector2f change_position(float pos_x, float pos_y)
{
    sfVector2f position;
    position.x = pos_x;
    position.y = pos_y;
    return (position);
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left = rect->left + offset;
    if (rect->left >= max_value)
        rect->left = 0;
}