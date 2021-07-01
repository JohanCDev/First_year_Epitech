/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-tanguy.bellicha
** File description:
** create_button
*/

#include "my.h"
#include "defender.h"

void set_params_of_button(s_button *button, char **array, \
sfRenderWindow *window)
{
    sfVector2f pos_ratio;
    sfVector2f size;

    pos_ratio.x = sfRenderWindow_getSize(window).x * \
    (my_getfloat(array[0])/100);
    pos_ratio.y = sfRenderWindow_getSize(window).y * \
    (my_getfloat(array[1])/100);
    size.x = sfRenderWindow_getSize(window).x * (my_getfloat(array[2])/100);
    size.y = (sfRenderWindow_getSize(window).y * (my_getfloat(array[3])/100));
    sfRectangleShape_setOrigin(button->rect, (sfVector2f) \
    {size.x / 2, size.y / 2});
    sfRectangleShape_setPosition(button->rect, pos_ratio);
    sfRectangleShape_setTexture(button->rect, button->texture, 1);
    sfRectangleShape_setSize(button->rect, size);
}

s_button *init_button_from_string(s_game *defender, char const *informations, \
int type)
{
    s_button *button = malloc(sizeof(s_button));
    char **array = my_str_to_word_array(informations);
    sfRenderWindow *window = defender->window;

    button->texture = sfTexture_createFromFile(array[4], NULL);
    button->rect = sfRectangleShape_create();
    set_params_of_button(button, array, window);
    button->button_type = type;
    return (button);
}