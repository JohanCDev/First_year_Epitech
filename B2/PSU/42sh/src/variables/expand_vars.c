/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Expands the variables in a string
*/

#include <libmy/ascii.h>

#include "variables.h"

sh_error_t sh_expand_vars(
    sh_ctx_t *ctx, char **str, sh_lstr_t *name, bool copy_name)
{
    sh_expansion_t exp = {.str = *str};
    sh_error_t ret;

    do {
        ret = sh_expand_var(ctx, &exp, name, copy_name);
        *str = exp.str;
        if (ret != SH_OK)
            return ret;
    } while (exp.str[exp.value_end] != '\0');
    return SH_OK;
}
