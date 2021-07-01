/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight_scene
*/

#include "rpg.h"

void attack_for_fight(game_t *rpg, enemie_info_t *enemie_info)
{
    enemie_info->life -= rpg->play_infos->player->attack_value;
    sfText_setString(rpg->fight->texts[1]->text, \
    my_itoa(enemie_info->life));
    rpg->particles->display = true;
}

int switch_fight_key(game_t *rpg, enemie_info_t *enemie_info, int played)
{
    switch (rpg->event.key.code) {
    case sfKeyA :
        attack_for_fight(rpg, enemie_info);
        played = 1;
        break;
    case sfKeyE :
        played = -1;
        rpg->play_infos->player->life += (rand() % \
        (int)(enemie_info->attack_value * 1.33));
        if (rpg->play_infos->player->life >= 100)
            rpg->play_infos->player->life = 100;
        break;
    case sfKeyR :
        played = 2;
        break;
    default:
        break;
    } return (played);
}

int continue_fight(game_t *rpg, enemie_info_t *enemie_info, int ret_player)
{
    if (ret_player == 2) {
        rpg->current_scene = rpg->play_infos->playing_game;
        return (1);
    } else if (ret_player == 1 && enemie_info->life <= 0) {
        rpg->particles->display = false;
        player_won(rpg);
        rpg->current_scene = rpg->play_infos->playing_game;
        rpg->play_infos->player->attack_value += 2;
        return (1);
    }
    return (0);
}

int proceed_enemy_turn(game_t *rpg, enemie_info_t *enemie_info, \
int ret_player)
{
    enemie_turn(rpg, enemie_info, ret_player);
    rpg->particles->display = false;
    if (rpg->play_infos->player->life <= 0) {
        return (1);
    }
    return (0);
}

void fight_scene(game_t *rpg, enemie_info_t *enemie_info)
{
    t_tmp_fight tmp = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
    int check_boss = check_boss_fight(rpg, enemie_info);

    if (check_boss == 0)
        return;
    tmp = initialize_fight(rpg, enemie_info, \
    sfSprite_getScale(enemie_info->mob->sprite));
    switch_ennemies_turn_for_fight(rpg, enemie_info);
    end_fight(rpg, tmp, enemie_info);
}