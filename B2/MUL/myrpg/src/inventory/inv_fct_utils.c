/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** inv_fct_utils
*/

#include "rpg.h"

inv_t *empty_inv_slot(inv_t *inv, char *filepath)
{
    inv->actual_nbr = 0;
    inv->item_type = NO_ITEM;
    sfTexture_destroy(inv->texture);
    inv->texture = sfTexture_createFromFile(filepath, NULL);
    sfRectangleShape_setTexture(inv->item, inv->texture, sfTrue);
    inv->is_empty = true;
    return inv;
}

inv_t **add_item(inv_t **inv, char *filepath, int item_type, int slot)
{
    sfVector2u size = {0, 0};
    if (inv[slot]->is_empty == true) {
        inv[slot]->is_empty = false;
        sfTexture_destroy(inv[slot]->texture);
        inv[slot]->texture = \
        sfTexture_createFromFile(filepath, NULL);
        size = sfTexture_getSize(inv[slot]->texture);
        sfRectangleShape_setSize(inv[slot]->item, (sfVector2f){size.x, size.y});
        sfRectangleShape_setTexture(inv[slot]->item, \
        inv[slot]->texture, sfTrue);
        inv[slot]->actual_nbr = 1;
        inv[slot]->item_type = item_type;
    }
    return inv;
}

bool is_inventory_full(inv_t **inv)
{
    for (int i = 0; i < 12; i++) {
        if (inv[i]->is_empty == true){
            return false;
        }
    }
    return true;
}

int next_item(inv_t **inv, int next)
{
    while (inv[next] && inv[next]->is_empty == false && next < INV_FULL)
        next++;
    return next;
}

void loot(inv_t **inv, int value)
{
    int slot = next_item(inv, 0);

    if (is_inventory_full(inv) == true)
        return;
    switch (value) {
    case 0 :
        break;
    case 1 :
        inv = add_item(inv, BONE_STR, BONE_TYPE, slot);
        break;
    case 2 :
        inv = add_item(inv, GOBLIN_STR, GOBLIN_TYPE, slot);
        break;
    case 3 :
        inv = add_item(inv, FLESH_STR, FLESH_TYPE, slot);
        break;
    }
}