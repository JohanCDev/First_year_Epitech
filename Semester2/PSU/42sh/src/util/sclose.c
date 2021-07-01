/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** Closes a file descriptor and sets it to -1
*/

#include <assert.h>
#include <unistd.h>

int sh_sclose(int *fd)
{
    int ret;

    assert(fd != NULL);
    if (*fd == -1)
        return 0;
    ret = close(*fd);
    *fd = -1;
    return ret;
}

int sh_sclose_pipe(int pipefd[2])
{
    int ret_0;
    int ret_1;

    if (pipefd == NULL)
        return 0;
    ret_0 = sh_sclose(&pipefd[0]);
    ret_1 = sh_sclose(&pipefd[1]);
    return ret_0 ? ret_0 : ret_1;
}
