/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-tanguy.bellicha
** File description:
** create_button
*/


#include "rpg.h"

void set_params_of_button(button_t *button, char **array)
{
    sfVector2f pos;
    sfVector2f size;

    pos.x = my_getfloat(array[0]);
    pos.y = my_getfloat(array[1]);
    size.x = my_getfloat(array[2]);
    size.y = my_getfloat(array[3]);
    sfRectangleShape_setOrigin(button->rect, (sfVector2f) \
    {size.x / 2, size.y / 2});
    sfRectangleShape_setPosition(button->rect, pos);
    sfRectangleShape_setTexture(button->rect, button->texture, 1);
    sfRectangleShape_setSize(button->rect, size);
}

button_t *init_button_from_string(char const *informations, \
int type)
{
    button_t *button = malloc(sizeof(button_t));
    char **array = my_str_to_word_array(informations);

    button->texture = sfTexture_createFromFile(array[4], NULL);
    button->rect = sfRectangleShape_create();
    set_params_of_button(button, array);
    sfRectangleShape_setTextureRect(button->rect, (sfIntRect){0, 0, 243, 230});
    button->button_type = type;
    return (button);
}