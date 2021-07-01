/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-tanguy.bellicha
** File description:
** create_towers
*/

#include "my.h"
#include "defender.h"

void create_sprite_circle_towers(s_tower_info *tower_info, char **array)
{
    sfSprite_setTexture(tower_info->object->sprite, \
    tower_info->object->texture, sfTrue);
    sfSprite_setScale(tower_info->object->sprite, \
    (sfVector2f){my_getfloat(array[9]), my_getfloat(array[10])});
    sfSprite_setTextureRect(tower_info->object->sprite, \
    tower_info->object->rect);
    sfSprite_setPosition(tower_info->object->sprite, \
    tower_info->object->position);
    tower_info->circle = sfCircleShape_create();
    sfCircleShape_setOrigin(tower_info->circle, \
    (sfVector2f){my_getfloat(array[11]), my_getfloat(array[11])});
    sfCircleShape_setPosition(tower_info->circle, \
    (sfVector2f){my_getnbr(array[5]) + sfSprite_getGlobalBounds\
        (tower_info->object->sprite).width/2, my_getnbr(array[6]) + \
        sfSprite_getGlobalBounds(tower_info->object->sprite).height/2});
    sfCircleShape_setRadius(tower_info->circle, my_getfloat(array[11]));
    sfCircleShape_setFillColor(tower_info->circle, \
    (sfColor){50, 50, 50, 120});
    tower_info->clock = sfClock_create();
}

void set_base_settings_tower(s_tower_info *tower_info, char **array)
{
    tower_info->draw_circle = 1;
    tower_info->type = 0;
    tower_info->can_move = 0;
    tower_info->killed_enemies = 0;
    tower_info->offset_rect = my_getnbr(array[12]);
    tower_info->max_value_rect = my_getnbr(array[13]);
    tower_info->price = my_getnbr(array[14]);
    tower_info->damage_hit = my_getfloat(array[15]);
    tower_info->animation_milliseconds = my_getfloat(array[16]);
}

s_tower_info *create_tower_from_string(char const *informations)
{
    s_tower_info *tower_info = malloc(sizeof(s_tower_info));
    char **array = my_str_to_word_array(informations);

    tower_info->object = malloc(sizeof(s_game_object));
    tower_info->object->texture = sfTexture_createFromFile(array[0], NULL);
    tower_info->object->rect = (sfIntRect){my_getnbr(array[1]), \
        my_getnbr(array[2]), my_getnbr(array[3]), my_getnbr(array[4])};
    tower_info->object->position = (sfVector2f){my_getnbr(array[5]), \
        my_getnbr(array[6])};
    tower_info->object->sprite = sfSprite_create();
    sfSprite_setOrigin(tower_info->object->sprite, \
    (sfVector2f){sfSprite_getGlobalBounds(tower_info->object->sprite).width \
        / 2 * my_getnbr(array[7]), sfSprite_getGlobalBounds\
        (tower_info->object->sprite).height / 2 * my_getnbr(array[8])});
    create_sprite_circle_towers(tower_info, array);
    set_base_settings_tower(tower_info, array);
    return (tower_info);
}