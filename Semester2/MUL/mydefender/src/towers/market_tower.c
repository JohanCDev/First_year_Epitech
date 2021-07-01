/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-tanguy.bellicha
** File description:
** market_tower
*/

#include "my.h"
#include "defender.h"

void market_object_is_clicked(s_game *defender, s_game_object *object, \
sfMouseButtonEvent mousePosition)
{
    sfFloatRect object_rect = sfSprite_getGlobalBounds(object->sprite);
    s_text *text = defender->play_infos->playing_game->texts[1];

    if (sfFloatRect_contains(&object_rect, mousePosition.x, mousePosition.y)) {
        if (sfSprite_getPosition(object->sprite).y < 400)
            detect_first_line_market(defender, object);
        else
            detect_second_line_market(defender, object);
        update_text(text, text->value, 0, (sfVector2f){150 - ((my_strlen\
            (my_itoa(text->value)) - 1) * 13), \
            sfText_getPosition(text->text).y});
        sfMusic_play(defender->musics->button_sound);
    }
}

void show_market(s_game *defender)
{
    s_scene *scene = defender->play_infos->playing_game;
    s_towers *current = defender->play_infos->towers;
    int i = 1;

    if (!defender->play_infos->show_menu) {
        while (scene->objs[++i])
            sfSprite_move(scene->objs[i]->sprite, (sfVector2f){-582, 0});
        update_text(scene->texts[2], 40, 0, (sfVector2f){1704 - 581, 150});
        update_text(scene->texts[3], 60, 0, (sfVector2f){1904 - 581, 150});
        update_text(scene->texts[4], 100, 0, (sfVector2f){1704 - 581, 360});
        update_text(scene->texts[5], 140, 0, (sfVector2f){1904 - 581, 360});
        sfRectangleShape_move(scene->buttons[0]->rect, (sfVector2f){-582, 0});
        defender->play_infos->show_menu = true;
        while (current != NULL) {
            current->tower_info->draw_circle = 0;
            current = current->next;
        }
    }
}

void hide_market(s_game *defender)
{
    s_scene *scene = defender->play_infos->playing_game;
    int i = 1;

    if (defender->play_infos->show_menu) {
        while (scene->objs[++i])
            sfSprite_move(scene->objs[i]->sprite, (sfVector2f){582, 0});
        update_text(scene->texts[2], 60, 0, (sfVector2f){1754, 150});
        update_text(scene->texts[3], 40, 0, (sfVector2f){1954, 150});
        update_text(scene->texts[4], 100, 0, (sfVector2f){1754, 360});
        update_text(scene->texts[5], 140, 0, (sfVector2f){1754, 360});
        sfRectangleShape_move(scene->buttons[0]->rect, (sfVector2f){582, 0});
        defender->play_infos->show_menu = false;
    }
}

void use_box(s_game *defender)
{
    if (defender->current_scene == defender->play_infos->playing_game) {
        if (!defender->play_infos->show_menu)
            show_market(defender);
        else
            hide_market(defender);
        update_window(defender, 1);
    }
}