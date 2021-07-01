/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myhunter-johan.chrillesen
** File description:
** close_window
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}