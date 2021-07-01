/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Intitalizes a command struct
*/

#include <assert.h>

#include "command.h"

void sh_command_init(sh_command_t *command)
{
    *command = (sh_command_t){
        .base =
            {
                .command_type = SH_COMMAND_UNRESOLVED,
                .pipe_in = {-1, -1},
                .pipe_out = {-1, -1},
            },
    };
    my_vec_init(&command->base.args, sizeof(char *));
    my_vec_init(&command->base.arg_types, sizeof(sh_token_type_t));
}
