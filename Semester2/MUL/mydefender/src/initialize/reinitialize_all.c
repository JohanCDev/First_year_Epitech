/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-tanguy.bellicha
** File description:
** reinitialize_all
*/

#include "my.h"
#include "defender.h"

void reinitialize_objects(s_game *defender)
{
    for (int i = 0; defender->play_infos->playing_game->objs[i]; i++)
        destroy_object(defender->play_infos->playing_game->objs[i]);
}

void reinitialize_towers(s_game *defender)
{
    s_towers *current_tower = defender->play_infos->towers;

    while (current_tower != NULL) {
        destroy_object(current_tower->tower_info->object);
        current_tower = current_tower->next;
    }
    defender->play_infos->towers = NULL;
}

void reinitialize_enemies(s_game *defender)
{
    s_enemies *current_enemy = defender->play_infos->enemies;

    while (current_enemy != NULL) {
        destroy_object(current_enemy->enemie_info->mob);
        sfClock_destroy(current_enemy->enemie_info->clock);
        current_enemy = current_enemy->next;
    }
    defender->play_infos->nb_enemies = 0;
    defender->play_infos->enemies = NULL;
}

void reinitialize_all(s_game *defender)
{
    sfImage_destroy(defender->map_path);
    defender->map_path = \
    sfImage_createFromFile("./resources/maps/path.png");
    reinitialize_towers(defender);
    reinitialize_enemies(defender);
    defender->play_infos->current_difficulty = 10;
    defender->play_infos->show_menu = false;
    update_text(defender->play_infos->playing_game->texts[0], \
    50, 0, (sfVector2f) {126, 24});
    update_text(defender->play_infos->playing_game->texts[1], \
    150, 0, (sfVector2f) {126, 64});
    update_text(defender->play_infos->playing_game->texts[6], \
    8, 0, (sfVector2f){792, 20});
    update_text(defender->scoreboard->texts[0], \
    0, 0, (sfVector2f){792, 80});
}