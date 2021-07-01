/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-johan.chrillesen
** File description:
** reinitialize_quests
*/

#include "rpg.h"

void reset_exploration(move_quest_t *travel)
{
    travel->castle = false;
    travel->cave = false;
    travel->city = false;
    travel->done = false;
    travel->farm = false;
    travel->forest = false;
    travel->graveyard = false;
    travel->hell = false;
    travel->lake = false;
    travel->snow = false;
}

void reset_ress_quest(scene_t *inv)
{
    sfText_setString(inv->texts[3]->text, \
    "Incomplete : Get All items (3 in total)\n");
    sfText_setColor(inv->texts[3]->text, sfRed);
    sfText_setPosition(inv->texts[3]->text, (sfVector2f){550, 860});
    sfText_setString(inv->texts[2]->text, "Incomplete : Get Full Inventory\n");
    sfText_setColor(inv->texts[2]->text, sfRed);
    sfText_setPosition(inv->texts[2]->text, (sfVector2f){660, 760});
}

void reset_travel_text_quest(text_t **texts)
{
    for (int i = 4; i < 13; i++) {
        sfText_setColor(texts[i]->text, sfRed);
    }
}

void reset_quests(quest_log_t *quests, game_t *rpg)
{
    reset_exploration(quests->travel);
    reset_ress_quest(rpg->inventory);
    reset_travel_text_quest(rpg->inventory->texts);
}