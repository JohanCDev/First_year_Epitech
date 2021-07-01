/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Flushes the builtin streams
*/

#include "libmy/io.h"

MY_IO_API int my_flush_stdin(void)
{
    return my_fflush(MY_STDIN);
}

MY_IO_API int my_flush_stdout(void)
{
    return my_fflush(MY_STDOUT);
}

MY_IO_API int my_flush_stderr(void)
{
    return my_fflush(MY_STDERR);
}
