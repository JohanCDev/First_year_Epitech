/*
** EPITECH PROJECT, 2021
** My_defender
** File description:
** button
*/

#include "defender.h"
#include "my.h"

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

void button_is_hover(s_button *button, sfMouseMoveEvent mousePosition)
{
    sfFloatRect button_rect = sfRectangleShape_getGlobalBounds(button->rect);
    sfColor colorHover = {255, 255, 255, 210};
    sfColor colorBase = {255, 255, 255, 255};

    if (sfFloatRect_contains(&button_rect, mousePosition.x, mousePosition.y)) {
        sfRectangleShape_setFillColor(button->rect, colorHover);
        if (sfRectangleShape_getScale(button->rect).x == 1.0)
            sfRectangleShape_setScale(button->rect, (sfVector2f) {1.2, 1.2});
    } else {
        sfRectangleShape_setFillColor(button->rect, colorBase);
        sfRectangleShape_setScale(button->rect, (sfVector2f) {1, 1});
    }
}