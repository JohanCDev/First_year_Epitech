/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Puts an unsigned int into the speicified stream
*/

#include "libmy/io.h"

MY_IO_API size_t my_fputuint(unsigned int nb, my_iostream_t *stream)
{
    return my_fputuintmax_t_base(nb, "0123456789", 10, stream);
}
