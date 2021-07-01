/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-johan.chrillesen
** File description:
** reset_inv
*/

#include "rpg.h"

void reset_inventory(game_t *rpg)
{
    for (int i = 2; i < INV_FULL; i++)
        empty_inv_slot(rpg->play_infos->player->inv[i], "./resources/inv.png");
}