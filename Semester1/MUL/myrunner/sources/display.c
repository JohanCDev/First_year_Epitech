/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myrunner-johan.chrillesen
** File description:
** display
*/

#include "runner.h"
#include "my.h"

void detect_obstacles(game_s *game, linked_list_s *list)
{
    sfFloatRect player_rect = sfSprite_getGlobalBounds(game->player->sprite);
    sfFloatRect enemy_rect = sfSprite_getGlobalBounds(list->enemy->sprite);

    if (sfFloatRect_intersects(&player_rect, &enemy_rect, NULL)) {
        game->win = 0;
        finish_game(game);
    }
}

void display_obstacles(game_s *game)
{
    linked_list_s *current = game->enemy;

    while (current != NULL) {
        if (current->enemy->rect.width > 80)
            sfSprite_move(current->enemy->sprite, change_position(-35, 0));
        else
            sfSprite_move(current->enemy->sprite, change_position(-25, 0));
        detect_obstacles(game, current);
        current = current->next;
    }
}

void do_parallax(game_s *game)
{
    move_rect(&game->big_bg->rect, 4, 2048);
    sfSprite_setTextureRect(game->big_bg->sprite, game->big_bg->rect);
    move_rect(&game->mid_bg->rect, 8, 2048);
    sfSprite_setTextureRect(game->mid_bg->sprite, game->mid_bg->rect);
    move_rect(&game->front_bg->rect, 16, 2048);
    sfSprite_setTextureRect(game->front_bg->sprite, game->front_bg->rect);
    move_rect(&game->ground->rect, 25, 2395);
    sfSprite_setTextureRect(game->ground->sprite, game->ground->rect);
    print_obstacle(game);
    display_obstacles(game);
}

sfText *set_score(game_s *game)
{
    sfVector2f pos_text = {200, 0};
    sfText *score = NULL;
    int length = 0;

    create_score_label("resources/text/CartooNature.ttf", game);
    score = sfText_create();
    sfText_setFont(score, sfFont_createFromFile\
    ("resources/text/CartooNature.ttf"));
    sfText_setCharacterSize(score, 60);
    sfText_setString(game->score.text, my_itoa(game->score.score));
    sfText_setString(score, "Score :");
    length = my_strlen(my_itoa(game->score.score));
    pos_text.x += length - 1 * 6;
    sfText_setPosition(game->score.text, pos_text);
    return (score);
}

void display_all(game_s *game)
{
    sfRenderWindow_clear(game->window.window, sfTransparent);
    do_parallax(game);
    sfRenderWindow_drawSprite(game->window.window, \
    game->big_bg->sprite, NULL);
    sfRenderWindow_drawSprite(game->window.window, \
    game->mid_bg->sprite, NULL);
    sfRenderWindow_drawSprite(game->window.window, game->front_bg->sprite, \
    NULL);
    sfRenderWindow_drawSprite(game->window.window, game->ground->sprite, \
    NULL);
    sfRenderWindow_drawSprite(game->window.window, \
    game->player->sprite, NULL);
    print_obstacle(game);
    sfRenderWindow_drawText(game->window.window, set_score(game), NULL);
    sfRenderWindow_drawText(game->window.window, game->score.text, NULL);
    sfRenderWindow_display(game->window.window);
}
