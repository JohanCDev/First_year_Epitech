/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init_inv
*/

#include "rpg.h"

text_t *init_inv_text(text_t *text)
{
    sfVector2f pos = {735, 200};

    text = malloc(sizeof(text_t));
    text->font = sfFont_createFromFile("./resources/font.ttf");
    text->text = sfText_create();
    text->value = 0;
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, 120);
    sfText_setString(text->text, "INVENTORY\n");
    sfText_setPosition(text->text, pos);
    return text;
}

text_t *init_life_text(text_t *text)
{
    sfVector2f pos = {885, 610};

    text = malloc(sizeof(text_t));
    text->font = sfFont_createFromFile("./resources/font.ttf");
    text->text = sfText_create();
    text->value = 100;
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, 120);
    sfText_setString(text->text, my_itoa(text->value));
    sfText_setPosition(text->text, pos);
    sfText_setColor(text->text, sfRed);
    return text;
}

text_t *init_full_success_text(text_t *text)
{
    sfVector2f pos = {600, 760};

    text = malloc(sizeof(text_t));
    text->font = sfFont_createFromFile("./resources/font.ttf");
    text->text = sfText_create();
    text->value = 0;
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, 60);
    sfText_setString(text->text, "Incomplete : Get Full Inventory\n");
    sfText_setPosition(text->text, pos);
    sfText_setColor(text->text, sfRed);
    return text;
}

text_t *init_multiple_success_text(text_t *text)
{
    sfVector2f pos = {550, 860};

    text = malloc(sizeof(text_t));
    text->font = sfFont_createFromFile("./resources/font.ttf");
    text->text = sfText_create();
    text->value = 0;
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, 60);
    sfText_setString(text->text, "Incomplete : Get All items (3 in total)\n");
    sfText_setPosition(text->text, pos);
    sfText_setColor(text->text, sfRed);
    return text;
}

scene_t *init_inv_texts(scene_t *inv)
{
    inv->texts = malloc(sizeof(text_t) * (14));
    inv->texts[0] = init_inv_text(inv->texts[0]);
    inv->texts[1] = init_life_text(inv->texts[1]);
    inv->texts[2] = init_full_success_text(inv->texts[2]);
    inv->texts[3] = init_multiple_success_text(inv->texts[3]);
    inv->texts = init_travels_texts(inv->texts);
    inv->texts[13] = NULL;
    return inv;
}