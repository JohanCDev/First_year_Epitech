/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-johan.chrillesen
** File description:
** init_other
*/

#include "rpg.h"

sfRenderWindow *initialize_window(void)
{
    int width = 1920;
    int height = 1080;

    sfVideoMode mode = {width, height, 32};
    sfRenderWindow *window = sfRenderWindow_create\
    (mode, "myrpg", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

particles_t *init_particles(void)
{
    particles_t *particles = malloc(sizeof(particles_t));

    if (particles == NULL)
        return NULL;
    particles->particle = create_object\
    ("./resources/objects/particle_blood.png", (sfVector2f) {3050, 850}, \
    (sfIntRect) {0, 0, 90, 64}, (sfVector2f) {2, 2});
    particles->current_sprite = 0;
    particles->clock = sfClock_create();
    particles->display = false;
    return particles;
}

void initialize_musics(musics_t *musics)
{
    musics->main_music = sfMusic_createFromFile\
    ("./resources/sounds/main_music.ogg");
    sfMusic_play(musics->main_music);
    sfMusic_setLoop(musics->main_music, sfTrue);
    sfMusic_setVolume(musics->main_music, 50);
    musics->button_sound = sfMusic_createFromFile\
    ("./resources/sounds/button_sound.ogg");
}

text_t *init_text_str(char *filepath, sfVector2f position, char *str, int size)
{
    text_t *label = malloc(sizeof(text_t));

    label->font = sfFont_createFromFile(filepath);
    label->text = sfText_create();
    label->value = 0;
    sfText_setFont(label->text, label->font);
    sfText_setCharacterSize(label->text, size);
    sfText_setString(label->text, str);
    sfText_setPosition(label->text, position);
    return (label);
}

text_t *init_text(char *filepath, sfVector2f position, int value, int size)
{
    text_t *label = malloc(sizeof(text_t));

    label->font = sfFont_createFromFile(filepath);
    label->text = sfText_create();
    label->value = value;
    sfText_setFont(label->text, label->font);
    sfText_setCharacterSize(label->text, size);
    sfText_setString(label->text, my_itoa(value));
    sfText_setPosition(label->text, position);
    return (label);
}