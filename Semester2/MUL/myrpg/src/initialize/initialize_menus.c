/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-tanguy.bellicha
** File description:
** initialize_menus
*/

#include "rpg.h"

void initialize_menu(game_t *rpg)
{
    rpg->menu->buttons = malloc(sizeof(button_t) * 4);
    rpg->menu->objs = malloc(sizeof(game_object_t) * 1);
    rpg->menu->buttons[0] = init_button_from_string(\
    "960 540 180 180 resources/menu/resume.png play", RESUME_BUTTON);
    rpg->menu->buttons[1] = init_button_from_string(\
    "1840 80 120 120 resources/menu/quit.png quit", QUIT_BUTTON);
    rpg->menu->buttons[2] = init_button_from_string(\
    "80 80 120 120 resources/menu/infos.png infos", INFOS_BUTTON);
    rpg->menu->buttons[3] = NULL;
    rpg->menu->objs[0] = NULL;
    rpg->menu->background = create_object\
    ("./resources/menu/background.jpg", (sfVector2f) \
    {sfRenderWindow_getSize(rpg->window).x/2, \
        sfRenderWindow_getSize(rpg->window).y/2}, \
    create_rect(0, 0, 1920, 1080), (sfVector2f) {1, 1});
    rpg->current_scene = rpg->menu;
}