/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Expands the first variable in a string
*/

#include <libmy/ascii.h>
#include <stdlib.h>

#include "shell.h"
#include "variables.h"

static sh_lstr_t sh_expand_var_get_name(char const *str)
{
    size_t len = 1;

    while (str[len] != '\0' && str[len] != '$' && !my_isspace(str[len]))
        ++len;
    return SH_LSTR(str, len);
}

static bool sh_expand_var_find_variable(
    char **start, sh_expansion_t *exp, sh_lstr_t *name)
{
    *name = SH_LSTR(NULL, 0);
    while ((*start)[0] != '\0' && !sh_is_var_expr_start((*start)[1]))
        *start = my_strechr(*start + 1, '$');
    if ((*start)[0] == '\0' || (*start)[1] == '\0') {
        exp->value_begin = (*start - exp->str) + ((*start)[0] != '\0');
        exp->value_end = exp->value_begin;
        return true;
    }
    *name = sh_expand_var_get_name(*start + 1);
    exp->value_begin = *start - exp->str;
    return false;
}

sh_error_t sh_expand_var_replace(
    sh_expansion_t *exp, sh_lstr_t name, sh_lstr_t value, size_t rest_start)
{
    size_t str_len = my_strlen(exp->str);
    char *new_str = realloc(
        exp->str, MY_MAX(str_len + 1, str_len - name.length + value.length));

    if (new_str == NULL)
        return SH_OUT_OF_MEMORY;
    exp->str = new_str;
    my_memmove(new_str + exp->value_begin + value.length, new_str + rest_start,
        str_len - rest_start + 1);
    my_memcpy(new_str + exp->value_begin, value.value, value.length);
    exp->value_end = exp->value_begin + value.length;
    return SH_OK;
}

sh_error_t sh_expand_var(
    sh_ctx_t *ctx, sh_expansion_t *exp, sh_lstr_t *name, bool copy_name)
{
    char *start = my_strechr(exp->str, '$');
    size_t rest_start;
    sh_lstr_t value;

    if (sh_expand_var_find_variable(&start, exp, name))
        return SH_OK;
    rest_start = exp->value_begin + name->length + 1;
    value = sh_var_get_any(ctx, *name);
    exp->value_end = rest_start - 1;
    if (copy_name)
        name->value = my_strndup(name->value, name->length);
    if (value.value == NULL)
        return SH_UNDEFINED_VAR;
    return sh_expand_var_replace(exp, *name, value, rest_start);
}
