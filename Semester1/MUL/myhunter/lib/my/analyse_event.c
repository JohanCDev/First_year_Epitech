/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myhunter-johan.chrillesen
** File description:
** analyse_event
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include "csfml.h"

object move_bird(object bird)
{
    sfClock *clock = sfClock_create();

    if (sfClock_getElapsedTime(clock).microseconds > 200000.0) {
        move_rect(&bird.rect, bird.rect.width, 117);
        sfSprite_setPosition(bird.sprite, change_position \
        (sfSprite_getPosition(bird.sprite).x + 20, sfSprite_getPosition\
        (bird.sprite).y - 50));
        sfClock_restart(clock);
    }
    return (bird);
}

void analyse_event(win window, object bird)
{
    switch (window.event.type) {
        case sfEvtClosed :
            close_window(window.window);
            break;
        case sfEvtMouseButtonPressed :
            manage_mouse_click(window, bird);
        default :
            break;
    }
    //bird = move_bird(bird);
}