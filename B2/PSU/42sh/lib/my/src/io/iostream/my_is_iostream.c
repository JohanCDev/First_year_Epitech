/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Tests if a stream is an input or an output stream
*/

#include "libmy/io.h"

MY_IO_API int my_is_input_stream(my_iostream_t const *stream)
{
    return stream->vtable->read != NULL;
}

MY_IO_API int my_is_output_stream(my_iostream_t const *stream)
{
    return stream->vtable->write != NULL;
}
