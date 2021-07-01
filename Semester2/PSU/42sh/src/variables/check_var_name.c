/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Checks the validity of a variable name
*/

#include <libmy/ascii.h>

#include "variables.h"

sh_error_t sh_check_var_name(char const *name, size_t name_len)
{
    if (!name || name_len == 0 || !(my_isalpha(*name) || *name == '_'))
        return SH_BAD_VAR_START;
    for (size_t i = 1; i < name_len; ++i)
        if (!(my_isalnum(name[i]) || name[i] == '_'))
            return SH_BAD_VAR_CHARS;
    return SH_OK;
}
