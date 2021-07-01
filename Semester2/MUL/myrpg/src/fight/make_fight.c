/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-johan.chrillesen
** File description:
** make_fight
*/

#include "rpg.h"

void switch_ennemies_turn_for_fight(game_t *rpg, enemie_info_t *enemie_info)
{
    int ret_player = 0;

    while (1) {
        update_fight_scene(rpg, enemie_info);
        ret_player = player_turn(rpg, enemie_info);
        if (ret_player == -3)
            continue;
        if (continue_fight(rpg, enemie_info, ret_player) == 1)
            break;
        if (ret_player == -2) {
            return;
        }
        update_fight_scene(rpg, enemie_info);
        if (proceed_enemy_turn(rpg, enemie_info, ret_player) == 1)
            return;
    }
}