/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-johan.chrillesen
** File description:
** destroy_others
*/

#include "rpg.h"

void destroy_texts(text_t *text)
{
    if (text) {
        if (text->font)
            sfFont_destroy(text->font);
        if (text->text)
            sfText_destroy(text->text);
        free(text);
        text = NULL;
    }
}

void destroy_particles(particles_t *particles)
{
    destroy_object(particles->particle);
    sfClock_destroy(particles->clock);
}