/*
** EPITECH PROJECT, 2021
** B-MUL-100-NAN-1-1-myrunner-johan.chrillesen
** File description:
** finish_game
*/

#include "runner.h"
#include "my.h"

void setup_final_text(game_s *game)
{
    sfVector2f pos_text = {game->window.mode.width / 2 - 65, \
    game->window.mode.height / 2 + 20};
    sfVector2f pos_final_score = {game->window.mode.width / 2 - 225, \
    game->window.mode.height / 2 - 65};

    sfText_setCharacterSize(game->score.text, 80);
    pos_text.x -= my_strlen(my_itoa(game->score.score)) - 1 * 10;
    sfText_setPosition(game->score.text, pos_text);
    sfText_setColor(game->score.text, sfBlack);
    game->your_score = sfText_create();
    sfText_setFont(game->your_score, sfFont_createFromFile\
    ("resources/text/CartooNature.ttf"));
    sfText_setCharacterSize(game->your_score, 80);
    sfText_setColor(game->your_score, sfBlack);
    sfText_setPosition(game->your_score, pos_final_score);
    sfText_setString(game->your_score, "Final score :");
    sfRenderWindow_drawText(game->window.window, game->score.text, NULL);
    sfRenderWindow_drawText(game->window.window, game->your_score, NULL);
}

void initialize_dino(object_s *dino, sfVector2f pos_dino)
{
    sfSprite_setScale(dino->sprite, create_vector(4, 4));
    sfSprite_setTextureRect(dino->sprite, dino->rect);
    sfSprite_setPosition(dino->sprite, pos_dino);
}

void display_everything(game_s *game)
{
    sfVector2f size = {1, 1};
    sfVector2f pos_dino = {800, 40};
    game->background_over = create_object\
    ("resources/images/backgrounds/endscreen.png", create_vector(0, 0), \
    create_rect(0, 0, 1920, 1080), size);

    sfSprite_setTextureRect(game->background_over->sprite, \
    create_rect(0, 0, 1920, 1080));
    sfRenderWindow_drawSprite(game->window.window, \
    game->background_over->sprite, NULL);
    if (game->win != 1) {
        game->player->rect.left = 240;
        initialize_dino(game->player, pos_dino);
        sfRenderWindow_drawSprite(game->window.window, \
        game->player->sprite, NULL);
    } else {
        initialize_dino(game->player_win, pos_dino);
        sfRenderWindow_drawSprite(game->window.window, \
        game->player_win->sprite, NULL);
    }
}

void display_end_screen(game_s *game)
{
    sfRenderWindow_clear(game->window.window, sfTransparent);
    display_everything(game);
    setup_final_text(game);
    sfRenderWindow_display(game->window.window);
}

void finish_game(game_s *game)
{
    sfMusic_pause(game->music);
    if (game->win == 1) {
        sfMusic_play(game->win_music);
    } else
        sfMusic_play(game->game_over);
    sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    display_end_screen(game);
    game->ret = 5;
    destroy_object(game->background_over);
    sfText_destroy(game->your_score);
}