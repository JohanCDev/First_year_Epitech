/*
** EPITECH PROJECT, 2021
** My_defender
** File description:
** main
*/

#include "defender.h"
#include "my.h"
#include <stdio.h>

sfVector2f update_pos(float positionX, float positionY)
{
    sfVector2f position;

    position.x = positionX;
    position.y = positionY;
    return (position);
}

int main(void)
{
    s_game *defender = initialize_all();

    sfRenderWindow_setMouseCursorVisible(defender->window, 0);
    while (sfRenderWindow_isOpen(defender->window)) {
        while (sfRenderWindow_pollEvent(defender->window, &defender->event))
            analyse_events(defender);
        if (defender->ret)
            break;
        update_window(defender, 1);
        if (defender->play_infos->playing_game->texts[0]->value <= 0)
            defender->current_scene = defender->scoreboard;
    }
    destroy_all(defender);
    return (0);
}
