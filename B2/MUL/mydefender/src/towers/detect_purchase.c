/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-tanguy.bellicha
** File description:
** detect_purchase
*/

#include "defender.h"
#include "my.h"

void detect_first_line_market(s_game *defender, s_game_object *object)
{
    if (sfSprite_getPosition(object->sprite).x < 1400)
        buy_gel(defender);
    if (sfSprite_getPosition(object->sprite).x > 1400)
        buy_scientist(defender);
}

void detect_second_line_market(s_game *defender, s_game_object *object)
{
    if (sfSprite_getPosition(object->sprite).x < 1400)
        buy_hospitals(defender);
    if (sfSprite_getPosition(object->sprite).x > 1400)
        buy_medic(defender);
}