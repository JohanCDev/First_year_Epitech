/*
** EPITECH PROJECT, 2021
** LibMy - io module
** File description:
** Opens a file stream
*/

#include <sys/stat.h>

#include "libmy/io/iostream.h"
#include "my_fopen.h"

static int my_fopen_get_mode(const char *mode_str, int *invalid_mode)
{
    int plus = mode_str[0] != '\0' && mode_str[1] == '+';

    switch (*mode_str) {
        case 'r': return plus ? P_MY_FOPEN_R_PLUS : P_MY_FOPEN_R;
        case 'w': return plus ? P_MY_FOPEN_W_PLUS : P_MY_FOPEN_W;
        case 'a': return plus ? P_MY_FOPEN_A_PLUS : P_MY_FOPEN_A;
        default: *invalid_mode = 1; return 0;
    }
}

static int my_fopen_init_stream(char const *path, int mode, my_iostream_t *ios)
{
    int read_mode = mode == P_MY_FOPEN_R || mode == P_MY_FOPEN_R_PLUS;
    int fd = read_mode
        ? open(path, mode)
        : open(path, mode,
            S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    if (fd < 0)
        return 1;
    if (read_mode ? my_finit_input_fd(fd, ios) : my_finit_output_fd(fd, ios)) {
        my_fclose(ios);
        return 2;
    }
    return 0;
}

MY_IO_API int my_fopen(
    const char *path, const char *mode_str, my_iostream_t *stream)
{
    int invalid_mode = 0;
    int mode = my_fopen_get_mode(mode_str, &invalid_mode);

    if (invalid_mode)
        return 1;
    if (my_fopen_init_stream(path, mode, stream))
        return 2;
    return 0;
}
