/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share
** File description:
** events
*/

#include "defender.h"
#include "my.h"

void analyse_key_events(s_game *defender)
{
    switch (defender->event.key.code) {
    case sfKeyEscape :
        escape_is_pressed(defender);
        break;
    case sfKeyLeft :
        use_box(defender);
        break;
    case sfKeyRight :
        use_box(defender);
        break;
    default :
        break;
    }
}

void analyse_events(s_game *defender)
{
    switch (defender->event.type) {
    case sfEvtClosed :
        defender->ret = 1;
        break;
    case sfEvtMouseButtonPressed :
        mouse_button_is_pressed(defender);
        break;
    case sfEvtKeyPressed :
        analyse_key_events(defender);
        break;
    case sfEvtMouseMoved :
        mouse_is_moved(defender);
        break;
    default :
        break;
    }
}

void mouse_button_is_pressed(s_game *defender)
{
    for (int i = 0; defender->current_scene->buttons[i]; i++)
        button_is_clicked(defender, defender->current_scene->buttons[i], \
        defender->event.mouseButton);
    for (int k = 0; defender->play_infos->show_menu && \
        defender->play_infos->market_list[k]; k++)
        market_object_is_clicked(defender, \
        defender->play_infos->market_list[k], defender->event.mouseButton);
}

void mouse_moved_in_menu(s_game *defender, s_scene *scene)
{
    for (int i = 0; scene->buttons[i]; i++)
        button_is_hover(scene->buttons[i], defender->event.mouseMove);
}

