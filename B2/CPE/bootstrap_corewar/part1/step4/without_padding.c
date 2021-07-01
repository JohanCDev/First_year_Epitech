#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *file;
    int nb = 192837;
    char message[40] = "Corewar is swag!!";
    char c = 'k';

    file = fopen("several-variables.yolo", "w");
    if (file == NULL) {
        fprintf(stderr, "Unable to create file\n");
        return (84);
    }
    fwrite(&nb, sizeof(int), 1, file);
    fwrite(&c, sizeof(char), 1, file);
    fwrite(&message, sizeof(message), 1, file);
    fclose(file);
    return (0);
}