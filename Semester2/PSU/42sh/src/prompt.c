/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Prints prompt
*/

#include <libmy/io.h>
#include <libmy/ascii.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

#include "shell.h"
#include "util.h"
#include "prompt.h"

static const sh_prompt_t prompt_flags[] = {
    {'/', &sh_print_wd},
    {'t', &sh_print_t},
    {'T', &sh_print_tt},
    {'p', &sh_print_p},
    {'P', &sh_print_pp},
    {'n', &sh_print_name},
    {'m', &sh_print_hostname},
    {'d', &sh_print_d},
    {'D', &sh_print_dd},
    {'w', &sh_print_w},
    {'W', &sh_print_ww},
    {'y', &sh_print_y},
    {'Y', &sh_print_yy},
};

void prompt_flag(char const *prompt, sh_ctx_t *ctx, int *i)
{
    *i = *i + 1;

    if (prompt[*i] == '%') {
        my_putc('%');
        return;
    }
    for (int j = 0; j < 12; j++)
        if (prompt_flags[j].flag == prompt[*i]) {
            prompt_flags[j].run(ctx);
            return;
        }
}

void sh_promptf(sh_ctx_t *ctx, char const *prompt)
{
    for (int i = 0; prompt[i] != '\0'; i++) {
        if (prompt[i] == '%')
            prompt_flag(prompt, ctx, &i);
        else
            my_putc(prompt[i]);
        my_flush_stdout();
    }
}

void sh_print_prompt(sh_ctx_t *ctx)
{
    sh_lstr_t value = sh_var_get(ctx, SH_LSTR("prompt", 6));

    if (ctx->is_tty) {
        if (value.value)
            sh_promptf(ctx, value.value);
        else
            sh_promptf(ctx, "$> ");
    }
}
