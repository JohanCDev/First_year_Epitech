/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Retrieves the builtin streams
*/

#include "libmy/io.h"

#include "iostream.h"

static const p_my_iostream_vtable_t VOID_INPUT_VTABLE = {
    .read = p_my_fread_void,
};

static const p_my_iostream_vtable_t VOID_OUTPUT_VTABLE = {
    .write = p_my_fwrite_void,
    .eof = p_my_feof_void,
};

static const my_iostream_t VOID_INPUT = {.vtable = &VOID_INPUT_VTABLE};

static const my_iostream_t VOID_OUTPUT = {.vtable = &VOID_OUTPUT_VTABLE};

MY_IO_API my_iostream_t *my_get_stdin(void)
{
    static my_iostream_t my_stdin;

    return &my_stdin;
}

MY_IO_API my_iostream_t *my_get_stdout(void)
{
    static my_iostream_t my_stdout;

    return &my_stdout;
}

MY_IO_API my_iostream_t *my_get_stderr(void)
{
    static my_iostream_t my_stderr;

    return &my_stderr;
}

MY_IO_API my_iostream_t *my_get_void_input(void)
{
    return (my_iostream_t *)&VOID_INPUT;
}

MY_IO_API my_iostream_t *my_get_void_output(void)
{
    return (my_iostream_t *)&VOID_OUTPUT;
}
