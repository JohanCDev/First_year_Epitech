/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myrunner-johan.chrillesen
** File description:
** create_and_destroy
*/

#include "runner.h"
#include "my.h"

object_s *create_object(const char *path, sfVector2f pos, sfIntRect rect, \
sfVector2f size)
{
    object_s *object = malloc(sizeof(*object));

    object->texture = sfTexture_createFromFile(path, NULL);
    if (object->texture == NULL)
        return (NULL);
    object->rect = rect;
    object->position = pos;
    object->sprite = sfSprite_create();
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    if (object->sprite == NULL)
        return (NULL);
    sfSprite_setScale(object->sprite, size);
    sfSprite_setTextureRect(object->sprite, object->rect);
    sfSprite_setPosition(object->sprite, pos);
    return (object);
}

game_s *create_parallax(game_s *game)
{
    sfVector2f size = {1, 1};

    game->big_bg = create_object("resources/images/backgrounds/big.png", \
    create_vector(0, 0), create_rect(0, 0, 1920, 1080), size);
    game->mid_bg = create_object("resources/images/backgrounds/middle.png", \
    create_vector(0, 350), create_rect(0, 0, 1920, 1080), size);
    game->front_bg = create_object("resources/images/backgrounds/small.png", \
    create_vector(0, 300), create_rect(0, 0, 1920, 1080), size);
    game->ground = create_object("resources/images/backgrounds/ground.png", \
    create_vector(0, 925), create_rect(0, 0, 1920, 23), size);
    sfTexture_setRepeated(game->big_bg->texture, 1);
    sfTexture_setRepeated(game->mid_bg->texture, 1);
    sfTexture_setRepeated(game->front_bg->texture, 1);
    sfTexture_setRepeated(game->ground->texture, 1);
    return (game);
}

win_s create_window(char const *name)
{
    win_s window;

    window.mode.height = 1080;
    window.mode.width = 1920;
    window.mode.bitsPerPixel = 32;
    window.window = sfRenderWindow_create(window.mode, name, sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window.window, 25);
    sfRenderWindow_clear(window.window, sfBlack);
    return (window);
}

void create_score_label(char const *filepath, game_s *game)
{
    game->score.font = sfFont_createFromFile(filepath);
    game->score.text = sfText_create();
    sfText_setFont(game->score.text, game->score.font);
    sfText_setCharacterSize(game->score.text, 60);
}