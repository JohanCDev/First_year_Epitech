/*
** EPITECH PROJECT, 2021
** B-CPE-201-NAN-2-1-bscorewar-johan.chrillesen
** File description:
** step1
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *file;

    file = fopen("some-text.yolo", "w");
    if (file == NULL) {
        fprintf(stderr, "Unable to create file\n");
        return (84);
    }
    fprintf(file, "Hello bambino\n");
    fclose(file);
    return (0);
}