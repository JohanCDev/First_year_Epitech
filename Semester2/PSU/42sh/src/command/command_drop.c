/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Frees a command structure
*/

#include <libmy/memory/alloc.h>
#include <stdlib.h>

#include "command.h"
#include "util.h"

static void sh_command_free_arg(void *arg)
{
    free(*(char **)arg);
}

void sh_command_reset(sh_command_t *command)
{
    assert(command->command_type >= 0
        && command->command_type < SH_COMMAND_TYPE_COUNT);
    switch (command->command_type) {
        case SH_COMMAND_BUILTIN: command->builtin.builtin = NULL; break;
        case SH_COMMAND_EXTERNAL:
            my_sfree((void **)&command->external.path);
            break;
        default: break;
    }
    command->command_type = SH_COMMAND_UNRESOLVED;
    my_vec_clear(&command->base.args, &sh_free_entry);
    command->base.pipe_pos = SH_PIPE_INVALID;
    my_sfree((void **)&command->base.input);
    my_sfree((void **)&command->base.output);
    sh_sclose_pipe(command->base.pipe_in);
    sh_sclose_pipe(command->base.pipe_out);
}

void sh_command_drop(sh_command_t *command)
{
    sh_command_reset(command);
    my_vec_free(&command->base.args, &sh_command_free_arg);
    my_vec_free(&command->base.arg_types, NULL);
}
