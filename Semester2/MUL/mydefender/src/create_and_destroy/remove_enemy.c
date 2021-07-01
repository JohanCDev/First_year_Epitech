/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-tanguy.bellicha
** File description:
** remove_enemy
*/

#include "defender.h"
#include "my.h"

s_enemies *verify_if_outside(s_game *defender, s_enemies *current)
{
    s_enemies *tmp = NULL;

    if (current->next != NULL) {
        if (sfSprite_getPosition\
        (current->next->enemie_info->mob->sprite).x > 1700) {
            tmp = current->next;
            current->next = current->next->next;
            return (tmp);
        }
    } else if (sfSprite_getPosition(current->enemie_info->mob->sprite).x \
    > 1700 && current->enemie_info->life != 0) {
        current->enemie_info->life = 0;
        remove_enemy_from_list(defender, current, false);
    }
    return (NULL);
}

void remove_enemy_from_list(s_game *defender, s_enemies *to_destroy, \
bool destroy)
{
    s_text *text = defender->play_infos->playing_game->texts[0];

    text->value -= to_destroy->enemie_info->base_speed;
    update_text(text, text->value, 0, (sfVector2f){150 - ((my_strlen\
        (my_itoa(text->value)) - 1) * 13), sfText_getPosition(text->text).y});
    if (destroy)
        destroy_object(to_destroy->enemie_info->mob);
    defender->play_infos->nb_enemies--;
}