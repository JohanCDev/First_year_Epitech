/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-BSQ-johan.chrillesen
** File description:
** main
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "mybsq.h"
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char *filepath = argv[1];
    int fd = fs_open_file(filepath);
    int size = get_size_file(filepath);
    char *buff = malloc(sizeof(char) * (size + 1));
    int ret = 0;
    char **array;
    int width = 0;
    int length = 0;

    if (fd == -1 || look_errors(size, fd) == 84)
        return (84);
    fs_understand_return_of_read(fd, buff, size);
    width = my_getnbr(buff);
    buff = skip_first_line(buff);
    length = get_length(buff, 0);
    array = populate_array(buff, width);
    ret = check_dimensions(array, length, width);
    my_printf("%d", do_bsq(array, length, width));
    return (ret);
}