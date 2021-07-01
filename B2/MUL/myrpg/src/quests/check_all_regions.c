/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-johan.chrillesen
** File description:
** check_all_regions
*/

#include "rpg.h"

bool check_final_regions(sfVector2f view, move_quest_t *travel)
{
    sfFloatRect city = {-135, -130, 265, 300};

    if (sfFloatRect_contains(&city, view.x, view.y) && travel->city == false) {
        travel->city = true;
        return (true);
    } else
        return (false);
}

bool check_regions_four(sfVector2f view, move_quest_t *travel)
{
    sfFloatRect cave = {30, -985, 25, 95};
    sfFloatRect castle = {760, -990, 585, 80};

    if (sfFloatRect_contains(&cave, view.x, view.y) && travel->cave == false) {
        travel->cave = true;
        return (true);
    } else if (sfFloatRect_contains(&castle, view.x, view.y) && \
    travel->castle == false) {
        travel->castle = true;
        return (true);
    } else
        return (check_final_regions(view, travel));
}

bool check_regions_three(sfVector2f view, move_quest_t *travel)
{
    sfFloatRect lake = {-690, 755, 1100, 185};
    sfFloatRect grave = {825, 545, 175, 265};

    if (sfFloatRect_contains(&lake, view.x, view.y) && travel->lake == false) {
        travel->lake = true;
        return (true);
    } else if (sfFloatRect_contains(&grave, view.x, view.y) && \
    travel->graveyard == false) {
        travel->graveyard = true;
        return (true);
    } else
        return (check_regions_four(view, travel));
}

bool check_regions_two(sfVector2f view, move_quest_t *travel)
{
    sfFloatRect farm = {-815, -400, 275, 115};
    sfFloatRect forest = {870, -445, 675, 670};

    if (sfFloatRect_contains(&farm, view.x, view.y) && travel->farm == false) {
        travel->farm = true;
        return (true);
    } else if (sfFloatRect_contains(&forest, view.x, view.y) && \
    travel->forest == false) {
        travel->forest = true;
        return (true);
    } else
        return (check_regions_three(view, travel));
}

bool check_region(sfVector2f view, move_quest_t *travel)
{
    sfFloatRect snow = {-1760, -995, 880, 330};
    sfFloatRect hell = {-1690, -175, 275, 320};

    if (sfFloatRect_contains(&snow, view.x, view.y) && travel->snow == false) {
        travel->snow = true;
        return (true);
    } else if (sfFloatRect_contains(&hell, view.x, view.y) && \
    travel->hell == false) {
        travel->hell = true;
        return (true);
    } else
        return (check_regions_two(view, travel));
}