/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-tanguy.bellicha
** File description:
** create_object
*/

#include "rpg.h"


game_object_t *create_object(const char *filepath, sfVector2f pos, \
sfIntRect rect, sfVector2f scale)
{
    game_object_t *object = malloc(sizeof(game_object_t));

    object->texture = sfTexture_createFromFile(filepath, NULL);
    if (object->texture == NULL)
        return (NULL);
    object->rect = rect;
    object->position = pos;
    object->sprite = sfSprite_create();
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setOrigin(object->sprite, (sfVector2f){sfSprite_getGlobalBounds\
        (object->sprite).width / 2, sfSprite_getGlobalBounds\
        (object->sprite).height / 2});
    sfSprite_setScale(object->sprite, scale);
    sfSprite_setTextureRect(object->sprite, object->rect);
    sfSprite_setPosition(object->sprite, object->position);
    return (object);
}