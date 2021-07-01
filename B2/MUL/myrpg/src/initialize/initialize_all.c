/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-tanguy.bellicha
** File description:
** initialize_all
*/


#include "rpg.h"

void initialize_struct(game_t *rpg)
{
    rpg->menu = malloc(sizeof(scene_t));
    rpg->play_infos = malloc(sizeof(s_playing));
    rpg->play_infos->playing_game = malloc(sizeof(scene_t));
    rpg->pause_menu = malloc(sizeof(scene_t));
    rpg->infos = malloc(sizeof(scene_t));
    rpg->infos->background = malloc(sizeof(game_object_t));
    rpg->infos->objs = malloc(sizeof(game_object_t) * 1);
    rpg->infos->buttons = malloc(sizeof(button_t) * 2);
    rpg->infos->texts = malloc(sizeof(text_t) * 1);
    rpg->infos->background = create_object("./resources/infos.png", \
    (sfVector2f) {960, 540}, (sfIntRect){0, 0, 1920, 1080}, (sfVector2f){1, 1});
    rpg->infos->buttons[0] = init_button_from_string\
    ("1800 925 180 180 resources/pause/home.png", HOME_BUTTON);
    rpg->musics = malloc(sizeof(musics_t));
    rpg->play_infos->player = init_player();
    rpg->inventory = init_scene_inventory();
    rpg->quests = init_quests(rpg->quests);
    rpg->window = initialize_window();
    rpg->particles = init_particles();
    rpg->ret = 0;
}

void initialize_pause_menu(game_t *rpg)
{
    rpg->pause_menu->buttons = malloc(sizeof(button_t) * 5);
    rpg->pause_menu->objs = malloc(sizeof(game_t) * 1);
    rpg->pause_menu->objs[0] = NULL;
    rpg->pause_menu->buttons[0] = init_button_from_string\
    ("960 540 240 240 resources/menu/resume.png", RESUME_BUTTON);
    rpg->pause_menu->buttons[1] = init_button_from_string\
    ("480 540 180 180 resources/pause/home.png", HOME_BUTTON);
    rpg->pause_menu->buttons[2] = init_button_from_string\
    ("1440 540 180 180 resources/menu/music.png", MUSIC_BUTTON);
    rpg->pause_menu->buttons[3] = init_button_from_string\
    ("1840 80 120 120 resources/menu/quit.png", QUIT_BUTTON);
    rpg->pause_menu->buttons[4] = NULL;
    rpg->pause_menu->background = rpg->menu->background;
}

game_t *initialize_all(void)
{
    game_t *rpg = malloc(sizeof(game_t));

    srand((unsigned int)(((size_t)&rpg)));
    initialize_struct(rpg);
    initialize_musics(rpg->musics);
    initialize_menu(rpg);
    initialize_game(rpg);
    initialize_enemies(rpg);
    init_fight_scene(rpg);
    initialize_pause_menu(rpg);
    init_snow(rpg);
    return (rpg);
}