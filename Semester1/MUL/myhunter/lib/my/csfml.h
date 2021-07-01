/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myhunter-johan.chrillesen
** File description:
** CSFML
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>

#pragma once

#ifndef CSFML_H
#define CSFML_H

typedef struct {
    sfTexture* texture;
    sfIntRect rect;
    sfSprite* sprite;
    sfVector2f size;
}object;

typedef struct {
    sfTexture* texture;
    sfSprite* sprite;
    sfVector2f size;
    sfRenderWindow* window;
    sfVideoMode mode;
    sfEvent event;
}win;

typedef struct {
    int score;
    int lifes;
}game;

void manage_mouse_click(win window, object bird);
void close_window(sfRenderWindow *window);
void analyse_event(win window, object bird);
void display_window(win window, object bird);
void move_rect(sfIntRect *rect, int offset, int max_value);
void check_resize(sfRenderWindow *window, sfEvent event);
int look_params(int argc, char **argv);
sfVector2f change_position(float pos_x, float pos_y);
object create_sprite(object bird);

#endif