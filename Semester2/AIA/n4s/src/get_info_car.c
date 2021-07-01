/*
** EPITECH PROJECT, 2021
** B-AIA-200-NAN-2-1-n4s-johan.chrillesen
** File description:
** get_info_car
*/

#include "n4s.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

double *get_info_lidar(void)
{   
    char *line = NULL;
    size_t size = 0;
    char **infos = NULL;
    double *info_float = malloc(sizeof(double) * 32);

    printf("GET_INFO_LIDAR\n");
    fflush(stdout);
    getline(&line, &size, stdin);
    infos = my_strtok(line, ":\n");
    for (int i = 3; infos[i]; i++)
        info_float[i - 3] = atof(infos[i]);
    // free(line);
    // free(infos);
    return (info_float);
}

float get_current_speed(void)
{
    char *line = NULL;
    size_t size = 0;

    printf("GET_CAR_SPEED_MAX\n");
    fflush(stdout);
    getline(&line, &size, stdin);
    fprintf(stderr, "%s\n", line);
    // free(line);
    return (atof(line));
}