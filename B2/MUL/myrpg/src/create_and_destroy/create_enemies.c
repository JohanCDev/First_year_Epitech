/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-johan.chrillesen
** File description:
** create_enemies
*/

#include "rpg.h"

void initialize_final_enemies(game_t *rpg)
{
    create_enemy(rpg, create_object("./resources/game/goblin.png", \
    (sfVector2f){-515, 550}, (sfIntRect){0, 0, 33, 37}, \
    (sfVector2f){0.75, 0.75}), (sfVector2f){50, 25});
    create_enemy(rpg, create_object("./resources/game/goblin.png", \
    (sfVector2f){-190, -660}, (sfIntRect){0, 0, 33, 37}, \
    (sfVector2f){0.75, 0.75}), (sfVector2f){50, 25});
    create_enemy(rpg, create_object("./resources/game/goblin.png", \
    (sfVector2f){-675, -305}, (sfIntRect){0, 0, 33, 37}, \
    (sfVector2f){0.75, 0.75}), (sfVector2f){50, 25});
    create_enemy(rpg, create_object("./resources/game/Boss.png", \
    (sfVector2f){-1450, -15}, (sfIntRect){0, 0, 26, 38}, \
    (sfVector2f){1.5, 1.5}), (sfVector2f){300, 80});
}

void initialize_next_enemies(game_t *rpg)
{
    create_enemy(rpg, create_object("./resources/game/goblin.png", \
    (sfVector2f){-1265, -670}, (sfIntRect){0, 0, 33, 37}, \
    (sfVector2f){0.75, 0.75}), (sfVector2f){50, 25});
    create_enemy(rpg, create_object("./resources/game/goblin.png", \
    (sfVector2f){-1090, -20}, (sfIntRect){0, 0, 33, 37}, \
    (sfVector2f){0.75, 0.75}), (sfVector2f){50, 25});
    create_enemy(rpg, create_object("./resources/game/goblin.png", \
    (sfVector2f){-1090, 25}, (sfIntRect){0, 0, 33, 37}, \
    (sfVector2f){0.75, 0.75}), (sfVector2f){50, 25});
    create_enemy(rpg, create_object("./resources/game/goblin.png", \
    (sfVector2f){-755, 220}, (sfIntRect){0, 0, 33, 37}, \
    (sfVector2f){0.75, 0.75}), (sfVector2f){50, 25});
    create_enemy(rpg, create_object("./resources/game/goblin.png", \
    (sfVector2f){-870, -510}, (sfIntRect){0, 0, 33, 37}, \
    (sfVector2f){0.75, 0.75}), (sfVector2f){50, 25});
    create_enemy(rpg, create_object("./resources/game/goblin.png", \
    (sfVector2f){-1095, 830}, (sfIntRect){0, 0, 33, 37}, \
    (sfVector2f){0.75, 0.75}), (sfVector2f){50, 25});
    initialize_final_enemies(rpg);
}

void initialize_enemies(game_t *rpg)
{
    init_enemies_list(rpg->play_infos->enemies);
    create_enemy(rpg, create_object("./resources/game/goblin.png", \
    (sfVector2f){150, 185}, (sfIntRect){0, 0, 33, 37}, \
    (sfVector2f){0.75, 0.75}), (sfVector2f){50, 25});
    create_enemy(rpg, create_object("./resources/game/goblin.png", \
    (sfVector2f){900, 625}, (sfIntRect){0, 0, 33, 37}, \
    (sfVector2f){0.75, 0.75}), (sfVector2f){50, 25});
    create_enemy(rpg, create_object("./resources/game/goblin.png", \
    (sfVector2f){755, 455}, (sfIntRect){0, 0, 33, 37}, \
    (sfVector2f){0.75, 0.75}), (sfVector2f){50, 25});
    create_enemy(rpg, create_object("./resources/game/goblin.png", \
    (sfVector2f){805, 240}, (sfIntRect){0, 0, 33, 37}, \
    (sfVector2f){0.75, 0.75}), (sfVector2f){50, 25});
    create_enemy(rpg, create_object("./resources/game/goblin.png", \
    (sfVector2f){1050, -915}, (sfIntRect){0, 0, 33, 37}, \
    (sfVector2f){0.75, 0.75}), (sfVector2f){50, 25});
    create_enemy(rpg, create_object("./resources/game/goblin.png", \
    (sfVector2f){705, -730}, (sfIntRect){0, 0, 33, 37}, \
    (sfVector2f){0.75, 0.75}), (sfVector2f){50, 25});
    initialize_next_enemies(rpg);
}