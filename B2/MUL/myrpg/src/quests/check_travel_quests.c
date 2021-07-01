/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** check_travel_quests
*/

#include "rpg.h"

void destroy_utils_quests(text_t *new_region, text_t *all_region, \
sfClock *clock)
{
    sfFont_destroy(new_region->font);
    sfFont_destroy(all_region->font);
    sfText_destroy(new_region->text);
    sfText_destroy(all_region->text);
    free(all_region);
    free(new_region);
    sfClock_destroy(clock);
}

void check_regions_one_by_one(sfVector2f view, game_t *rpg, \
sfClock *clock, text_t *new_region)
{
    if (check_region(view, rpg->quests->travel) == true) {
        while (sfClock_getElapsedTime(clock).microseconds < 500000) {
            sfRenderWindow_drawText(rpg->window, new_region->text, NULL);
            sfRenderWindow_display(rpg->window);
        }
    }
}

void check_all_is_done(game_t *rpg, move_quest_t *travel, text_t *all_region, \
sfClock *clock)
{
    if (travel->castle == true && travel->cave == true && travel->city == true \
    && travel->farm == true && travel->forest == true && \
    travel->graveyard == true && travel->hell == true && \
    travel->lake == true && travel->done == false) {
        while (sfClock_getElapsedTime(clock).microseconds < 2000000) {
            sfRenderWindow_drawText(rpg->window, all_region->text, NULL);
            sfRenderWindow_display(rpg->window);
        }
        travel->done = true;
    }
}

move_quest_t *check_travel_quest(game_t *rpg, move_quest_t *travel)
{
    sfVector2f view = sfView_getCenter(rpg->play_infos->map_view);
    text_t *new_region = init_text_str("./resources/font2.ttf", \
    (sfVector2f){view.x - view.x / 16, view.y}, "New region discovered", 25);
    text_t *all_region = init_text_str("./resources/font2.ttf", \
    (sfVector2f){view.x - view.x / 16, view.y}, "All regions discovered", 25);
    sfClock *clock = sfClock_create();

    check_regions_one_by_one(view, rpg, clock, new_region);
    sfClock_restart(clock);
    sfRenderWindow_clear(rpg->window, sfTransparent);
    sfRenderWindow_drawSprite(rpg->window, \
    rpg->play_infos->playing_game->background->sprite, NULL);
    sfRenderWindow_drawSprite(rpg->window, \
    rpg->play_infos->player->sprite, NULL);
    check_all_is_done(rpg, travel, all_region, clock);
    destroy_utils_quests(new_region, all_region, clock);
    return (travel);
}