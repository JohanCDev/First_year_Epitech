/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-tanguy.bellicha
** File description:
** wave_chrono
*/

#include "defender.h"
#include "my.h"

void display_text_if_sup_or_eq_to_zero(s_game *defender)
{
    if (defender->play_infos->playing_game->texts[6]->value > -1) {
        update_text(defender->play_infos->playing_game->texts[6], \
        defender->play_infos->playing_game->texts[6]->value, 0, \
        (sfVector2f) {792, 20});
    }
}

void display_wave_chrono(s_game *defender)
{
    if (sfClock_getElapsedTime(defender->play_infos->main_clock).microseconds \
    >= 1000000) {
        defender->play_infos->playing_game->texts[6]->value--;
        display_text_if_sup_or_eq_to_zero(defender);
        if (defender->play_infos->playing_game->texts[6]->value <= 0 && \
        !defender->play_infos->active_wave) {
            update_text(defender->scoreboard->texts[0], 1, 1, \
            (sfVector2f){780, 480});
            create_wave(defender);
            defender->play_infos->current_difficulty *= 1.32;
            defender->play_infos->playing_game->texts[6]->value = 20;
            defender->play_infos->active_wave = true;
        } else if ((defender->play_infos->playing_game->texts[6]->value == -1 \
        || defender->play_infos->nb_enemies == 0) && \
        defender->play_infos->active_wave) {
            defender->play_infos->playing_game->texts[6]->value = 8;
            defender->play_infos->active_wave = false;
        } else
            sfClock_restart(defender->play_infos->main_clock);
    }
}