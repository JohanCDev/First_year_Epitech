/*
** EPITECH PROJECT, 2021
** B-CPE-110-NAN-1-1-antman-tanguy.bellicha
** File description:
** antman
*/

#ifndef ANTMAN_H
#define ANTMAN_H

#define char_is_alpha(c) ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') \
|| (c == '\'') || (c >= '0' && c <= '9') || c == '-') ? 1 : 0

#define is_special_char(c) (((c >= ':' && c <= '?') || (c >= '!' && c <= '/') \
|| (c >= '[' && c <= '`') || (c >= '{' && c <= '~')) && \
(c != '#' || c != '@')) ? 1 : 0

typedef struct antman_t {
    int ret;
    char *file_content;
    char **list_of_words;
    char **differents_words;
    int i_list;
    int *word_indexes;
    int nb;
    int nb_commun_words;
    int nb_words;
} s_antman;

char *populate_str(int fd, char *buffer, char *str, int length);
char *read_file(struct stat file_stat, int fd);
int check_file(char *filepath, s_antman *antman);
int fill_list(s_antman *antman, int start);
int word_is_in_list(char *str, char **list);
char **add_in_list(char *str, char **list);
int fill_differents_words(s_antman *antman);
int find_in_list(s_antman *antman, int i);
int check_different_words(s_antman *antman, int i_main);
int check_end(s_antman *antman, int i, int k);
int compress_string(s_antman *antman);
int compress_image(char *filepath, s_antman *antman);
int print_hexa_line(s_antman *antman);
int my_skipline(char *str, int i);

#endif