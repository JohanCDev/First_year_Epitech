/*
** EPITECH PROJECT, 2021
** B-AIA-200-NAN-2-1-n4s-johan.chrillesen
** File description:
** wheels
*/

#include "n4s.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int set_wheels_direction(double average, double dir)
{
    char *line = NULL;
    size_t size = 0;

    printf("WHEELS_DIR:");
    if (average < 0.0)
        printf("-");
    printf("%f\n", dir);
    fflush(stdout);
    getline(&line, &size, stdin);
    fprintf(stderr, "%s\n", line);
    free(line);
    return (1);
}

void check_lidar_right_left(double *lidar, double aver)
{
    if (lidar[1] < 100)
        set_wheels_direction(-1, 0.3);
    else if (lidar[31] < 100)
        set_wheels_direction(1, 0.3);
    else
        set_wheels_direction(aver, 0.4);
}

int set_dir(double *lidar, double dir)
{
    int result = 1;
    double average = lidar[1] - lidar[31];

    if (dir >= 1500)
        result = set_wheels_direction(average, 0.005);
    else if (dir >= 1000)
        result = set_wheels_direction(average, 0.05);
    else if (dir >= 600)
        result = set_wheels_direction(average, 0.1);
    else if (dir >= 400)
        result = set_wheels_direction(average, 0.2);
    else if (dir >= 200)
        result = set_wheels_direction(average, 0.3);
    else
        result = set_wheels_direction(average, 0.5);
    return result;
}


int manage_direction(void)
{
    double direction;
    double *lidar = get_info_lidar();
    if (lidar == NULL)
        return 42;
    direction = lidar[16];
    if (set_dir(lidar, direction) != 1)
        return 0;
    //free(lidar);
    return 42;
}