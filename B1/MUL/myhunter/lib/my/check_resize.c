/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myhunter-johan.chrillesen
** File description:
** check_resize
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "csfml.h"
#include "my.h"

void check_resize(sfRenderWindow *window, sfEvent event) {
    sfVector2u size = sfRenderWindow_getSize(window);

    size.x > 1920 ? size.x = 1920 : 0;
    size.y > 1080 ? size.y = 1080 : 0;
    size.x < 800 ? size.x = 800 : 0;
    size.y < 600 ? size.y = 600 : 0;
    sfRenderWindow_setSize(window, size);
}