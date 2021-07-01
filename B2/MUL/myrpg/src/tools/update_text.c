/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share
** File description:
** update_text
*/


#include "rpg.h"

void update_text(text_t *text, int value, bool add, sfVector2f pos)
{
    if (add == false)
        text->value = value;
    else
        text->value += value;
    text->potext_t = pos;
    sfText_setPosition(text->text, text->potext_t);
    sfText_setString(text->text, my_itoa(text->value));
}