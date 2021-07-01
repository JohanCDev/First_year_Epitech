/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-tanguy.bellicha
** File description:
** differents_enemies
*/

#include "my.h"
#include "defender.h"

void create_ch(s_game *defender, int pos_x)
{
    s_enemie_info *enemie_info = NULL;

    if (defender->current_scene == defender->play_infos->playing_game) {
        enemie_info = malloc(sizeof(s_enemie_info));
        enemie_info->mob = create_object\
        ("./resources/enemies/ch_corona.png", \
        (sfVector2f){pos_x, get_start_y(defender, pos_x)}, \
        create_rect(0, 0, 170, 169), \
        (sfVector2f){0.5, 0.5});
        enemie_info->life = 2.0;
        enemie_info->base_speed = 1;
        enemie_info->current_speed = enemie_info->base_speed;
        enemie_info->direction = (sfVector2f) {1, 0};
        enemie_info->clock = sfClock_create();
        enemie_info->speed_clock = sfClock_create();
        defender->play_infos->nb_enemies++;
        insert_in_list_enemie(defender, enemie_info);
    }
}

void create_br(s_game *defender, int pos_x)
{
    s_enemie_info *enemie_info = NULL;

    if (defender->current_scene == defender->play_infos->playing_game) {
        enemie_info = malloc(sizeof(s_enemie_info));
        enemie_info->mob = create_object\
        ("./resources/enemies/br_corona.png", \
        (sfVector2f){pos_x, get_start_y(defender, pos_x)}, \
        create_rect(0, 0, 170, 169), \
        (sfVector2f){0.5, 0.5});
        enemie_info->life = 3.0;
        enemie_info->base_speed = 2;
        enemie_info->current_speed = enemie_info->base_speed;
        enemie_info->direction = (sfVector2f) {1, 0};
        enemie_info->clock = sfClock_create();
        enemie_info->speed_clock = sfClock_create();
        defender->play_infos->nb_enemies++;
        insert_in_list_enemie(defender, enemie_info);
    }
}

void create_sa(s_game *defender, int pos_x)
{
    s_enemie_info *enemie_info = NULL;

    if (defender->current_scene == defender->play_infos->playing_game) {
        enemie_info = malloc(sizeof(s_enemie_info));
        enemie_info->mob = create_object\
        ("./resources/enemies/sa_corona.png", \
        (sfVector2f){pos_x, get_start_y(defender, pos_x)}, \
        create_rect(0, 0, 170, 169), \
        (sfVector2f){0.5, 0.5});
        enemie_info->life = 4.0;
        enemie_info->base_speed = 2;
        enemie_info->current_speed = enemie_info->base_speed;
        enemie_info->direction = (sfVector2f) {1, 0};
        enemie_info->clock = sfClock_create();
        enemie_info->speed_clock = sfClock_create();
        defender->play_infos->nb_enemies++;
        insert_in_list_enemie(defender, enemie_info);
    }
}

void create_bg(s_game *defender, int pos_x)
{
    s_enemie_info *enemie_info = NULL;

    if (defender->current_scene == defender->play_infos->playing_game) {
        enemie_info = malloc(sizeof(s_enemie_info));
        enemie_info->mob = create_object\
        ("./resources/enemies/bg_corona.png", \
        (sfVector2f){pos_x, get_start_y(defender, pos_x)}, \
        create_rect(0, 0, 170, 169), \
        (sfVector2f){0.5, 0.5});
        enemie_info->life = 4.0;
        enemie_info->base_speed = 3;
        enemie_info->current_speed = enemie_info->base_speed;
        enemie_info->direction = (sfVector2f) {1, 0};
        enemie_info->clock = sfClock_create();
        enemie_info->speed_clock = sfClock_create();
        defender->play_infos->nb_enemies++;
        insert_in_list_enemie(defender, enemie_info);
    }
}