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

static void fill_vec_from_glob(my_vec_t *new_args, glob_t *globbuf)
{
    for (size_t i = 0; i < globbuf->gl_pathc; i++)
        my_vec_push(new_args, globbuf->gl_pathv + i);
}

static int fill_globbuf(glob_t *globbuf, sh_command_t *command,
    size_t *nb_args, my_vec_t *new_args)
{
    char *arg;
    int flags = GLOB_TILDE;
    int type_id = 1;
    int return_code = 0;

    for (size_t i = 1; i < *nb_args - 1; i++) {
        arg = MY_VEC_GET(char *, &command->base.args, i);
        if (MY_VEC_GET(sh_token_type_t, &command->base.arg_types, type_id++)
            != SH_TOKEN_UNQUOTED_STR)
            continue;
        return_code = glob(arg, flags, NULL, globbuf);
        if (return_code == GLOB_NOSPACE || return_code == GLOB_ABORTED)
            break;
        if (return_code == 0) {
            fill_vec_from_glob(new_args, globbuf);
            my_vec_remove(&command->base.args, NULL, i--);
            free(arg);
            (*nb_args)--;
        }
    }
    return return_code;
}

static void handle_globbuf(
    sh_ctx_t *ctx, sh_command_t *command, my_vec_t *new_args, size_t nb_args)
{
    size_t count_globbed = new_args->length;
    char *arg;
    sh_token_type_t token_type = SH_TOKEN_UNQUOTED_STR;

    if (count_globbed == 0) {
        ctx->exit_code = 1;
        sh_perror(MY_VEC_GET(char *, &command->base.args, 0), SH_NO_MATCH);
    }
    my_vec_remove(&command->base.args, &arg, nb_args - 1);
    free(arg);
    for (size_t i = 0; i < new_args->length; i++) {
        arg = MY_VEC_GET(char *, new_args, i);
        my_vec_push(&command->base.args, &arg);
        my_vec_push(&command->base.arg_types, &token_type);
    }
}

bool sh_command_globbing(sh_ctx_t *ctx, sh_command_t *command)
{
    glob_t globbuf;
    char *arg = NULL;
    int return_code = 0;
    size_t nb_args = command->base.args.length;
    const sh_token_type_t arg_type = SH_TOKEN_SINGLE_STR;
    my_vec_t new_args;

    if (!sh_command_need_globbing(command, &globbuf))
        return true;
    globfree(&globbuf);
    globbuf.gl_pathc = 0;
    my_vec_init(&new_args, sizeof(char *));
    return_code = fill_globbuf(&globbuf, command, &nb_args, &new_args);
    handle_globbuf(ctx, command, &new_args, nb_args);
    my_vec_push(&command->base.args, &arg);
    my_vec_push(&command->base.arg_types, (void *)&arg_type);
    my_vec_free(&new_args, NULL);
    return (return_code != GLOB_NOSPACE && return_code != GLOB_ABORTED
        && ctx->exit_code != 1);
}
