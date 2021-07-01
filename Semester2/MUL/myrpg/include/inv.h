/*
** EPITECH PROJECT, 2021
** rpg_functions
** File description:
** include
*/

#ifndef INCLUDE_H_
#define INCLUDE_H_

#include "rpg.h"
#include "struct.h"
#include <SFML/Window/Event.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>
#include <stdio.h>

#define INV_FULL 12
#define NO_ITEM -1
#define EMPTY_STR "Vide"
#define GOBLIN_STR "./resources/goblin_head.png"
#define GOBLIN_TYPE 2
#define BONE_STR "./resources/Bone.png"
#define BONE_TYPE 3
#define SWORD_STR "./resources/sword.png"
#define SWORD_TYPE 4
#define SHIELD_STR "./resources/shield.png"
#define SHIELD_TYPE 5
#define FLESH_STR "./resources/rotten_flesh.png"
#define FLESH_TYPE 6
#define MAX_ITEM 1

typedef struct inv_s {
    sfRectangleShape *item;
    sfTexture *texture;
    int actual_nbr;
    int max;
    sfText *nb_item;
    int item_type;
    bool is_empty;
}inv_t;

bool is_inventory_full(inv_t **inv);
int next_item(inv_t **inv, int next);
void display_inv(inv_t **inv, sfRenderWindow *window);
inv_t **add_item(inv_t **inv, char *filepath, int item_type, int slot);
inv_t *empty_inv_slot(inv_t *inv, char *filepath);
inv_t **init_empty_inventory(inv_t **inv, char *filepath, int test);
inv_t **init_inventory(inv_t** inv);

#endif /* !INCLUDE_H_ */
