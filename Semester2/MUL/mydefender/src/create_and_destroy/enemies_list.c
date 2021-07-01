/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-tanguy.bellicha
** File description:
** enemies_list
*/

#include "defender.h"
#include "my.h"

void insert_in_list_enemie(s_game *defender, s_enemie_info *enemie_info)
{
    s_enemies *new = malloc(sizeof(s_enemies));

    if (new == NULL)
        return;
    new->enemie_info = enemie_info;
    new->next = defender->play_infos->enemies;
    defender->play_infos->enemies = new;
}

void add_enemie_in_window(s_game *defender)
{
    s_enemies *current = defender->play_infos->enemies;

    while (current != NULL) {
        if (current->enemie_info->mob->sprite != NULL && \
            current->enemie_info->life > 0)
            sfRenderWindow_drawSprite(defender->window, \
            current->enemie_info->mob->sprite, NULL);
        current = current->next;
    }
}

void act_on_enemy(s_enemies *current, s_game *defender)
{
    s_enemies *to_destroy = NULL;

    if (current->enemie_info->life > 0)
        add_enemie_in_window(defender);
    if (sfClock_getElapsedTime(current->enemie_info->clock).microseconds \
    > 16000 && current->enemie_info->life > 0) {
        for (int i = 0; i < current->enemie_info->current_speed; i++) {
            current->enemie_info->direction = \
            check_next_direction(defender, current->enemie_info);
            sfSprite_move(current->enemie_info->mob->sprite, \
            current->enemie_info->direction);
        }
        sfSprite_setRotation(current->enemie_info->mob->sprite, \
        sfSprite_getRotation(current->enemie_info->mob->sprite) + 1.4);
        sfClock_restart(current->enemie_info->clock);
        if ((to_destroy = verify_if_outside(defender, current)) != NULL)
            remove_enemy_from_list(defender, to_destroy, true);
    }
}

void display_enemies(s_game *defender)
{
    s_enemies *current = defender->play_infos->enemies;

    while (defender->play_infos->nb_enemies > 0 && current != NULL) {
        act_on_enemy(current, defender);
        if (sfClock_getElapsedTime(current->enemie_info->speed_clock).\
        microseconds > 1600000 && \
        current->enemie_info->base_speed != \
        current->enemie_info->current_speed) {
            current->enemie_info->current_speed = \
            current->enemie_info->base_speed;
        }
        current = current->next;
    }
}