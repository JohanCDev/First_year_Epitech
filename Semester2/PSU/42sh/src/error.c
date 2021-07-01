/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Prints errors
*/

#include <errno.h>
#include <libmy/io/iostream.h>
#include <string.h>
#include "shell.h"

static char const *ERROR_MESSAGES[SH_ERROR_MAX] = {
    [SH_OK] = "no error",
    [SH_EXPRESSION_SYNTAX] = "Expression Syntax",
    [SH_BAD_NUMBER] = "Badly formed number",
    [SH_BAD_VAR_START] = "Variable name must begin with a letter",
    [SH_BAD_VAR_CHARS] = "Variable name must contain alphanumeric characters",
    [SH_TOO_MANY_ARGS] = "Too many arguments",
    [SH_TOO_FEW_ARGS] = "Too few arguments",
    [SH_CD_NO_HOME_DIR] = "No home directory",
    [SH_CD_HOME_DIR] = "Can't change to home directory",
    [SH_OUT_OF_MEMORY] = "Out of memory",
    [SH_INVALID_NULL_COMMAND] = "Invalid null command",
    [SH_MISSING_REDIRECT_NAME] = "Missing name for redirect",
    [SH_AMBIGUOUS_INPUT_REDIRECT] = "Ambiguous input redirect",
    [SH_AMBIGUOUS_OUTPUT_REDIRECT] = "Ambiguous output redirect",
    [SH_NO_MATCH] = "No match",
    [SH_READ_ONLY_VAR] = "Cannot write to read-only variable",
    [SH_UNDEFINED_VAR] = "Undefined variable",
    [SH_ILLEGAL_VAR] = "Illegal variable name",
    [SH_UNKNOWN_KEY] = "Unknown key",
    [SH_UNKNOWN_KEYBIND_FUNCTION] = "Unknown keybind function",
    [SH_ALIAS_LOOP] = "Alias loop",
};

char const *sh_strerror(sh_error_t code)
{
    if (code < SH_OK || code >= SH_ERROR_MAX)
        return "Unknown error";
    return ERROR_MESSAGES[code];
}

sh_error_t sh_perror(char const *prefix, sh_error_t code)
{
    if (code == SH_OK)
        return code;
    if (prefix) {
        my_eputs(prefix);
        my_eputs(": ");
    }
    my_eputs(sh_strerror(code));
    my_eputs(".\n");
    my_flush_stderr();
    return code;
}

int sh_perror_errno(char const *prefix)
{
    if (prefix) {
        my_eputs(prefix);
        my_eputs(": ");
    }
    my_eputs(strerror(errno));
    my_eputs(".\n");
    my_flush_stderr();
    return errno;
}
