/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** The entry point of the program
*/

#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#include "shell.h"

static int sh_init_stdio(struct termios *oldt)
{
    struct termios newt;

    if (my_init_stdout(malloc(IO_BUF_SIZE), IO_BUF_SIZE, &free))
        return 84;
    if (my_init_stderr(malloc(IO_BUF_SIZE), IO_BUF_SIZE, &free)) {
        my_free_stdout();
        return 84;
    }
    if (my_init_stdin(malloc(IO_BUF_SIZE), IO_BUF_SIZE, &free)) {
        my_free_stdout();
        my_free_stderr();
        return 84;
    }
    tcgetattr(STDIN_FILENO, oldt);
    newt = *oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    return 0;
}

static void sh_free_stdio(void)
{
    my_free_stdout();
    my_free_stderr();
    my_free_stdin();
}

int main(int argc, char *argv[], char *envp[])
{
    sh_ctx_t ctx;
    struct termios oldt;

    if (sh_init_stdio(&oldt))
        return 84;
    if (sh_ctx_init(&ctx, argc, (char const **)argv, envp)) {
        sh_free_stdio();
        return 84;
    }
    if (sh_parse_args(&ctx, argc, (char const **)argv))
        sh_start(&ctx);
    sh_ctx_drop(&ctx);
    sh_free_stdio();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ctx.exit_code;
}
