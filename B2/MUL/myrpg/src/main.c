/*
** EPITECH PROJECT, 2021
** My_rpg
** File description:
** main
*/

#include "rpg.h"

int main(void)
{
    game_t *rpg = initialize_all();
    sfRenderWindow_setMouseCursorVisible(rpg->window, 0);
    while (sfRenderWindow_isOpen(rpg->window)) {
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event))
            analyse_events(rpg);
        if (rpg->ret)
            break;
        update_window(rpg, 1);
    }
    destroy_all(rpg);
    return (0);
}