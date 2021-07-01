/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-tanguy.bellicha
** File description:
** towers
*/

#include "my.h"
#include "defender.h"

void insert_in_list_towers(s_game *defender, s_tower_info *tower_info)
{
    s_towers *new = malloc(sizeof(s_towers));

    if (new == NULL)
        return;
    new->tower_info = tower_info;
    new->next = defender->play_infos->towers;
    defender->play_infos->towers = new;
}

void add_tower_in_window(s_game *defender)
{
    s_towers *current = defender->play_infos->towers;

    while (current != NULL) {
        if (current->tower_info->object != NULL) {
            sfRenderWindow_drawSprite(defender->window, \
            current->tower_info->object->sprite, NULL);
        }
        current = current->next;
    }
}

void animate_towers(s_towers *current, s_game *defender)
{
    if (sfClock_getElapsedTime(current->tower_info->clock).microseconds \
    >= current->tower_info->animation_milliseconds && \
    current->tower_info->can_move && \
    detect_enemies_in_circle(defender, current->tower_info, false, \
    current->tower_info->type / 3 - current->tower_info->type % 3)) {
        move_rect(&current->tower_info->object->rect, \
        current->tower_info->offset_rect, \
        current->tower_info->max_value_rect);
        if (current->tower_info->object->rect.left >= \
            current->tower_info->max_value_rect - \
            current->tower_info->offset_rect)
            detect_enemies_in_circle(defender, current->tower_info, true, \
            current->tower_info->type / 3 - current->tower_info->type % 3);
        sfClock_restart(current->tower_info->clock);
    } else if (!detect_enemies_in_circle(defender, current->tower_info, \
        false, current->tower_info->type / 3 - current->tower_info->type % 3))
        current->tower_info->object->rect.left = 0;
}

void detect_click_on_tower(s_towers *current, s_game *defender, \
sfFloatRect tower_rect)
{
    if (defender->event.type == sfEvtMouseButtonPressed && \
    (!defender->play_infos->show_menu || \
    (defender->play_infos->show_menu && \
    defender->event.mouseButton.x < 1600 - 581))) {
        current->tower_info->draw_circle = sfFloatRect_contains\
        (&tower_rect, defender->event.mouseButton.x, \
        defender->event.mouseButton.y);
    }
}

void display_towers(s_game *defender)
{
    s_towers *current = defender->play_infos->towers;
    sfFloatRect tower_rect;

    while (current != NULL) {
        sfRenderWindow_pollEvent(defender->window, &defender->event);
        tower_rect = sfSprite_getGlobalBounds\
        (current->tower_info->object->sprite);
        detect_click_on_tower(current, defender, tower_rect);
        if (current->tower_info->draw_circle || !current->tower_info->can_move)
            sfRenderWindow_drawCircleShape(defender->window, \
            current->tower_info->circle, NULL);
        sfRenderWindow_drawSprite(defender->window, \
        current->tower_info->object->sprite, NULL);
        animate_towers(current, defender);
        sfSprite_setTextureRect(current->tower_info->object->sprite, \
        current->tower_info->object->rect);
        current = current->next;

    }
}
