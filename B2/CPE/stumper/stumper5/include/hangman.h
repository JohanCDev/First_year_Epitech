/*
** EPITECH PROJECT, 2021
** sandpile.h
** File description:
** sandpile.h
*/


#ifndef __HANGMAN__
#define __HANGMAN__

//-----NEEDED-INCLUDE------
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <fcntl.h>
//-----MACROS--------------

//-----STRUCTURE-----------
typedef struct s_hangman {
    char *word_to_find;
    char *word;
    int nb_tries;
    int ret;
} hangman_t;

//-----PROTOTYPES----------

//my_str_to_word_array.c
char **my_str_to_word_array(char *str, char *delims);

//my_str_isnum.c
int my_str_isnum(char const *str);

//open_and_read_file.c
char *open_and_read_file(char const *filepath);

//check_letter.c
int check_letter(char c, hangman_t *hang);

//initialize.c
hangman_t *init_and_check(int argc, char **argv);

//get_word.c
int initialize_words(hangman_t *hang, char **array, int nb_rand);
int pick_random_word(hangman_t *hang, char *file);
bool get_word_in_file(hangman_t *hang, char **argv);

//play.c
int show_word(hangman_t *hang);
int play(hangman_t *hang);

//free_all.c
void free_array(char **array);
void free_struct(hangman_t *hang);

//init_tests.c
void init_tests(hangman_t *hang, char *word);

#endif