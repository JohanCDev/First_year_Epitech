/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Resets the path vector
*/

#include <libmy/ascii.h>
#include <stdlib.h>

#include "shell.h"
#include "util.h"

static int sh_copy_path_dir(my_vec_t *pathvec, size_t dir_len, char const *dir)
{
    char *entry;

    if (dir_len == 0)
        return 0;
    entry = malloc(sizeof(*dir) * (dir_len + 1));
    if (!entry || my_vec_push(pathvec, &entry) != MY_VEC_OK) {
        free(entry);
        my_vec_free(pathvec, &sh_free_entry);
        return 0;
    }
    my_strncpy(entry, dir, dir_len);
    entry[dir_len] = '\0';
    return 0;
}

static void sh_copy_path(my_vec_t *pathvec, char const *path)
{
    char *next = my_strchr(path, ':');

    while (next) {
        if (sh_copy_path_dir(pathvec, next - path, path))
            return;
        path = next + 1;
        next = my_strchr(path, ':');
    }
    sh_copy_path_dir(pathvec, my_strlen(path), path);
}

void sh_ctx_reset_path(sh_ctx_t *ctx)
{
    char *path = NULL;

    for (size_t i = 0; i < ctx->path.length; ++i)
        free(MY_VEC_GET_ELEM(char *, &ctx->path, i));
    ctx->path.length = 0;
    for (size_t i = 0; i < ctx->env.length - 1; ++i) {
        if (my_strncmp(MY_VEC_GET_ELEM(char *, &ctx->env, i), "PATH=", 5)
            == 0) {
            path = MY_VEC_GET_ELEM(char *, &ctx->env, i) + 5;
            break;
        }
    }
    if (path)
        sh_copy_path(&ctx->path, path);
    else
        sh_copy_path(&ctx->path, DEFAULT_PATH);
}
