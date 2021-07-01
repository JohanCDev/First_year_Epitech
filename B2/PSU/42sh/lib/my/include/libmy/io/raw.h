/*
** EPITECH PROJECT, 2020
** LibMy - io module
** File description:
** Raw IO functions.
*/

/// @file
/// Raw IO functions.
///
/// @since 0.3.2

#ifndef __LIBMY_IO_RAW__
#define __LIBMY_IO_RAW__

#include "libmy/io/config.h"

MY_API_BEGIN

/// Puts a single character into the standard output.
///
/// @param c The byte to display.
///
/// @since 0.1.0
MY_IO_API void my_putchar(char c);

/// Puts a single character into the specified file descriptor.
///
/// @param fd The file descriptor.
/// @param c  The byte to display.
///
/// @since 0.1.0
MY_IO_API void my_putchar_fd(int fd, char c);

/// Puts an integer into the standard output.
///
/// @param nb The number to display.
///
/// @returns Always 0.
/// @since 0.1.0
MY_IO_API int my_put_nbr(int nb);

/// Puts an integer into the specified file descriptor.
///
/// @param fd The file descriptor.
/// @param nb The number to display.
///
/// @returns Always 0.
/// @since 0.1.0
MY_IO_API int my_put_nbr_fd(int fd, int nb);

/// Puts an unsigned int into the standard output.
///
/// @param nb The number to display.
///
/// @returns Always 0.
/// @since 0.1.0
MY_IO_API int my_putuint(unsigned int nb);

/// Puts an unsigned int into the specified file descriptor.
///
/// @param fd The file descriptor.
/// @param nb The number to display.
///
/// @returns Always 0.
/// @since 0.1.0
MY_IO_API int my_putuint_fd(int fd, unsigned int nb);

/// Puts a null-terminated string into the standard output.
///
/// @param str The string to display, must end with a null character.
///            @b Cannot be @c NULL.
///
/// @returns Always 0.
/// @since 0.1.0
MY_IO_API int my_putstr(char const *str);

/// Puts a null-terminated string into the specified file descriptor.
///
/// @param fd  The file descriptor.
/// @param str The string to display, must end with a null character.
///            @b Cannot be @c NULL.
///
/// @returns Always 0.
/// @since 0.1.0
MY_IO_API int my_putstr_fd(int fd, char const *str);

/// Displays the memory pointed to by @c str in a pretty format.
///
/// @param str  The memory to display.
/// @param size The number of bytes to display.
///
/// @returns -1 if @c str is @c NULL of <tt>size &lt; 0</tt>, 0 otherwise.
/// @since 0.1.0
MY_IO_API int my_showmem(char const *str, int size);

/// Puts a null-terminated string into the standard output,
/// displaying the non-printable characters by a backslash followed by
/// their hexadecimal values.
///
/// @param str The string to display, must end with a null character.
///
/// @returns -1 if @c str is @c NULL, 0 otherwise.
/// @since 0.1.0
MY_IO_API int my_showstr(char const *str);

/// Puts an null-terminated array of strings into the standard output,
/// displaying each string in their own line.
///
/// @param tab A null-terminated array of strings.
///            The contained strings must end with a null character.
///
/// @return -1 is @c tab is @c NULL, 0 otherwise.
/// @since 0.1.0
MY_IO_API int my_show_word_array(char *const *tab);

/// Puts a null-terminated string into the standard output,
/// followed by a newline.
///
/// @param str The string to display, must end with a null character.
///            @b Cannot be @c NULL.
///
/// @returns Always 0.
/// @since 0.1.0
MY_INLINE void my_putendl(char const *str)
{
    my_putstr(str);
    my_putchar('\n');
}

/// Puts a null-terminated string into the specified file descriptor,
/// followed by a newline.
///
/// @param fd  The file descriptor.
/// @param str The string to display, must end with a null character.
///            @b Cannot be @c NULL.
///
/// @returns Always 0.
/// @since 0.1.0
MY_INLINE void my_putendl_fd(int fd, char const *str)
{
    my_putstr_fd(fd, str);
    my_putchar_fd(fd, '\n');
}

MY_API_END

#endif // !defined(__LIBMY_IO_RAW__)
