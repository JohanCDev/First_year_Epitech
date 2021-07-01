/*
** EPITECH PROJECT, 2021
** B-CPE-210-NAN-2-1-stumper1-maxime3.vincent
** File description:
** head
*/

#ifndef HEAD_C
#define HEAD_C

typedef struct head_t {
    int v;
    int n;
    int c;
    int q;
    int nb_files;
} s_head;

int check_quiet(char *option);
int check_bytes(char *option);
int check_lines(char *option);
int check_verbose(char *option);

void print_for_lines(char *buffer, int nb_lines_to_jump);
int display_lines(char **args, int x, s_head *head);
int display_bytes(char **args, int x, s_head *head);

#endif