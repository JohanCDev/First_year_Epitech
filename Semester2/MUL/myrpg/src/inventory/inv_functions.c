/*
** EPITECH PROJECT, 2021
** rpg_functions
** File description:
** house
*/

#include "rpg.h"

bool all_type_of_item(inv_t **inv)
{
    bool head = false;
    bool bone = false;
    bool flesh = false;

    for (int i = 0; i < INV_FULL; i++) {
        if (inv[i]->item_type == BONE_TYPE)
            bone = true;
        if (inv[i]->item_type == FLESH_TYPE)
            flesh = true;
        if (inv[i]->item_type == GOBLIN_TYPE)
            head = true;
    }
    if (head == true && bone == true && flesh == true)
        return true;
    return false;
}

inv_t **init_empty_inventory(inv_t **inv, char *filepath, int test)
{
    sfVector2f pos = {760, 240};
    sfVector2u size = {0, 0};
    int i = 0;

    if (test == 2)
        i+= 12;
    while (i < (12 * test)) {
        if (i % 4 == 0) {
            pos.x = 760;
            pos.y += 100;
        }
        sfRectangleShape_setPosition(inv[i]->item, pos);
        inv[i]->texture = sfTexture_createFromFile(filepath, NULL);
        sfRectangleShape_setTexture(inv[i]->item, inv[i]->texture, sfTrue);
        size = sfTexture_getSize(inv[i]->texture);
        sfRectangleShape_setSize(inv[i]->item, (sfVector2f){size.x, size.y});
        pos.x += 100;
        i++;
    }
    return inv;
}

inv_t **init_inventory(inv_t** inv)
{
    inv = malloc(sizeof(inv_t) * (24));
    if (!inv)
        return NULL;
    for (int i = 0; i < 24; i++) {
        inv[i] = malloc(sizeof(inv_t));
        if (!inv[i])
            return NULL;
        inv[i]->is_empty = true;
        inv[i]->actual_nbr = 0;
        inv[i]->max = MAX_ITEM;
        inv[i]->nb_item = sfText_create();
        inv[i]->item = sfRectangleShape_create();
    }
    inv = init_empty_inventory(inv, "./resources/inv.png", 1);
    inv = init_empty_inventory(inv, "./resources/inv.png", 2);
    inv = add_item(inv, SWORD_STR, SWORD_TYPE, 0);
    inv = add_item(inv, SHIELD_STR, SHIELD_TYPE, 1);
    return inv;
}

void detect_inv(game_t *rpg)
{
    if (rpg->current_scene != rpg->inventory) {
        rpg->current_scene = rpg->inventory;
    } else {
        rpg->current_scene = rpg->play_infos->playing_game;
    }
}

scene_t *init_scene_inventory(void)
{
    scene_t *inv = malloc(sizeof(scene_t));

    inv->objs = malloc(sizeof(game_object_t));
    inv->buttons = malloc(sizeof(button_t));
    inv->objs[0] = NULL;
    inv->buttons[0] = NULL;
    inv = init_inv_texts(inv);
    inv->background = malloc(sizeof(game_object_t));
    inv->background->texture = \
    sfTexture_createFromFile("./resources/inv_bg.png", NULL);
    inv->background->sprite = sfSprite_create();
    sfSprite_setTexture(inv->background->sprite, \
    inv->background->texture, sfTrue);
    inv->background->position.x = 0;
    inv->background->position.y = 0;
    sfSprite_setPosition(inv->background->sprite, inv->background->position);
    return inv;
}