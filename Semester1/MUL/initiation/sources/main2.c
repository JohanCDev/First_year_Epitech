/*
** EPITECH PROJECT, 2020
** CSFML
** File description:
** main2
*/
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    sfVideoMode mode = {1080, 720, 32};
    sfRenderWindow *window;
    sfShape *shape = malloc(sizeof(sfShape *) * 1024);
    sfEvent event;
    sfVector2f position;
    sfVector2f scale;
    sfColor color;

    color.r = 0;
    color.g = 0;
    color.b = 255;
    color.a = 255;
    position.x = 100;
    position.y = 100;
    scale.x = 10;
    scale.y = 10;
    sfShape_setPosition(shape, position);
    sfShape_setFillColor(shape, color);
    sfShape_setOutlineColor(shape, color);
    sfShape_setScale(shape, scale);
    window = sfRenderWindow_create(mode, "window", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
   
    while (sfRenderWindow_isOpen(window) && sfRenderWindow_hasFocus(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawShape(window, shape, NULL);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}