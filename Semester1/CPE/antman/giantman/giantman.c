/*
** EPITECH PROJECT, 2021
** B-CPE-110-NAN-1-1-antman-tanguy.bellicha
** File description:
** giantman
*/

#include "my.h"
#include "giantman.h"

int verify_file(char *filepath)
{
    struct stat image_stat;
    int fd = 0;

    if ((fd = open(filepath, O_RDONLY)) == -1) {
        my_put_error("Can't read this file.\n");
        close(fd);
        return (84);
    }
    if (stat(filepath, &image_stat) || S_ISDIR(image_stat.st_mode))
        return (84);
    return (0);
}

void switch_extension(char *filepath, int num_extension, s_giantman *giantman)
{
    switch (num_extension) {
        case 1:
            giantman->ret = verify_file(filepath);
            break;
        case 2:
            giantman->ret = verify_file(filepath);
            break;
        case 3:
            giantman->ret = uncompress_image(filepath, giantman);
            break;
    }
}

s_giantman *initialize(void)
{
    s_giantman *giantman;

    if (!(giantman = malloc(sizeof(s_giantman *))) || \
    !(giantman->file_content = malloc(sizeof(char *))))
        return (NULL);
    else
        return (giantman);
}

int my_skipline(char *str, int i)
{
    while (str[i] && str[i] != '\n') {
        i++;
    }
    i++;
    return (i);
}

int main(int argc, char **argv)
{
    s_giantman *giantman = initialize();

    if (!giantman)
        return (84);
    if (argc != 3 || giantman->ret == 84 || (!(my_getnbr(argv[2]) >= 1 \
    && my_getnbr(argv[2]) <= 3)))
        return (84);
    switch_extension(argv[1], my_getnbr(argv[2]), giantman);
    if (giantman->ret != 0)
        return (84);
    return (0);
}