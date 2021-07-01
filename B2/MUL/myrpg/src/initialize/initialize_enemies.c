/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** initialize_enemies
*/

#include "rpg.h"

void create_enemy(game_t *rpg, game_object_t *mob, sfVector2f stats)
{
    enemie_info_t *enemy_info = NULL;

    enemy_info = malloc(sizeof(enemie_info_t));
    enemy_info->mob = mob;
    enemy_info->life = stats.x;
    enemy_info->attack_value = stats.y;
    enemy_info->clock = sfClock_create();
    add_enemy_at_list(rpg, enemy_info);
}

void add_enemy_at_list(game_t *rpg, enemie_info_t *enemy_info)
{
    enemies_t *new = malloc(sizeof(enemies_t));

    new->enemie_info = enemy_info;
    new->next = rpg->play_infos->enemies;
    rpg->play_infos->enemies = new;
}

void init_enemies_list(enemies_t *list)
{
    list = malloc(sizeof(enemies_t));

    list->next = NULL;
    list->enemie_info = NULL;
}