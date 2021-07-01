/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-tanguy.bellicha
** File description:
** remove_enemy
*/

#include "rpg.h"

enemies_t *verify_if_outside(game_t *rpg, enemies_t *current)
{
    enemies_t *tmp = NULL;

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
        remove_enemy_from_list(rpg, current, false);
    }
    return (NULL);
}

void remove_enemy_from_list(game_t *rpg, enemies_t *to_destroy, \
bool destroy)
{
    text_t *text = rpg->play_infos->playing_game->texts[0];
    update_text(text, text->value, 0, (sfVector2f){150 - ((my_strlen\
        (my_itoa(text->value)) - 1) * 13), sfText_getPosition(text->text).y});
    if (destroy)
        destroy_object(to_destroy->enemie_info->mob);
    rpg->play_infos->enemies--;
}