/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myhunter-johan.chrillesen
** File description:
** main
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "my.h"
#include "csfml.h"

void display_window(win window, object bird) {
    window.sprite = sfSprite_create();
    window.texture = sfTexture_createFromFile\
    ("ressources/background.png", NULL);
    window.size.x = 1.5;
    window.size.y = 1.5;
    bird.size.x = 2.5;
    bird.size.y = 2.5;

    sfRenderWindow_clear(window.window, sfBlack);
    sfSprite_setTexture(window.sprite, window.texture, sfTrue);
    sfSprite_setScale(window.sprite, window.size);
    sfRenderWindow_drawSprite(window.window, window.sprite, NULL);
    sfRenderWindow_drawSprite(window.window, bird.sprite, NULL);
    sfSprite_setScale(bird.sprite, bird.size);
    sfSprite_setTextureRect(bird.sprite, bird.rect);
    sfRenderWindow_display(window.window);
}

win init_window(win window)
{
    window.mode.height = 747;
    window.mode.width = 1200;
    window.mode.bitsPerPixel = 32;
    char *w = "My_hunter";
    window.window = sfRenderWindow_create(window.mode, w, \
    sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window.window, 30);
    return (window);
}

void detect_sprite_clicked(sfSprite* sprite, sfEvent event)
{
    if (event.mouseButton.x > (sfSprite_getPosition(sprite).x) && \
    event.mouseButton.x < (sfSprite_getPosition(sprite).x + \
    sfSprite_getTextureRect(sprite).width * 2.5) && \
    event.mouseButton.y > (sfSprite_getPosition(sprite).y) && \
    event.mouseButton.y < (sfSprite_getPosition(sprite).y + \
    sfSprite_getTextureRect(sprite).height * 2.5))
        my_putstr("clicked on sprite\n");
    else
        my_putstr("Not on sprite\n");
}

int main(int argc, char **argv)
{
    object bird;
    win window;
    srand(time(NULL));
    window = init_window(window);
    bird.texture = sfTexture_createFromFile \
    ("ressources/blueduck.png", NULL);
    bird.sprite = sfSprite_create();
    bird = create_sprite(bird);
    int ret = 0;
    sfClock *clock = sfClock_create();

    if (argc >= 2) {
        ret = look_params(argc, argv);
        return (ret);
    }
    while (sfRenderWindow_isOpen(window.window)) {
        while (sfRenderWindow_pollEvent(window.window, &window.event))
            analyse_event(window, bird);
        if (sfClock_getElapsedTime(clock).microseconds > 200000.0) {
            move_rect(&bird.rect, bird.rect.width, 117);
            sfSprite_setPosition(bird.sprite, change_position \
            (sfSprite_getPosition(bird.sprite).x + 20, sfSprite_getPosition\
            (bird.sprite).y - 50));
            sfClock_restart(clock);
        }
        display_window(window, bird);
    }
    sfRenderWindow_destroy(window.window);
}