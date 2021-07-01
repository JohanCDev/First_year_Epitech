/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-johan.chrillesen
** File description:
** intialize_fight
*/

#include "rpg.h"

void init_fight_scene(game_t *rpg)
{
    rpg->fight = malloc(sizeof(scene_t));
    rpg->fight->buttons = malloc(sizeof(button_t));
    rpg->fight->objs = malloc(sizeof(game_object_t));
    rpg->fight->background = create_object("./resources/fight_bg.png", \
    (sfVector2f) {960, 540}, (sfIntRect) {0, 0, 3840, 2160}, \
    (sfVector2f) {1, 1});
    rpg->fight->texts = malloc(sizeof(text_t) * 3);
    rpg->fight->buttons[0] = NULL;
    rpg->fight->texts[0] = init_text("./resources/font.ttf", \
    (sfVector2f){25, 25}, rpg->play_infos->player->life, 75);
    rpg->fight->texts[1] = init_text("./resources/font.ttf", \
    (sfVector2f){1825, 25}, 50, 75);
    rpg->fight->texts[2] = init_text_str("./resources/font.ttf", \
    (sfVector2f){900, 25}, "LIFE", 75);
    rpg->fight->texts[3] = NULL;
    rpg->fight->objs[0] = NULL;
}