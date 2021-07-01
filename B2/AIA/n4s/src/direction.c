/*
** EPITECH PROJECT, 2021
** B-AIA-200-NAN-2-1-n4s-johan.chrillesen
** File description:
** direction
*/

#include "n4s.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int go_forward(float speed)
{
    char *line = NULL;
    size_t size = 0;

    printf("CAR_FORWARD:%.2f\n", speed);
    fflush(stdout);
    getline(&line, &size, stdin);
    fprintf(stderr, "%s\n", line);
    free(line);
    return (1);
}

int go_backward(float speed)
{
    char *line = NULL;
    size_t size = 0;

    printf("CAR_BACKWARDS:%.2f\n", speed);
    fflush(stdout);
    getline(&line, &size, stdin);
    fprintf(stderr, "%s\n", line);
    free(line);
    return (1);
}