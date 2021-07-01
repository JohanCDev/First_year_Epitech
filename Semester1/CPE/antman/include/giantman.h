/*
** EPITECH PROJECT, 2021
** B-CPE-110-NAN-1-1-antman-tanguy.bellicha
** File description:
** giantman
*/

#ifndef GIANTMAN_H
#define GIANTMAN_H

typedef struct giantman_t {
    int ret;
    char *file_content;
} s_giantman;

int uncompress_image(char *filepath, s_giantman *giantman);
char *read_uncompressed_image(struct stat file_stat, int fd);
char *get_image_str(int fd, char *buffer, char *str, int length);
int hexa_to_dec(char *str);
char *my_getstr(char *str);
int my_skipline(char *str, int i);
int print_dec_line(s_giantman *giantman);

#endif