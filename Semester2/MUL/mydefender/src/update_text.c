/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share
** File description:
** update_text
*/

#include "my.h"
#include "defender.h"

void update_text(s_text *text, int value, bool add, sfVector2f pos)
{
    if (add == false)
        text->value = value;
    else
        text->value += value;
    text->pos_text = pos;
    sfText_setPosition(text->text, text->pos_text);
    sfText_setString(text->text, my_itoa(text->value));
}