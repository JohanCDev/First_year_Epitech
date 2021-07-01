/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myhunter-johan.chrillesen
** File description:
** create_sprite
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "csfml.h"

object create_sprite(object bird)
{
    bird.rect.left = 0;
    bird.rect.top = 34;
    bird.rect.width = 39;
    bird.rect.height = 34;
    int x = rand() % 1000 + 100;
    sfVector2f position_beginning = {x, 520};

    sfSprite_setTexture(bird.sprite, bird.texture, sfTrue);
    sfSprite_setTextureRect(bird.sprite, bird.rect);
    sfSprite_setPosition(bird.sprite, position_beginning);
    return (bird);
}

//RECT = {x, y, width, heigth}