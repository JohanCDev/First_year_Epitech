/*
** EPITECH PROJECT, 2021
** LibMy - io module
** File description:
** Reads the next line
*/

#include "libmy/collections.h"
#include "libmy/io.h"

MY_LOCAL void my_getdelim_alloc_vec(
    my_vec_t *linevec, char *line, size_t alloc_size)
{
    if (line == NULL) {
        my_vec_init(linevec, sizeof(char));
    } else {
        linevec->data = line;
        linevec->capacity = alloc_size;
        linevec->length = 0;
        linevec->elem_size = sizeof(char);
    }
}

MY_LOCAL ssize_t my_getdelim_read(
    my_vec_t *line, char delim, my_iostream_t *stream)
{
    char c;
    ssize_t count = 0;

    while (my_fread(&c, sizeof(char), 1, stream) == 1) {
        ++count;
        if (my_vec_push(line, &c) != MY_VEC_OK)
            return -1;
        if (c == delim)
            return count;
    }
    if (my_feof(stream))
        return count;
    return -1;
}

MY_LOCAL ssize_t my_getdelim_add_null_byte(my_vec_t *line, ssize_t ret)
{
    char zero = '\0';

    if (ret < 0 || my_vec_push(line, &zero) != MY_VEC_OK)
        return -1;
    return ret;
}

MY_IO_API ssize_t my_getdelim(
    char **line, size_t *alloc_size, char delim, my_iostream_t *stream)
{
    my_vec_t linevec;
    ssize_t ret = -1;

    if (line == NULL || alloc_size == NULL)
        return -1;
    my_getdelim_alloc_vec(&linevec, *line, *alloc_size);
    if (!my_feof(stream)) {
        ret = my_getdelim_read(&linevec, delim, stream);
        ret = my_getdelim_add_null_byte(&linevec, ret);
    }
    *alloc_size = linevec.capacity;
    *line = linevec.data;
    return ret;
}
