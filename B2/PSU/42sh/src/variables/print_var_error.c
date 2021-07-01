/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Prints an error, with extra information if it is a variable error
*/

#include <libmy/printf.h>

#include "variables.h"

bool sh_print_var_error(sh_error_t code, sh_lstr_t name)
{
    switch (code) {
        case SH_OK: return true;
        case SH_UNDEFINED_VAR:
            my_fprintf(MY_STDERR, "%.*s: Undefined variable.\n", name.length,
                name.value);
            return false;
        default: return (bool)sh_rerror(NULL, code, 0);
    }
}
