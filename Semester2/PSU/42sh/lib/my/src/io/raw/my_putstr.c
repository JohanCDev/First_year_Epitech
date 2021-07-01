/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Prints a string into the standard output
*/

#include <unistd.h>
#include "libmy/ascii.h"
#include "libmy/io.h"

MY_IO_API int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return 0;
}

MY_IO_API int my_putstr_fd(int fd, char const *str)
{
    write(fd, str, my_strlen(str));
    return 0;
}
