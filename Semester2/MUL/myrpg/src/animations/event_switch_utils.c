/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** event_switch_utils
*/

#include "rpg.h"

float check_pixel_for_hitbox(sfVector2f current, sfImage *hitboxes, \
float final_x)
{
    while (current.x <= final_x) {
        if (current.x < 0 || current.y < 0 || current.x >
            sfImage_getSize(hitboxes).x || current.y > \
            sfImage_getSize(hitboxes).y)
            return (-1);
        if (sfImage_getPixel(hitboxes, current.x, current.y).a == 255)
            return (-1);
        current.x += 1;
    }
    return (current.x);
}

bool check_if_can_move(sfView *view, sfImage *hitboxes, \
sfVector2f move, game_t *rpg)
{
    float cur_x = (int) sfView_getCenter(view).x + 3453/2 + move.x + \
    (sfSprite_getGlobalBounds(rpg->play_infos->player->sprite).width / 5);
    float cur_y = ((int) sfView_getCenter(view).y + 1951/2 + move.y) + \
    (sfSprite_getGlobalBounds(rpg->play_infos->player->sprite).height / 7 * 4);
    float final_x = (int) sfView_getCenter(view).x + 3453/2 + move.x +  \
    sfSprite_getTextureRect(rpg->play_infos->player->sprite).width / 5 * 4;
    float final_y = (int) sfView_getCenter(view).y + 1951/2 + move.y +  \
    sfSprite_getGlobalBounds(rpg->play_infos->player->sprite).height;

    while (cur_y <= final_y) {
        cur_x = check_pixel_for_hitbox((sfVector2f){cur_x, cur_y}, hitboxes, \
        final_x);
        if (cur_x == -1)
            return (0);
        cur_x = (int) sfView_getCenter(view).x + 3453/2 + move.x;
        cur_y += 1;
    }
    return (1);
}

void detect_fighting(game_t *rpg)
{
    sfFloatRect player_rect = sfSprite_getGlobalBounds\
    (rpg->play_infos->player->sprite);
    sfFloatRect enemy_rect = (sfFloatRect) {0, 0, 0, 0};
    enemies_t *current = rpg->play_infos->enemies;

    while (current != NULL) {
        player_rect = sfSprite_getGlobalBounds\
        (rpg->play_infos->player->sprite);
        enemy_rect = sfSprite_getGlobalBounds\
        (current->enemie_info->mob->sprite);
        if (sfFloatRect_intersects(&player_rect, &enemy_rect, NULL) == sfTrue \
        && current->enemie_info->life > 0) {
            fight_scene(rpg, current->enemie_info);
            sfRenderWindow_setView(rpg->window, rpg->play_infos->default_view);
            break;
        }
        current = current->next;
    }
}

void mouse_moved_in_menu(game_t *rpg, scene_t *scene)
{
    for (int i = 0; scene->buttons[i]; i++) {
        button_is_hover(scene->buttons[i], rpg->event.mouseMove);
    }
}
