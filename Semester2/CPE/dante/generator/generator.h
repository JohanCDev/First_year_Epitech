/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-johan.chrillesen
** File description:
** generator
*/

#ifndef GENERATOR_H_
#define GENERATOR_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>

typedef struct s_generator{
    int i;
    int n;
    int x;
    int y;
    int **tab;
} t_generator;

void display_maze(t_generator *);
void put_start_end(t_generator *);
int fill_int_array(t_generator *);
int	check_end(t_generator *);
void merge_cells(t_generator *);
void make_imperfect(t_generator *);

#endif /* !GENERATOR_H_ */
