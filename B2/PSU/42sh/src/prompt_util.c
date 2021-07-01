/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** More prompt format functions
*/

#include <libmy/io.h>
#include <libmy/ascii.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

#include "shell.h"
#include "token.h"
#include "util.h"

void sh_print_name(sh_ctx_t *ctx)
{
    char *username;

    username = getlogin();
    my_puts(username);
    (void)ctx;
}

void sh_print_hostname(sh_ctx_t *ctx)
{
    char **host = sh_env_get_entry(ctx, SH_LSTR("HOSTNAME", 8));

    if (host) {
        my_puts(*host+9);
    }
}

void sh_print_d(sh_ctx_t *ctx)
{
    time_t now;
    struct tm *local;
    char *week_day[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    time(&now);
    local = localtime(&now);
    my_puts(week_day[local->tm_wday]);
    (void)ctx;
}

void sh_print_dd(sh_ctx_t *ctx)
{
    time_t now;
    struct tm *local;

    time(&now);
    local = localtime(&now);
    my_printf("%d", local->tm_mday);
    (void)ctx;
}
