/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-tanguy.bellicha
** File description:
** tower_interact_enemies
*/

#include "my.h"
#include "defender.h"

bool can_attack_this_enemie(s_tower_info *tower_info, \
s_enemie_info *enemie_info)
{
    sfFloatRect circle_tower;

    circle_tower = sfCircleShape_getGlobalBounds(tower_info->circle);
    if (sfFloatRect_contains(&circle_tower, sfSprite_getPosition\
        (enemie_info->mob->sprite).x, sfSprite_getPosition\
        (enemie_info->mob->sprite).y) && enemie_info->life > 0)
        return (true);
    return (false);
}

void kill_enemy(s_game *defender, s_enemie_info *enemie_info)
{
    if (enemie_info->life <= 0) {
        update_text(defender->play_infos->playing_game->texts[1], \
        4 * enemie_info->base_speed, 1, (sfVector2f){150 - ((my_strlen\
            (my_itoa(defender->play_infos->playing_game->texts[1]->value)) \
            - 1) * 13), sfText_getPosition\
            (defender->play_infos->playing_game->texts[1]->text).y});
        defender->play_infos->nb_enemies--;
    }
}

void attack_enemy(bool attack, s_game *defender, s_enemie_info *enemie_info, \
s_tower_info *tower)
{
    if (attack) {
        enemie_info->life -= tower->damage_hit;
        kill_enemy(defender, enemie_info);
        if (tower->type == 2 && enemie_info->base_speed != 1) {
            enemie_info->current_speed = enemie_info->base_speed - 1;
            sfClock_restart(enemie_info->speed_clock);
        }
    }
}

bool detect_enemies_in_circle(s_game *defender, \
s_tower_info *tower_info, bool attack, int area_damage)
{
    s_enemies *current = defender->play_infos->enemies;
    int detected_area = 0;

    while (current != NULL) {
        if (can_attack_this_enemie(tower_info, current->enemie_info)) {
            if (attack)
                attack_enemy(attack, defender, \
                current->enemie_info, tower_info);
            if (!area_damage)
                return (true);
            detected_area = 1;
        }
        current = current->next;
    }
    if (detected_area)
        return (true);
    return (false);
}