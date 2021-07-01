/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myhunter-johan.chrillesen
** File description:
** move_rect
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include "csfml.h"

void move_rect(sfIntRect *rect, int offset, int max_value) {
    rect->left += offset;
    if (rect->left >= max_value)
        rect->left = 0;
}

sfVector2f change_position(float pos_x, float pos_y)
{
    sfVector2f position;
    position.x = pos_x;
    position.y = pos_y;
    return (position);
}