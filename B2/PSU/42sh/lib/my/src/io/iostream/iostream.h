/*
** EPITECH PROJECT, 2020
** LibMy - io module internals
** File description:
** Internals for the IO streams.
*/

#ifndef __LIBMY_IO_IOSTREAM_IOSTREAM_H__
#define __LIBMY_IO_IOSTREAM_IOSTREAM_H__

#include "libmy/internal/iostream.h"

#if LIBMY_ALLOW_READ
MY_LOCAL size_t p_my_fread_unix(
    p_my_iostream_unix_t *input, void *ptr, size_t size, size_t nmemb);
    #define P_MY_FREAD_UNIX ((p_my_fread_impl_t)&p_my_fread_unix)
#else
    #define P_MY_FREAD_UNIX ((p_my_fread_impl_t)NULL)
#endif

MY_LOCAL size_t p_my_fread_memory(
    p_my_iostream_memory_t *input, void *ptr, size_t size, size_t nmemb);
MY_LOCAL size_t p_my_fread_void(
    void *input, void *ptr, size_t size, size_t nmemb);

MY_LOCAL size_t p_my_fwrite_unix(
    p_my_iostream_unix_t *output, const void *ptr, size_t size, size_t nmemb);
MY_LOCAL size_t p_my_fwrite_memory(p_my_iostream_memory_t *output,
    const void *ptr, size_t size, size_t nmemb);
MY_LOCAL size_t p_my_fwrite_void(
    void *output, const void *ptr, size_t size, size_t nmemb);

MY_LOCAL int p_my_fflush_unix(p_my_iostream_unix_t *stream);

MY_LOCAL void p_my_ffree_unix(p_my_iostream_unix_t *stream);

MY_LOCAL int p_my_feof_unix(p_my_iostream_unix_t const *stream);
MY_LOCAL int p_my_feof_memory(p_my_iostream_memory_t const *stream);
MY_LOCAL int p_my_feof_void(void const *stream);

MY_LOCAL int p_my_fset_threshold_unix(
    p_my_iostream_unix_t *stream, float threshold);

MY_LOCAL int p_my_fset_buffer_unix(p_my_iostream_unix_t *stream, void *buf,
    size_t buf_cap, void (*free_buf)(void *));

MY_LOCAL void *p_my_fget_buffer_unix(
    p_my_iostream_unix_t const *stream, size_t *size);
MY_LOCAL void *p_my_fget_buffer_memory(
    p_my_iostream_memory_t const *stream, size_t *size);

#if LIBMY_ALLOW_CLOSE
MY_LOCAL int p_my_fclose_unix(p_my_iostream_unix_t *stream);
    #define P_MY_FCLOSE_UNIX ((p_my_fclose_impl_t)&p_my_fclose_unix)
#else
    #define P_MY_FCLOSE_UNIX ((p_my_fclose_impl_t)NULL)
#endif

#endif // !defined(__LIBMY_IO_IOSTREAM_IOSTREAM_H__)
