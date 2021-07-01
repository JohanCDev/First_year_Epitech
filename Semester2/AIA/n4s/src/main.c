/*
** EPITECH PROJECT, 2021
** B-AIA-200-NAN-2-1-n4s-johan.chrillesen
** File description:
** main
*/

#include "n4s.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int start_simulation(void)
{
    char *line = NULL;
    size_t size = 0;

    printf("START_SIMULATION\n");
    fflush(stdout);
    getline(&line, &size, stdin);
    fprintf(stderr, "%s\n", line);
    free(line);
    return (1);
}

int cycle_wait(int cycles)
{
    char *line = NULL;
    size_t size = 0;

    printf("CYCLE_WAIT:%d\n", cycles);
    fflush(stdout);
    getline(&line, &size, stdin);
    fprintf(stderr, "%s\n", line);
    free(line);
    return (1);
}

int stop_simulation(void)
{
    char *line = NULL;
    size_t size = 0;

    printf("STOP_SIMULATION\n");
    fflush(stdout);
    getline(&line, &size, stdin);
    free(line);
    return (1);
}

int is_ended(void)
{
    char *line = NULL;
    size_t size = 0;
    char **array = NULL;

    if (getline(&line, &size, stderr) == -1)
        return (0);
    fprintf(stderr, "%s\n", line);
    array = my_str_to_word_array(line, ":");
    if (!strcmp(array[3], "Track Cleared")) {
        free(line);
        printf("Finishhhhhhhhhhhhh\n");
        return (1);
    }
    free(line);
    return (0);
}

int main(void)
{
    float speed;
    float direction;
    
    start_simulation();
    while (42) {
        speed = manage_speed();
        // if (is_ended() == 1)
            // break;
        if (speed == 42)
            continue;
        direction = manage_direction();
        if (direction == 42)
            continue;
    }
    stop_simulation();
}