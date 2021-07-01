/*
** EPITECH PROJECT, 2020
** include my.h
** File description:
** desc
*/

#ifndef MYBSQ_H
#define MYBSQ_H

typedef struct
{
    int x;
    int y;
    int size;
    int error;
    int big_x;
    int big_y;
} position;
int fs_open_file(char const *filepath);
int fs_understand_return_of_read(int fd, char *buffer, int size);
int get_size_file(char const *filepath);
int look_errors(int size, int fd);
char **populate_array(char *buffer, int size);
char *skip_first_line(char *buffer);
int check_dimensions(char **array, int lentgh, int width);
int get_length(char const *buffer, int i);
int do_bsq(char **array, int length, int width);
int look_for_errors(position square);

#endif