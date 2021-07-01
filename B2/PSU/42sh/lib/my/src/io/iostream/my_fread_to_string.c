/*
** EPITECH PROJECT, 2021
** LibMy - io module
** File description:
** Reads the contents of the standard input
*/

#include <stdlib.h>
#include <unistd.h>
#include "libmy/collections.h"
#include "libmy/core.h"
#include "libmy/io.h"

static size_t read_to_vec(my_vec_t *vec, size_t to_read, my_iostream_t *stream)
{
    size_t read;

    if (my_vec_ensure_capacity(vec, to_read + vec->length + 1))
        return 0;
    read = my_fread(((char *)vec->data) + vec->length, 1, to_read, stream);
    vec->length += read;
    ((char *)vec->data)[vec->length] = '\0';
    return read;
}

MY_IO_API char *my_fread_to_string(
    size_t count, size_t *output_len, my_iostream_t *stream)
{
    my_vec_t output;

    my_vec_init(&output, sizeof(char));
    *output_len = 0;
    if (my_vec_push(&output, ""))
        return NULL;
    output.length = 0;
    while (output.length < count) {
        size_t most = count - output.length;
        size_t read = read_to_vec(&output, MY_MIN(most, MY_READ_SIZE), stream);

        if (read > 0)
            continue;
        if (my_feof(stream))
            break;
        my_vec_free(&output, NULL);
        return NULL;
    }
    *output_len = output.length;
    return (char *)(output.data);
}
