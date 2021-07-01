/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** initialize_quest
*/

#include "rpg.h"

move_quest_t *init_travel_quest(move_quest_t *travel)
{
    travel->snow = false;
    travel->hell = false;
    travel->farm = false;
    travel->forest = false;
    travel->lake = false;
    travel->graveyard = false;
    travel->cave = false;
    travel->castle = false;
    travel->city = false;
    travel->done = false;
    return travel;
}

quest_log_t *init_quests(quest_log_t *quests)
{
    quests = malloc(sizeof(quest_log_t));
    quests->travel = malloc(sizeof(move_quest_t));
    quests->travel = init_travel_quest(quests->travel);
    return quests;
}