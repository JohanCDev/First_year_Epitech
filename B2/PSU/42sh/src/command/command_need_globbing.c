/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Parses the next command
*/

#include <glob.h>
#include <libmy/ascii.h>
#include <libmy/collections.h>
#include <stdlib.h>
#include <sys/types.h>

#include "builtin.h"
#include "command.h"
#include "util.h"

static bool has_unquoted_strings(sh_command_t *command, size_t nb_args)
{
    for (size_t i = 1; i < nb_args - 1; i++)
        if (MY_VEC_GET(sh_token_type_t, &command->base.arg_types, i)
            == SH_TOKEN_UNQUOTED_STR)
            return true;
    return false;
}

static bool has_globbing_chars(
    glob_t *globbuf, sh_command_t *command, size_t nb_args)
{
    char *arg;
    int flags = GLOB_TILDE | GLOB_NOMAGIC;
    int return_code = 0;

    for (size_t i = 1; i < nb_args - 1; i++) {
        if (MY_VEC_GET(sh_token_type_t, &command->base.arg_types, i)
            != SH_TOKEN_UNQUOTED_STR)
            continue;
        arg = MY_VEC_GET(char *, &command->base.args, i);
        return_code = glob(arg, flags, NULL, globbuf);
        if (return_code == GLOB_NOSPACE || return_code == GLOB_ABORTED)
            break;
        flags |= (i == 1) ? GLOB_APPEND : 0;
    }
    if (nb_args - 2 != globbuf->gl_pathc)
        return true;
    for (size_t i = 1; i < nb_args - 1; i++)
        if (my_strcmp(MY_VEC_GET(char *, &command->base.args, i),
                globbuf->gl_pathv[i - 1]))
            return true;
    return false;
}

bool sh_command_need_globbing(sh_command_t *command, glob_t *globbuf)
{
    size_t nb_args = command->base.args.length;

    globbuf->gl_offs = 0;
    globbuf->gl_pathc = 0;
    globbuf->gl_pathv = NULL;
    if (nb_args < 2 || !has_unquoted_strings(command, nb_args)
        || !has_globbing_chars(globbuf, command, nb_args)) {
        globfree(globbuf);
        return false;
    }
    globfree(globbuf);
    if (command->command_type != SH_COMMAND_BUILTIN)
        return true;
    return command->builtin.builtin->need_glob;
}
