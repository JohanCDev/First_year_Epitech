/*
** EPITECH PROJECT, 2021
** B-CPE-110-NAN-1-1-antman-tanguy.bellicha
** File description:
** antman
*/

#include "my.h"
#include "antman.h"

int verify_file(char *filepath)
{
    struct stat image_stat;
    int fd = 0;

    if ((fd = open(filepath, O_RDONLY)) == -1) {
        my_put_error("Can't read this file.\n");
        close(fd);
        return (84);
    }
    if (stat(filepath, &image_stat) || S_ISDIR(image_stat.st_mode)) {
        return (84);
    }
    return (0);
}

void switch_extension(char *filepath, int num_extension, s_antman *antman)
{
    switch (num_extension) {
        case 1:
            antman->ret = verify_file(filepath);
            break;
        case 2:
            antman->ret = verify_file(filepath);
            break;
        case 3:
            antman->ret = compress_image(filepath, antman);
            break;
    }
}

s_antman *initialize(void)
{
    s_antman *antman;

    if (!(antman = malloc(sizeof(s_antman *))) || \
    !(antman->file_content = malloc(sizeof(char *))) || \
    !(antman->list_of_words = malloc(sizeof(char **))) || \
    !(antman->differents_words = malloc(sizeof(char **))) || \
    !(antman->word_indexes = malloc(sizeof(int *))))
        return (NULL);
    else
        return (antman);
}

void write_compressed(s_antman *antman)
{
    int i = 0;

    while (antman->differents_words[i])
        my_printf("@%s", antman->differents_words[i++]);
    my_printf("|");
    for (i = 0; antman->word_indexes[i] != -1; i++) {
        my_printf("#%d\ni : %d\n", antman->word_indexes[i], i);
    }
    my_printf("\n");
}

int main(int argc, char **argv)
{
    s_antman *antman = initialize();
    if (!antman)
        return (84);
    if (argc != 3 || antman->ret == 84 || (!(my_getnbr(argv[2]) >= 1 \
    && my_getnbr(argv[2]) <= 3)))
        return (84);
    switch_extension(argv[1], my_getnbr(argv[2]), antman);
    if (antman->ret != 0)
        return (84);
    return (0);
}