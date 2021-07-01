/*
** EPITECH PROJECT, 2020
** CSFML
** File description:
** test
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>

int main()
{
    sfVideoMode mode = {720, 720, 32};
    sfRenderWindow *window;
    sfEvent event;
    sfTexture* texture;
    sfSprite* sprite;
    texture = sfTexture_createFromFile("sources/sprite.jpeg", NULL);
    if (!texture)
        return 1;
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    window = sfRenderWindow_create(mode, "window", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}