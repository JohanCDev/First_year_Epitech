/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Initializes a stream
*/

#include "libmy/io.h"

#include "iostream.h"

static const p_my_iostream_vtable_t UNIX_INPUT_VTABLE = {
    .read = P_MY_FREAD_UNIX,
    .flush = (p_my_fflush_impl_t)p_my_fflush_unix,
    .destroy = (p_my_ffree_impl_t)p_my_ffree_unix,
    .eof = (p_my_feof_impl_t)p_my_feof_unix,
    .set_threshold = (p_my_fset_threshold_impl_t)p_my_fset_threshold_unix,
    .set_buffer = (p_my_fset_buf_impl_t)p_my_fset_buffer_unix,
    .get_buffer = (p_my_fget_buf_impl_t)p_my_fget_buffer_unix,
    .close = P_MY_FCLOSE_UNIX,
};

static const p_my_iostream_vtable_t MEMORY_INPUT_VTABLE = {
    .read = (p_my_fread_impl_t)p_my_fread_memory,
    .eof = (p_my_feof_impl_t)p_my_feof_memory,
    .get_buffer = (p_my_fget_buf_impl_t)p_my_fget_buffer_memory,
};

static const p_my_iostream_vtable_t UNIX_OUTPUT_VTABLE = {
    .write = (p_my_fwrite_impl_t)p_my_fwrite_unix,
    .flush = (p_my_fflush_impl_t)p_my_fflush_unix,
    .destroy = (p_my_ffree_impl_t)p_my_ffree_unix,
    .eof = (p_my_feof_impl_t)p_my_feof_unix,
    .set_threshold = (p_my_fset_threshold_impl_t)p_my_fset_threshold_unix,
    .set_buffer = (p_my_fset_buf_impl_t)p_my_fset_buffer_unix,
    .get_buffer = (p_my_fget_buf_impl_t)p_my_fget_buffer_unix,
    .close = P_MY_FCLOSE_UNIX,
};

static const p_my_iostream_vtable_t MEMORY_OUTPUT_VTABLE = {
    .write = (p_my_fwrite_impl_t)p_my_fwrite_memory,
    .eof = (p_my_feof_impl_t)p_my_feof_memory,
    .get_buffer = (p_my_fget_buf_impl_t)p_my_fget_buffer_memory,
};

MY_IO_API int my_finit_input_fd(int fd, my_iostream_t *stream)
{
    p_my_iostream_unix_t *input = &(stream->unix_stream);

    input->vtable = &UNIX_INPUT_VTABLE;
    input->fd = fd;
    input->is_eof = 0;
    input->buf = NULL;
    input->buf_cap = 0;
    input->buf_len = 0;
    input->threshold = MY_DEFAULT_FLUSH_THRESHOLD;
    input->free_buf = NULL;
    return 0;
}

MY_IO_API int my_finit_input_memory(
    void const *ptr, size_t len, my_iostream_t *stream)
{
    p_my_iostream_memory_t *input = &(stream->memory_stream);

    input->vtable = &MEMORY_INPUT_VTABLE;
    input->buf = (unsigned char *)ptr;
    input->count = 0;
    input->limit = len;
    return 0;
}

MY_IO_API int my_finit_output_fd(int fd, my_iostream_t *stream)
{
    p_my_iostream_unix_t *output = &(stream->unix_stream);

    output->vtable = &UNIX_OUTPUT_VTABLE;
    output->fd = fd;
    output->is_eof = 0;
    output->buf = NULL;
    output->buf_cap = 0;
    output->buf_len = 0;
    output->threshold = MY_DEFAULT_FLUSH_THRESHOLD;
    output->free_buf = NULL;
    return 0;
}

MY_IO_API int my_finit_output_memory(
    void *ptr, size_t limit, my_iostream_t *stream)
{
    p_my_iostream_memory_t *output = &(stream->memory_stream);

    output->vtable = &MEMORY_OUTPUT_VTABLE;
    output->buf = (unsigned char *)ptr;
    output->count = 0;
    output->limit = limit;
    return 0;
}
