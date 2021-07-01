/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-mydefender-tanguy.bellicha
** File description:
** show_tower
*/

#include "defender.h"
#include "my.h"

int place_tower_at_release(s_game *defender, s_tower_info *tower_info, \
int red_circle_tempo)
{
    if (defender->event.type == sfEvtMouseButtonReleased) {
        if (can_tower_be_placed(defender->map_path, \
            tower_info->object->sprite, defender->event.mouseButton))
            return (-1);
        else
            red_circle_tempo = 20;
        sfSprite_setPosition(tower_info->object->sprite, (sfVector2f)\
        {defender->event.mouseButton.x, defender->event.mouseButton.y});
        sfCircleShape_setPosition(tower_info->circle, (sfVector2f)\
        {defender->event.mouseButton.x + sfSprite_getGlobalBounds\
            (tower_info->object->sprite).width/2, \
            defender->event.mouseButton.y + \
            sfSprite_getGlobalBounds(tower_info->object->sprite).height/2});
    }
    return (red_circle_tempo);
}

void tower_follow_mouse(s_game *defender, s_tower_info *tower_info)
{
    sfSprite_setPosition(tower_info->object->sprite, (sfVector2f)\
    {defender->event.mouseMove.x, defender->event.mouseMove.y});
    sfCircleShape_setPosition(tower_info->circle, (sfVector2f)\
    {defender->event.mouseMove.x + sfSprite_getGlobalBounds\
        (tower_info->object->sprite).width/2, \
        defender->event.mouseMove.y + \
        sfSprite_getGlobalBounds(tower_info->object->sprite).height/2});
}

int display_red_circle_if_incorrect(sfClock *clock, int red_circle_tempo, \
s_tower_info *tower_info, s_game *defender)
{
    if (sfClock_getElapsedTime(clock).microseconds > 20000) {
        if (red_circle_tempo > 0) {
            sfCircleShape_setFillColor(tower_info->circle, \
            (sfColor){255, 0, 0, 120});
            red_circle_tempo--;
        } else
            sfCircleShape_setFillColor(tower_info->circle, \
            (sfColor){50, 50, 50, 120});
        update_window(defender, 0);
        sfClock_restart(clock);
    }
    return (red_circle_tempo);
}

void place_tower_and_buy_it(s_game *defender, s_tower_info *tower_info)
{
    sfCircleShape_setFillColor(tower_info->circle, (sfColor){50, 50, 50, 120});
    update_text(defender->play_infos->playing_game->texts[1], \
    -tower_info->price, 1, (sfVector2f){150 - ((my_strlen(my_itoa\
        (defender->play_infos->playing_game->texts[1]->value)) - 1) * 13), \
        sfText_getPosition\
        (defender->play_infos->playing_game->texts[1]->text).y});
    tower_info->draw_circle = 0;
    sfMusic_stop(defender->musics->buying_sound);
    sfMusic_play(defender->musics->buying_sound);
}

void show_tower_until_release(s_game *defender, s_tower_info *tower_info)
{
    sfClock *clock = sfClock_create();
    int red_circle_tempo = 0;

    while (1) {
        sfRenderWindow_pollEvent(defender->window, &defender->event);
        if ((red_circle_tempo = place_tower_at_release\
            (defender, tower_info, red_circle_tempo)) == -1)
            break;
        else if (defender->event.type == sfEvtMouseMoved)
            tower_follow_mouse(defender, tower_info);
        red_circle_tempo = display_red_circle_if_incorrect\
        (clock, red_circle_tempo, tower_info, defender);
    }
    place_tower_and_buy_it(defender, tower_info);
    sfClock_destroy(clock);
}