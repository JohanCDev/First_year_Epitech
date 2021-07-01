/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-tanguy.bellicha
** File description:
** create_object
*/

#include "defender.h"
#include "my.h"

s_game_object *create_object(const char *filepath, sfVector2f pos, \
sfIntRect rect, sfVector2f scale)
{
    s_game_object *object = malloc(sizeof(s_game_object));

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