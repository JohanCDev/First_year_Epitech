/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Fetches the current working directory
*/

#include <errno.h>
#include <libmy/ascii.h>
#include <libmy/memory.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

static char *sh_get_cwd_free_path(char *path)
{
    free(path);
    return NULL;
}

static char *sh_normalize_path(char *path)
{
    size_t len;

    if (!path)
        return NULL;
    len = my_strlen(path);
    while (len > 1 && path[len - 1] == '/') {
        path[len - 1] = '\0';
        --len;
    }
    return path;
}

char *sh_get_cwd(void)
{
    char *path = NULL;
    size_t capacity = PATH_MAX;

    errno = 0;
    path = getcwd(NULL, 0);
    if (path && errno == 0)
        return *path == '(' ? sh_get_cwd_free_path(path)
                            : sh_normalize_path(path);
    do {
        free(path);
        path = malloc(capacity);
        if (!path)
            return NULL;
        getcwd(path, capacity);
        capacity *= 2;
    } while (errno == ERANGE);
    if (errno != 0 || (path && *path == '('))
        return sh_get_cwd_free_path(path);
    return sh_normalize_path(path);
}
