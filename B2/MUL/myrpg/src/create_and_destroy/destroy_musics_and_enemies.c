/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-johan.chrillesen
** File description:
** destroy_musics_and_enemies
*/

#include "rpg.h"

void destroy_musics(musics_t *musics)
{
    if (musics->main_music)
        sfMusic_destroy(musics->main_music);
    if (musics->button_sound)
        sfMusic_destroy(musics->button_sound);
}