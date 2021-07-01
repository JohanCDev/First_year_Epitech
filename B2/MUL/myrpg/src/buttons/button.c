/*
** EPITECH PROJECT, 2021
** My_rpg
** File description:
** button
*/

#include "rpg.h"

char *my_get_image_name(char *path)
{
    int end = 0;
    int start = 0;
    char *image_name;

    while (path[end] && path[end] != '.')
        end++;
    start = end;
    while (path[start] != '/')
        start--;
    start++;
    image_name = malloc(sizeof(char) * (end - start));
    my_strncpy(image_name, &path[start], end - start);
    return (image_name);
}

void button_is_hover(button_t *button, sfMouseMoveEvent mousePosition)
{
    sfFloatRect button_rect = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfFloatRect_contains(&button_rect, mousePosition.x, mousePosition.y)) {
        if (sfRectangleShape_getScale(button->rect).x == 1.0)
            sfRectangleShape_setScale(button->rect, (sfVector2f) {1.2, 1.2});
        sfRectangleShape_setTextureRect(button->rect, \
        (sfIntRect){243, 0, 243, 230});
    } else {
        sfRectangleShape_setScale(button->rect, (sfVector2f) {1, 1});
        sfRectangleShape_setTextureRect(button->rect, \
        (sfIntRect){0, 0, 243, 230});
    }
}