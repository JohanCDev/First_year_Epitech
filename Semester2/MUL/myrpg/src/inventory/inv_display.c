/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** inv_display
*/

#include "rpg.h"

text_t *valid_full_inv(text_t *text)
{
    sfText_setString(text->text, "Complete : Get Full Inventory\n");
    sfText_setColor(text->text, sfGreen);
    sfText_setPosition(text->text, (sfVector2f){595, 760});
    return text;
}

text_t *valid_all_item(text_t *text)
{
    sfText_setString(text->text, "Complete : Get All items (3 in total)\n");
    sfText_setColor(text->text, sfGreen);
    sfText_setPosition(text->text, (sfVector2f){545, 860});
    return text;
}

void valid_travel_quests(move_quest_t *travel, text_t **texts)
{
    if (travel->snow)
        sfText_setColor(texts[4]->text, sfGreen);
    if (travel->hell)
        sfText_setColor(texts[5]->text, sfGreen);
    if (travel->farm)
        sfText_setColor(texts[6]->text, sfGreen);
    if (travel->forest)
        sfText_setColor(texts[7]->text, sfGreen);
    if (travel->lake)
        sfText_setColor(texts[8]->text, sfGreen);
    if (travel->graveyard)
        sfText_setColor(texts[9]->text, sfGreen);
    if (travel->cave)
        sfText_setColor(texts[10]->text, sfGreen);
    if (travel->castle)
        sfText_setColor(texts[11]->text, sfGreen);
    if (travel->city)
        sfText_setColor(texts[12]->text, sfGreen);
}

void heart_change(game_object_t *heart, sfMouseButtonEvent mousePosition, \
game_t *rpg)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(heart->sprite);
    sfVector2u size = sfTexture_getSize(heart->texture);

    if (sfFloatRect_contains(&rect, mousePosition.x, mousePosition.y) && \
    rpg->event.type == sfEvtMouseButtonReleased) {
        if (sfClock_getElapsedTime(rpg->play_infos->player->clock)\
        .microseconds > 1000000) {
            move_rect(&heart->rect, size.x / 9, (size.x / 9) * 9);
            sfSprite_setTextureRect(heart->sprite, heart->rect);
            sfClock_restart(rpg->play_infos->player->clock);
        }
    }
}

void display_inventory(game_t *rpg, inv_t **inv, sfRenderWindow *win)
{
    for (int i = 12; i < INV_FULL * 2; i++)
        sfRenderWindow_drawRectangleShape(win, inv[i]->item, NULL);
    for (int i = 0; i < INV_FULL; i++)
        sfRenderWindow_drawRectangleShape(win, inv[i]->item, NULL);
    rpg->inventory->texts[1]->value = rpg->play_infos->player->life;
    sfText_setString(rpg->inventory->texts[1]->text, \
    my_itoa(rpg->play_infos->player->life));
    if (is_inventory_full(inv) == true)
        rpg->inventory->texts[2] = valid_full_inv(rpg->inventory->texts[2]);
    if (all_type_of_item(inv) == true)
        rpg->inventory->texts[3] = valid_all_item(rpg->inventory->texts[3]);
    valid_travel_quests(rpg->quests->travel, rpg->inventory->texts);
    for (int m = 0; m < 13; m++) {
        sfRenderWindow_drawText(win, \
        rpg->inventory->texts[m]->text, NULL);
    }
    sfRenderWindow_pollEvent(rpg->window, &rpg->event);
    heart_change(rpg->play_infos->player->heart, rpg->event.mouseButton, rpg);
    sfRenderWindow_drawSprite(win, \
    rpg->play_infos->player->heart->sprite, NULL);
}