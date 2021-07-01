#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    struct padding_s {
        int nb;
        char c;
        char message[40];
    };

int main(void)
{
    FILE *file;
    struct padding_s padding = {192837, 'k', "Corewar is swag!!"};

    file = fopen("one-structure.yolo", "w");
    if (file == NULL) {
        fprintf(stderr, "Unable to create file\n");
        return (84);
    }
    fwrite(&padding.nb, sizeof(int), 1, file);
    fwrite(&padding.c, sizeof(char), 1, file);
    fwrite(&padding.message, sizeof(padding.message), 1, file);
    fclose(file);
    return (0);
}