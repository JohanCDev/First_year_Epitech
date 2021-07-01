/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share
** File description:
** initailize_texts
*/

#include "my.h"
#include "defender.h"

void initialize_playing_game_texts_next(s_text **texts)
{
    texts[4] = init_text("./resources/font.ttf", (sfVector2f) {1900, 274}, \
    100, 32);
    update_text(texts[4], 100, 0, (sfVector2f){1900, 274});
    texts[5] = init_text("./resources/font.ttf", (sfVector2f) {1952, 274}, \
    140, 32);
    update_text(texts[5], 140, 0, (sfVector2f){1952, 274});
    texts[6] = init_text("./resources/font.ttf", (sfVector2f) {792, 20}, \
    8, 48);
    update_text(texts[6], texts[6]->value, 0, (sfVector2f){792, 20});
    texts[7] = NULL;
}

void initialize_playing_game_texts(s_text **texts)
{
    texts[0] = init_text("./resources/font.ttf", (sfVector2f) {152, 24}, \
    150, 32);
    update_text(texts[0], 50, 0, (sfVector2f){150 - ((my_strlen\
        (my_itoa(texts[0]->value)) - 1) * 13), \
        sfText_getPosition(texts[0]->text).y});
    texts[1] = init_text("./resources/font.ttf", (sfVector2f) {152, 64}, \
    100, 32);
    update_text(texts[1], 150, 0, (sfVector2f){150 - ((my_strlen\
        (my_itoa(texts[1]->value)) - 1) * 13), \
        sfText_getPosition(texts[1]->text).y});
    texts[2] = init_text("./resources/font.ttf", (sfVector2f) {1900, 64}, \
    60, 32);
    texts[3] = init_text("./resources/font.ttf", (sfVector2f) {1900, 64}, \
    40, 32);
    update_text(texts[3], 40, 0, (sfVector2f){1952, 166});
    initialize_playing_game_texts_next(texts);
}