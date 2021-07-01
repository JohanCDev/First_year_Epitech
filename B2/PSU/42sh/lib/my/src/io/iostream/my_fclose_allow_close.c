/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Closes files using the close syscall
*/

#include <unistd.h>
#include "libmy/io.h"

MY_LOCAL int p_my_fclose_unix(p_my_iostream_unix_t *stream)
{
    return close(stream->fd) == -1;
}
