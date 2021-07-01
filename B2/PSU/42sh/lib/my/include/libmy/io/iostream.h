/*
** EPITECH PROJECT, 2021
** LibMy - io module
** File description:
** IO stream definitions and utilities
*/

/// @file
/// IO stream definitions and utilities.
///
/// @since 0.3.2

#ifndef __LIBMY_MEMORY_IOSTREAM_H__
#define __LIBMY_MEMORY_IOSTREAM_H__

#include "libmy/io/config.h"

MY_API_BEGIN

#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

#include "libmy/internal/iostream.h"

/// An IO stream.
///
/// @since 0.2.0
typedef p_my_iostream_t my_iostream_t;

/// The default percentage at which streams will auto-flush.
///
/// @since 0.1.0
#define MY_DEFAULT_FLUSH_THRESHOLD ((float)1.0)

/// The maximum number of characters that will be read at one time.
///
/// @since 0.1.0
#define MY_READ_SIZE ((size_t)1024)

/// The maximum number of characters that will be written at one time.
///
/// @since 0.1.0
#define MY_WRITE_SIZE ((size_t)1024)

/// Initializes an file input stream with a file descriptor.
///
/// @param fd     The file descritor to read from.
/// @param stream The input stream to initialize.
///
/// @returns 0 if successful.
/// @since 0.2.0
MY_IO_API int my_finit_input_fd(int fd, my_iostream_t *stream);

/// Initializes a memory input stream with a pointer to a memory location.
///
/// @param ptr    The memory to read from.
/// @param len    The length of the memory pointed by @c ptr.
/// @param stream The input stream to initialize.
///
/// @returns 0 if successful.
/// @since 0.2.0
MY_IO_API int my_finit_input_memory(
    void const *ptr, size_t len, my_iostream_t *stream);

/// Initializes an file output stream with a file descriptor.
///
/// @param fd     The file descritor to write to.
/// @param stream The output stream to initialize.
///
/// @returns 0 if successful.
/// @since 0.2.0
MY_IO_API int my_finit_output_fd(int fd, my_iostream_t *stream);

/// Initializes an memory output stream with a pointer to a memory location.
///
/// @param ptr    The memory to write to.
/// @param limit  The maximum number of bytes that can by written to @c ptr.
/// @param stream The output stream to initialize.
///
/// @returns 0 if successful.
/// @since 0.2.0
MY_IO_API int my_finit_output_memory(
    void *ptr, size_t limit, my_iostream_t *stream);

/// Initializes the buffer of a buffered IO stream.
///
/// @param buf      The buffer this stream will use, the pointed memory must
///                 live as long as the stream. If @c buf is @c NULL,
///                 then this function will never succeed.
/// @param buf_cap  The capacity of the buffer, must @b not be zero.
/// @param free_buf A function that frees the buffer, can be @c NULL.
/// @param stream   The stream to initialize.
///
/// @returns 0 if successful.
/// @since 0.2.0
MY_IO_API int my_fset_buffer(void *buf, size_t buf_cap,
    void (*free_buf)(void *), my_iostream_t *stream);

/// Changes the auto-flush threshold in the given string.
/// If this function is not called the default threshold is
/// @ref MY_DEFAULT_FLUSH_THRESHOLD.
///
/// @param threshold The auto-flush threshold.
/// @param stream    The IO stream.
///
/// @returns 0, if successful.
/// @since 0.2.0
MY_IO_API int my_fset_flush_threshold(float threshold, my_iostream_t *stream);

/// Initializes the standard input IO stream.
///
/// @param buf      The buffer this stream will use, the pointed memory must
///                 live as long as the stream.
/// @param buf_cap  The capacity of the buffer, must @b not be zero.
/// @param free_buf A function that frees the buffer, can be @c NULL.
///
/// @returns 0, if successful and buf is not @c NULL.
/// @since 0.1.0
MY_IO_API int my_init_stdin(
    unsigned char *buf, size_t buf_cap, void (*free_buf)(void *));

/// Initializes the standard output IO stream.
///
/// @param buf      The buffer this stream will use, the pointed memory must
///                 live as long as the stream.
/// @param buf_cap  The capacity of the buffer, must @b not be zero.
/// @param free_buf A function that frees the buffer, can be @c NULL.
///
/// @since 0.1.0
MY_IO_API int my_init_stdout(
    unsigned char *buf, size_t buf_cap, void (*free_buf)(void *));

/// Initializes the standard error IO stream.
///
/// @param buf      The buffer this stream will use, the pointed memory must
///                 live as long as the stream.
/// @param buf_cap  The capacity of the buffer, must @b not be zero.
/// @param free_buf A function that frees the buffer, can be @c NULL.
///
/// @since 0.1.0
MY_IO_API int my_init_stderr(
    unsigned char *buf, size_t buf_cap, void (*free_buf)(void *));

/// Flushes the given stream and calls its @c free_buf function.
///
/// @param stream The stream
///
/// @since 0.1.0
MY_IO_API void my_ffree(my_iostream_t *stream);

/// Flushes the standard input stream and calls its @c free_buf function.
///
/// @since 0.1.0
MY_IO_API void my_free_stdin(void);

/// Flushes the standard output stream and calls its @c free_buf function.
///
/// @since 0.1.0
MY_IO_API void my_free_stdout(void);

/// Flushes the standard error stream and calls its @c free_buf function.
///
/// @since 0.1.0
MY_IO_API void my_free_stderr(void);

/// Retrieves the stdin IO stream.
/// The stream @b must be initialized with @ref my_init_stdin.
///
/// @returns The standard input IO stream.
/// @since 0.1.0
MY_IO_API my_iostream_t *my_get_stdin(void);

/// Retrieves the stdout IO stream.
/// The stream @b must be initialized with @ref my_init_stdout.
///
/// @returns The standard output IO stream.
/// @since 0.1.0
MY_IO_API my_iostream_t *my_get_stdout(void);

/// Retrieves the stderr IO stream.
/// The stream @b must be initialized with @ref my_init_stderr.
///
/// @returns The standard error IO stream.
/// @since 0.1.0
MY_IO_API my_iostream_t *my_get_stderr(void);

/// Retrives the void input stream instance.
/// The void input stream does not need to be initialized before use.
///
/// @returns The void stream instance.
/// @since 0.2.0
MY_IO_API my_iostream_t *my_get_void_input(void);

/// Retrives the void output stream instance.
/// The void output stream does not need to be initialized before use.
///
/// @returns The void stream instance.
/// @since 0.2.0
MY_IO_API my_iostream_t *my_get_void_output(void);

/// The standard input IO stream
/// The stream @b must be initialized with @ref my_init_stdin.
///
/// @since 0.1.0
#define MY_STDIN (my_get_stdin())

/// The standard output IO stream
/// The stream @b must be initialized with @ref my_init_stdout.
///
/// @since 0.1.0
#define MY_STDOUT (my_get_stdout())

/// The standard error IO stream
/// The stream @b must be initialized with @ref my_init_stderr.
///
/// @since 0.1.0
#define MY_STDERR (my_get_stderr())

/// The void input stream instance
///
/// @since 0.2.0
#define MY_VOID_IN (my_get_void_input())

/// The void output stream instance
///
/// @since 0.2.0
#define MY_VOID_OUT (my_get_void_output())

#if LIBMY_ALLOW_OPEN
/// Opens a file.
///
/// @param path
/// @param mode
/// @param stream
///
/// @returns 0, if successful.
/// @since 0.3.2
MY_IO_API int my_fopen(
    const char *path, const char *mode, my_iostream_t *stream);
#endif

/// Reads @c nmemb items of data, each @c size bytes long, to the
/// passed stream, obtaitning them from the location given by @c ptr.
///
/// @param ptr    The data to write.
/// @param size   The size of one element.
/// @param nmemb  The number of elements to write.
/// @param stream The IO stream.
///
/// @returns The number of items written, and/or zero if an error occurs.
/// @since 0.1.0
MY_IO_API size_t my_fwrite(
    const void *ptr, size_t size, size_t nmemb, my_iostream_t *stream);

/// Tests if the stream has reached end-of-file.
///
/// @param stream The stream to test.
///
/// @returns Whether the stream has reached end-of-file.
/// @since 0.1.0
MY_IO_API int my_feof(my_iostream_t *stream);

/// Tests whether the given stream can be read from.
///
/// @param stream The stream to test.
///
/// @returns Can this stream be read from?
/// @since 0.2.0
MY_IO_API int my_is_input_stream(my_iostream_t const *stream);

/// Tests whether the given stream can be written to.
///
/// @param stream The stream to test.
///
/// @returns Can this stream be written to?
/// @since 0.2.0
MY_IO_API int my_is_output_stream(my_iostream_t const *stream);

/// Returns the current buffer used by this IO stream and
/// writes its size to @c size.
/// For memory streams, this function will always return
/// the same pointer that was passed during their creation.
///
/// @note the contents of the returned pointer are undefined if
/// any function is called with this stream as a parameter,
/// with the exception of @ref my_ffree which alter the buffer pointer
/// only is a freeing function pointer was passed during the initialization
/// of the stream.
///
/// @param[out] size Where the size of the buffer is written.
/// @param stream    The stream.
///
/// @returns A pointer to the stream's buffer, or @c NULL if the stream
///          does not have a buffer.
MY_IO_API void *my_fget_buffer(size_t *size, my_iostream_t const *stream);

/// Reads @c nmemb items of data, each @c size bytes long, from the
/// passed stream, storing them at the location given by @c ptr.
///
/// @param[out] ptr Where the read elements will be written to.
/// @param size     The size of one element.
/// @param nmemb    The number of elements to read.
/// @param stream   The IO stream.
///
/// @returns The number of items read, and/or zero if an error occurs.
///          Check @ref my_feof to differenciate between errors
///          and normal end of file.
/// @since 0.1.0
MY_IO_API size_t my_fread(
    void *ptr, size_t size, size_t nmemb, my_iostream_t *stream);

#if LIBMY_ALLOW_MALLOC_FREE
/// Reads at most @c count bytes from @c stream into an allocated string.
///
/// @param count           The maximum number of bytes to read.
/// @param[out] output_len The size of the returned string,
///                        set to 0 in case of error.
/// @param stream          The input stream.
///
/// @returns The read bytes into an allocated string,
///          or @c NULL in case of error.
/// @since 0.1.0
MY_IO_API char *my_fread_to_string(
    size_t count, size_t *output_len, my_iostream_t *stream);
#endif

/// Closes a IO stream.
///
/// @param stream The IO stream.
///
/// @returns 0, if successful.
/// @since 0.1.0
MY_IO_API int my_fclose(my_iostream_t *stream);

/// Clears a stream's buffer.
/// For output streams, my_fflush forces a write of all the buffered data.
/// For input streams, my_fflush discards any buffered data.
///
/// @param stream The stream.
///
/// @returns 0, if successful.
/// @since 0.1.0
MY_IO_API int my_fflush(my_iostream_t *stream);

/// Flushes the standard input, see @ref my_fflush for more details.
///
/// @returns 0, if successful.
/// @since 0.1.0
MY_IO_API int my_flush_stdin(void);

/// Flushes the standard output, see @ref my_fflush for more details.
///
/// @returns 0, if successful.
/// @since 0.1.0
MY_IO_API int my_flush_stdout(void);

/// Flushes the standard error, see @ref my_fflush for more details.
///
/// @returns 0, if successful.
/// @since 0.1.0
MY_IO_API int my_flush_stderr(void);

/// Puts a null-terminated string into the speicified output stream.
///
/// @param str    The string to display, must end with a null character.
///               @b Cannot be @c NULL.
/// @param stream The IO stream.
///
/// @returns 0, if successful.
/// @since 0.1.0
MY_IO_API int my_fputs(char const *str, my_iostream_t *stream);

/// Puts a null-terminated string into the speicified output stream,
/// followed by a newline.
///
/// @param str    The string to display, must end with a null character.
///               @b Cannot be @c NULL.
/// @param stream The IO stream.
///
/// @returns 0, if successful.
/// @since 0.1.0
MY_IO_API int my_fputs_endl(char const *str, my_iostream_t *stream);

/// Puts a null-terminated string into the standard output.
///
/// @param str    The string to display, must end with a null character.
///               @b Cannot be @c NULL.
///
/// @returns 0, if successful.
/// @since 0.1.0
MY_IO_API int my_puts(char const *str);

/// Puts a null-terminated string into the standard output,
/// followed by a newline.
///
/// @param str    The string to display, must end with a null character.
///               @b Cannot be @c NULL.
///
/// @returns 0, if successful.
/// @since 0.1.0
MY_IO_API int my_puts_endl(char const *str);

/// Puts a null-terminated string into the standard error.
///
/// @param str    The string to display, must end with a null character.
///               @b Cannot be @c NULL.
///
/// @returns 0, if successful.
/// @since 0.1.0
MY_IO_API int my_eputs(char const *str);

/// Puts a null-terminated string into the standard error,
/// followed by a newline
///
/// @param str    The string to display, must end with a null character.
///               @b Cannot be @c NULL.
///
/// @returns 0, if successful.
/// @since 0.1.0
MY_IO_API int my_eputs_endl(char const *str);

/// Puts a character into the specified output stream.
///
/// @param c      The character to put.
/// @param stream The IO stream.
///
/// @returns 0, if successful.
/// @since 0.1.0
MY_IO_API int my_fputc(char c, my_iostream_t *stream);

/// Puts a character into the standard output.
///
/// @param c The chracter to put.
///
/// @returns 0, if successful.
/// @since 0.1.0
MY_IO_API int my_putc(char c);

/// Puts a character into the standard error.
///
/// @param c The chracter to put.
///
/// @returns 0, if successful.
/// @since 0.1.0
MY_IO_API int my_eputc(char c);

/// Puts a character into the specified output stream, @c count times.
///
/// @param c      The character to put.
/// @param count  The number of characters to print.
/// @param stream The IO stream.
///
/// @returns 0, if successful.
/// @since 0.2.0
MY_IO_API int my_frputc(char c, size_t count, my_iostream_t *stream);

/// Puts a character into the standard output, @c count times.
///
/// @param c      The character to put.
/// @param count  The number of characters to print.
///
/// @returns 0, if successful.
/// @since 0.2.0
MY_IO_API int my_rputc(char c, size_t count);

/// Puts a character into the standard error, @c count times.
///
/// @param c      The character to put.
/// @param count  The number of characters to print.
///
/// @returns 0, if successful.
/// @since 0.2.0
MY_IO_API int my_erputc(char c, size_t count);

/// Puts an int into the specified stream.
///
/// @param nb     The number to display.
/// @param stream The IO stream.
///
/// @returns The number of bytes written to @c stream,
///          or 0 if an error occurred.
/// @since 0.1.0
MY_IO_API size_t my_fputint(int nb, my_iostream_t *stream);

/// Puts an intmax_t into the specified stream, with the given base
/// and radix.
///
/// @param nb     The number to display.
/// @param base   The base to use.
/// @param radix  The size of the base.
/// @param stream The IO stream.
///
/// @returns The number of bytes written to @c stream,
///          or 0 if an error occurred.
/// @since 0.2.0
MY_IO_API size_t my_fputintmax_t_base(
    intmax_t nb, char const *base, size_t radix, my_iostream_t *stream);

/// Puts an unsigned int into the specified stream.
///
/// @param nb The number to display.
/// @param stream The IO stream.
///
/// @returns The number of bytes written to @c stream,
///          or 0 if an error occurred.
/// @since 0.1.0
MY_IO_API size_t my_fputuint(unsigned int nb, my_iostream_t *stream);

/// Puts an uintmax_t into the specified stream, with the given base
/// and radix.
///
/// @param nb     The number to display.
/// @param base   The base to use.
/// @param radix  The size of the base.
/// @param stream The IO stream.
///
/// @returns The number of bytes written to @c stream,
///          or 0 if an error occurred.
/// @since 0.2.0
MY_IO_API size_t my_fputuintmax_t_base(
    uintmax_t nb, char const *base, size_t radix, my_iostream_t *stream);

/// Reads the next character from @c stream.
///
/// @param stream The input stream.
///
/// @returns The next character as an unsigned char cast to an int, or -1 on
/// end of file or error.
MY_INLINE int my_fgetc(my_iostream_t *stream)
{
    unsigned char c;

    if (my_fread(&c, sizeof(c), 1, stream) == 1)
        return (int)c;
    return -1;
}

#if LIBMY_ALLOW_MALLOC_FREE
/// Reads an entire line from @c stream, using @c delim as a delimiter and
/// stores the read line into <tt>*line</tt>.
///
/// If <tt>*line</tt> is set to @c NULL and <tt>*alloc_size</tt> is set to 0
/// before the call, the function will allocate a buffer big enough to store
/// the line. This buffer should be freed by the caller even if the call
/// failed.
///
/// <tt>*line</tt> can contains a pointer to a malloc-allocated buffer
/// <tt>*n</tt> in size, if the buffer is not large enough, the function
/// resizes it with @ref my_realloc and updates <tt>*line</tt> and <tt>*n</tt>.
///
/// The buffer is null-terminated and includes the delimiter character.
///
/// @param line A pointer the the line buffer, cannot be @c NULL.
/// @param alloc_size A pointer to the size of the allocation.
/// @param delim The end-of-line delimiter
/// @param stream The input stream.
///
/// @returns The number of bytes read from @c stream, or -1 on IO error or
/// end-of-file. Use @ref my_feof to distinguish between errors and normal end
/// of file.
MY_IO_API ssize_t my_getdelim(
    char **line, size_t *alloc_size, char delim, my_iostream_t *stream);

/// Reads an entire line from @c stream, using <tt>'\n'</tt> as a delimiter and
/// stores the read line into <tt>*line</tt>.
///
/// If <tt>*line</tt> is set to @c NULL and <tt>*alloc_size</tt> is set to 0
/// before the call, the function will allocate a buffer big enough to store
/// the line. This buffer should be freed by the caller even if the call
/// failed.
///
/// <tt>*line</tt> can contains a pointer to a malloc-allocated buffer
/// <tt>*n</tt> in size, if the buffer is not large enough, the function
/// resizes it with @ref my_realloc and updates <tt>*line</tt> and <tt>*n</tt>.
///
/// The buffer is null-terminated and includes the newline character.
///
/// Use @ref my_getdelim for reading lines with custom delimiters.
///
/// @param line A pointer the the line buffer, cannot be @c NULL.
/// @param alloc_size A pointer to the size of the allocation.
/// @param stream The input stream.
///
/// @returns The number of bytes read from @c stream, or -1 on IO error or
/// end-of-file. Use @ref my_feof to distinguish between errors and normal end
/// of file.
MY_INLINE ssize_t my_getline(
    char **line, size_t *alloc_size, my_iostream_t *stream)
{
    return my_getdelim(line, alloc_size, '\n', stream);
}
#endif

MY_API_END

#endif // !defined(__LIBMY_MEMORY_IOSTREAM_H__)
