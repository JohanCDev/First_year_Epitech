/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper1-maxime3.vincent
** File description:
** head
*/

#ifndef HEAD_C
#define HEAD_C

typedef struct s_game {
    char **map;
    char **next_map;
    int height;
    int width;
    int ret;
} game_t;

game_t *check_errors(char **argv);
void get_map(game_t *game, struct stat file_stat, int fd);
int check_map(char const *buffer, int height);
int check_length(char const *buffer, int i, int nb_columns, \
int nb_columns_base);

void play_game(game_t *game, int nb_rounds);


void array_free(char **array);
char **copy_array(char **array, int free, int height);

#endif