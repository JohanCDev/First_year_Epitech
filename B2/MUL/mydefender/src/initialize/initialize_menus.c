/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-tanguy.bellicha
** File description:
** initialize_menus
*/

#include "my.h"
#include "defender.h"

void initialize_menu(s_game *defender)
{
    defender->menu->buttons[0] = init_button_from_string\
    (defender, "50 50 9 16 resources/menu/resume.png play", RESUME_BUTTON);
    defender->menu->buttons[1] = init_button_from_string\
    (defender, "95.3 8 6.75 12 resources/menu/quit.png quit", QUIT_BUTTON);
    defender->menu->buttons[2] = init_button_from_string\
    (defender, "4.7 8 6.75 12 resources/menu/infos.png infos", INFOS_BUTTON);
    defender->menu->buttons[3] = NULL;
    defender->menu->objs[0] = NULL;
    defender->menu->background = create_object\
    ("./resources/menu/background.png", (sfVector2f) \
    {sfRenderWindow_getSize(defender->window).x/2, \
        sfRenderWindow_getSize(defender->window).y/2}, \
    create_rect(0, 0, 1189, 669), (sfVector2f) {1.345, 1.345});
    defender->current_scene = defender->menu;
}

void initialize_play_infos(s_game *defender)
{
    defender->play_infos->towers = malloc(sizeof(s_towers) * 1);
    defender->play_infos->towers = NULL;
    defender->play_infos->market_list = malloc(sizeof(s_game_object) * 5);
    defender->play_infos->market_list[0] = create_object\
    ("./resources/towers/gel.png", (sfVector2f){1282, 236}, \
    (sfIntRect){0, 0, 300, 532}, (sfVector2f){0.18, 0.18});
    defender->play_infos->market_list[1] = create_object\
    ("./resources/towers/scientist.png", (sfVector2f){1544, 236}, \
    (sfIntRect){0, 0, 52, 68}, (sfVector2f){1.4, 1.4});
    defender->play_infos->market_list[2] = create_object\
    ("./resources/towers/hospital.png", (sfVector2f){1132, 444}, \
    (sfIntRect){0, 0, 740, 657}, (sfVector2f){0.14, 0.14});
    defender->play_infos->market_list[3] = create_object\
    ("./resources/towers/medic.png", (sfVector2f){1711, 448}, \
    (sfIntRect){0, 0, 302, 108}, (sfVector2f){0.36, 0.36});
    defender->play_infos->market_list[4] = NULL;
    defender->play_infos->show_menu = false;
    defender->play_infos->active_wave = false;
    defender->play_infos->current_difficulty = 8;
    defender->play_infos->main_clock = sfClock_create();
}

void initialize_pause_menu(s_game *defender)
{
    defender->pause_menu->buttons = malloc(sizeof(s_button) * 5);
    defender->pause_menu->objs = malloc(sizeof(s_game_object) * 1);
    defender->pause_menu->objs[0] = NULL;
    defender->pause_menu->buttons[0] = init_button_from_string\
    (defender, "50 50 12 21.33 resources/menu/resume.png resume", \
    RESUME_BUTTON);
    defender->pause_menu->buttons[1] = init_button_from_string\
    (defender, "25 50 9 16 resources/pause/home.png home", HOME_BUTTON);
    defender->pause_menu->buttons[2] = init_button_from_string\
    (defender, "95.3 8 6.75 12 resources/menu/quit.png quit", QUIT_BUTTON);
    defender->pause_menu->buttons[3] = init_button_from_string\
    (defender, "75 50 9 16 resources/menu/music.png music", MUSIC_BUTTON);
    defender->pause_menu->buttons[4] = NULL;
    defender->pause_menu->background = defender->menu->background;
}