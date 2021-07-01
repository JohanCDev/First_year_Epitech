/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init_travel_texts
*/

#include "rpg.h"

text_t *init_travel_text(text_t *text, char *region, sfVector2f pos)
{
    text->font = sfFont_createFromFile("./resources/font.ttf");
    text->text = sfText_create();
    text->value = 0;
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, 60);
    sfText_setString(text->text, region);
    sfText_setPosition(text->text, pos);
    sfText_setColor(text->text, sfRed);
    return text;
}

text_t **init_travels_texts(text_t **texts)
{
    for (int i = 4; i < 13; i++)
        texts[i] = malloc(sizeof(text_t));
    texts[4] = init_travel_text(texts[4], "Snow", (sfVector2f){1500, 50});
    texts[5] = init_travel_text(texts[5], "Hell", (sfVector2f){1500, 150});
    texts[6] = init_travel_text(texts[6], "Farm", (sfVector2f){1500, 250});
    texts[7] = init_travel_text(texts[7], "Forest", (sfVector2f){1500, 350});
    texts[8] = init_travel_text(texts[8], "Sea", (sfVector2f){1500, 450});
    texts[9] = init_travel_text(texts[9], "Graveyard", (sfVector2f){1500, 550});
    texts[10] = init_travel_text(texts[10], "Cave", (sfVector2f){1500, 650});
    texts[11] = init_travel_text(texts[11], "Castle", (sfVector2f){1500, 750});
    texts[12] = init_travel_text(texts[12], "City", (sfVector2f){1500, 850});
    return texts;
}