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

    file = fopen("number-as-text.yolo", "w");
    if (file == NULL) {
        fprintf(stderr, "Unable to create file\n");
        return (84);
    }
    fprintf(file, "%d", 12345678);
    fclose(file);
    return (0);
}