/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Puts an int into the speicified stream
*/

#include "libmy/io.h"

MY_IO_API size_t my_fputint(int nb, my_iostream_t *stream)
{
    return my_fputintmax_t_base(nb, "0123456789", 10, stream);
}
