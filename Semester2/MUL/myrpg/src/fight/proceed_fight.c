/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-johan.chrillesen
** File description:
** proceed_fight
*/

#include "rpg.h"

int player_turn(game_t *rpg, enemie_info_t *enemie_info)
{
    int played = 0;

    while (played == 0) {
        if (sfRenderWindow_pollEvent(rpg->window, &rpg->event) == sfFalse)
            return (-3);
        switch (rpg->event.type) {
        case sfEvtClosed:
            rpg->ret = 1;
            return (-2);
        case sfEvtKeyPressed:
            played = switch_fight_key(rpg, enemie_info, played);
        default:
            break;
        }
    }
    return (played);
}

void enemy_attacks(enemie_info_t *enemie_info, game_t *rpg, int damage)
{
    if (rand() % 2 == 1) {
        enemie_info->life += 20.0;
    } else {
        rpg->play_infos->player->life -= damage;
    }
}

void enemie_turn(game_t *rpg, enemie_info_t *enemie_info, int ret_player)
{
    int damage = rand() % (enemie_info->attack_value / 3);

    if (ret_player == -1) {
        if (enemie_info->life < 10.0) {
            enemy_attacks(enemie_info, rpg, damage);
        } else {
            rpg->play_infos->player->life -= damage;
        }
        rpg->play_infos->player->life += (enemie_info->attack_value / 5);
    } else {
        damage = rand() % enemie_info->attack_value;
        if (enemie_info->life < 10.0) {
            enemy_attacks(enemie_info, rpg, damage);
        } else {
            rpg->play_infos->player->life -= damage;
        }
    }
    sfText_setString(rpg->fight->texts[0]->text, \
    my_itoa(rpg->play_infos->player->life));
}

void player_won(game_t *rpg)
{
    loot(rpg->play_infos->player->inv, rand() % 4);
}