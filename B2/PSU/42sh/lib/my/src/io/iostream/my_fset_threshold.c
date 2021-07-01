/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Sets the flushing threshold for a stream
*/

#include "libmy/io.h"

MY_LOCAL int p_my_fset_threshold_unix(
    p_my_iostream_unix_t *stream, float threshold)
{
    if (threshold < 0.0 || threshold > 1.0)
        return 1;
    stream->threshold = threshold;
    return 0;
}

MY_IO_API int my_fset_flush_threshold(float threshold, my_iostream_t *stream)
{
    p_my_fset_threshold_impl_t func = stream->vtable->set_threshold;

    if (func)
        return (*func)(stream, threshold);
    return 0;
}
