/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** puts a char into the standard output
*/

#include <unistd.h>
#include "libmy/io.h"

MY_IO_API void my_putchar(char c)
{
    write(1, &c, 1);
}

MY_IO_API void my_putchar_fd(int fd, char c)
{
    write(fd, &c, 1);
}
