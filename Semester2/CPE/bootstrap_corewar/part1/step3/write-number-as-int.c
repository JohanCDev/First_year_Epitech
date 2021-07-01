#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *file;
    int nb = 12345678;

    file = fopen("number-as-int.yolo", "w");
    if (file == NULL) {
        fprintf(stderr, "Unable to create file\n");
        return (84);
    }
    fclose(file);
    return (0);
}