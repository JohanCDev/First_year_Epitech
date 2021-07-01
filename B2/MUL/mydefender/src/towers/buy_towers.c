/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-tanguy.bellicha
** File description:
** buy_towers
*/

#include "my.h"
#include "defender.h"

void drop_tower(s_game *defender, s_tower_info *tower_info)
{
    insert_in_list_towers(defender, tower_info);
    hide_market(defender);
    show_tower_until_release(defender, tower_info);
}

void buy_scientist(s_game *defender)
{
    s_tower_info *tower_info = NULL;

    if (defender->current_scene == defender->play_infos->playing_game && \
    defender->play_infos->playing_game->texts[1]->value >= 60) {
        tower_info = create_tower_from_string(\
        "./resources/towers/scientist.png 0 0 52 68 -200 -200 \
0 0 1.2 1.2 200 60 360 60 1.0 200000");
        tower_info->type = 1;
        drop_tower(defender, tower_info);
        tower_info->can_move = 1;
        sfSprite_setPosition(tower_info->object->sprite, (sfVector2f)\
        {defender->event.mouseButton.x, defender->event.mouseButton.y});
        sfCircleShape_setPosition(tower_info->circle, (sfVector2f)\
        {defender->event.mouseButton.x + sfSprite_getGlobalBounds\
            (tower_info->object->sprite).width/2, \
            defender->event.mouseButton.y + \
            sfSprite_getGlobalBounds(tower_info->object->sprite).height/2});
    }
}

void buy_gel(s_game *defender)
{
    s_tower_info *tower_info = NULL;

    if (defender->current_scene == defender->play_infos->playing_game && \
    defender->play_infos->playing_game->texts[1]->value >= 40) {
        tower_info = create_tower_from_string(\
        "./resources/towers/gel.png 0 0 300 532 -200 -200 1 1 \
0.14 0.14 150 327 1800 40 0.6 160000");
        tower_info->type = 2;
        drop_tower(defender, tower_info);
        tower_info->can_move = 1;
        sfSprite_setPosition(tower_info->object->sprite, (sfVector2f)\
        {defender->event.mouseButton.x, defender->event.mouseButton.y});
        sfCircleShape_setPosition(tower_info->circle, (sfVector2f)\
        {defender->event.mouseButton.x + sfSprite_getGlobalBounds\
            (tower_info->object->sprite).width/2, \
            defender->event.mouseButton.y + \
            sfSprite_getGlobalBounds(tower_info->object->sprite).height/2});
    }
}

void buy_hospitals(s_game *defender)
{
    s_tower_info *tower_info = NULL;

    if (defender->current_scene == defender->play_infos->playing_game && \
    defender->play_infos->playing_game->texts[1]->value >= 100) {
        tower_info = create_tower_from_string(\
        "./resources/towers/hospital.png 0 0 740 657 -200 -200 \
0 0 0.12 0.12 120 740 740 100 0.8 800000");
        tower_info->type = 3;
        drop_tower(defender, tower_info);
        tower_info->can_move = 1;
        sfSprite_setPosition(tower_info->object->sprite, (sfVector2f)\
        {defender->event.mouseButton.x, defender->event.mouseButton.y});
        sfCircleShape_setPosition(tower_info->circle, (sfVector2f)\
        {defender->event.mouseButton.x + sfSprite_getGlobalBounds\
            (tower_info->object->sprite).width/2, \
            defender->event.mouseButton.y + \
            sfSprite_getGlobalBounds(tower_info->object->sprite).height/2});
    }
}

void buy_medic(s_game *defender)
{
    s_tower_info *tower_info = NULL;

    if (defender->current_scene == defender->play_infos->playing_game && \
    defender->play_infos->playing_game->texts[1]->value >= 140) {
        tower_info = create_tower_from_string(\
        "./resources/towers/medic.png 0 0 302 108 -200 -200 0 0 \
0.24 0.24 320 302 2407 140 2.4 240000");
        tower_info->type = 4;
        drop_tower(defender, tower_info);
        tower_info->can_move = 1;
        sfSprite_setPosition(tower_info->object->sprite, (sfVector2f)\
        {defender->event.mouseButton.x, defender->event.mouseButton.y});
        sfCircleShape_setPosition(tower_info->circle, (sfVector2f)\
        {defender->event.mouseButton.x + sfSprite_getGlobalBounds\
            (tower_info->object->sprite).width/2, \
            defender->event.mouseButton.y + \
            sfSprite_getGlobalBounds(tower_info->object->sprite).height/2});
    }
}