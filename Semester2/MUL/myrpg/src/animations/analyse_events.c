/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-johan.chrillesen
** File description:
** analyse_events
*/

#include "rpg.h"

void analyse_other_key_events(game_t *rpg)
{
    switch (rpg->event.key.code) {
    case sfKeyD :
        rpg->play_infos->key_pressed.go_right = true;
        rpg->play_infos->player->map_pos.x += 5.0 / (3453 / 1920);
        sfSprite_setTexture(rpg->play_infos->player->sprite, \
        rpg->play_infos->player->textures->run, sfFalse);
        break;
    case sfKeyF :
        detect_fighting(rpg);
        break;
    case sfKeyI :
        detect_inv(rpg);
    default :
        break;
    }
}

void analyse_key_events_second(game_t *rpg)
{
    switch (rpg->event.key.code) {
    case sfKeyQ :
        rpg->play_infos->key_pressed.go_left = true;
        rpg->play_infos->player->map_pos.x -= 5.0 / (3453 / 1920);
        sfSprite_setTexture(rpg->play_infos->player->sprite, \
        rpg->play_infos->player->textures->run_reversed, sfFalse);
        break;
    case sfKeyS :
        rpg->play_infos->key_pressed.go_down = true;
        rpg->play_infos->player->map_pos.y += 5.0 / (1941 / 1080);
        sfSprite_setTexture(rpg->play_infos->player->sprite, \
        rpg->play_infos->player->textures->run_reversed, sfFalse);
        break;
    default :
        analyse_other_key_events(rpg);
    }
}

void analyse_key_events(game_t *rpg)
{
    check_travel_quest(rpg, rpg->quests->travel);
    if (rpg->current_scene != rpg->play_infos->playing_game && \
        rpg->current_scene != rpg->inventory)
        return;
    switch (rpg->event.key.code) {
    case sfKeyEscape :
        escape_is_pressed(rpg);
        break;
    case sfKeyZ :
        rpg->play_infos->key_pressed.go_up = true;
        rpg->play_infos->player->map_pos.y -= 5.0 / (1941 / 1080);
        sfSprite_setTexture(rpg->play_infos->player->sprite, \
        rpg->play_infos->player->textures->run, sfFalse);
        break;
    default :
        analyse_key_events_second(rpg);
    }
}

void analyse_events(game_t *rpg)
{
    switch (rpg->event.type) {
    case sfEvtClosed :
        rpg->ret = 1;
        break;
    case sfEvtMouseButtonPressed :
        mouse_button_is_pressed(rpg);
        break;
    case sfEvtKeyPressed :
        analyse_key_events(rpg);
        execute_movement(rpg);
        break;
    case sfEvtMouseMoved :
        mouse_is_moved(rpg);
        break;
    case sfEvtKeyReleased :
        key_is_released(rpg);
        break;
    default :
        check_boss_is_dead(rpg);
    }
}

void mouse_button_is_pressed(game_t *rpg)
{
    for (int i = 0; rpg->current_scene->buttons[i]; i++) {
        if (button_is_clicked(rpg, rpg->current_scene->buttons[i], \
            rpg->event.mouseButton))
            break;
    }
}