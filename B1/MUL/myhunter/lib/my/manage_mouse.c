/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myhunter-johan.chrillesen
** File description:
** manage_mouse_click
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "csfml.h"

void clicked_on_sprite(object bird, win window)
{
    sfClock *clockStop = sfClock_create();

    bird.rect.top = 120;
    bird.rect.width = 35;
    while (sfClock_getElapsedTime(clockStop).microseconds < 200000.0) {
        // sfSprite_setPosition(sprite, change_position(sfSprite_getPosition \
        // (sprite).x, sfSprite_getPosition(sprite).y + 50));
        move_rect(&bird.rect, bird.rect.width, 70);
        // sfClock_restart(clock);
    }
    display_window(window, bird);
}

void manage_mouse_click(win window, object bird)
{
    my_putstr("Mouse x = ");
    my_put_nbr(window.event.mouseButton.x);
    my_putstr(" y = ");
    my_put_nbr(window.event.mouseButton.y);
    my_putchar('\n');
    if (window.event.mouseButton.button == sfMouseLeft) {
        if (window.event.mouseButton.x > (sfSprite_getPosition(bird.sprite).x) \
        && window.event.mouseButton.x < (sfSprite_getPosition(bird.sprite).x + \
        sfSprite_getTextureRect(bird.sprite).width * 2.5) && \
        window.event.mouseButton.y > (sfSprite_getPosition(bird.sprite).y) && \
        window.event.mouseButton.y < (sfSprite_getPosition(bird.sprite).y + \
        sfSprite_getTextureRect(bird.sprite).height * 2.5)) {
            clicked_on_sprite(bird, window);
            my_putstr("On sprite\n");
        }
        else
            my_putstr("Not on sprite\n");
    }
}