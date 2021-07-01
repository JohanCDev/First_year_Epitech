/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** keybinds
*/

#ifndef KEYBINDS_H_
#define KEYBINDS_H_

#include <libmy/collections/vec.h>
#include <libmy/io.h>
#include <sys/types.h>
#include <libmy/collections/hash_map.h>

struct sh_line_edit;

typedef int (*keybind_t)(
    struct sh_line_edit *, my_vec_t *, my_iostream_t *, char *);
int sh_exec_keybind(struct sh_line_edit *line_edit, my_vec_t *line,
    my_iostream_t *stream, char *c);

///
/// @brief Insert the char c in the char * vector line at the position
/// line_edit->pos
///
/// @param line_edit The line_edit struct to keep the position of the cursor.
/// @param line The line vector, a char * vector.
/// @param stream The stream from which the char was read. Not used here.
/// @param c A pointer to the char that must be inserted.
/// @return int
///
int sh_keybind_self_insert(struct sh_line_edit *line_edit, my_vec_t *line,
    my_iostream_t *stream, char *c);

///
/// @brief Similar to sh_keybind_self_insert but instead of inserting a char,
/// it removes the one at the pos line_edit->pos
///
/// @param line_edit The line_edit struct to keep the position of the cursor.
/// @param line The line vector, a char * vector.
/// @param stream The stream from which the char was read. Not used here.
/// @param c A pointer to the char which raised this call. Not used here.
/// @return int
///
int sh_keybind_delete(struct sh_line_edit *line_edit, my_vec_t *line,
    my_iostream_t *stream, char *c);

///
/// @brief Move the cursor to the left, decrement line_edit->pos
///
/// @param line_edit The line_edit struct to keep the position of the cursor.
/// @param line The line vector, a char * vector.
/// @param stream The stream from which the char was read. Not used here.
/// @param c A pointer to the char which raised this call. Not used here.
/// @return int
///
int sh_keybind_move_left(struct sh_line_edit *line_edit, my_vec_t *line,
    my_iostream_t *stream, char *c);

///
/// @brief Move the cursor to the right, increment line_edit->pos
///
/// @param line_edit The line_edit struct to keep the position of the cursor.
/// @param line The line vector, a char * vector.
/// @param stream The stream from which the char was read. Not used here.
/// @param c A pointer to the char which raised this call. Not used here.
/// @return int
///
int sh_keybind_move_right(struct sh_line_edit *line_edit, my_vec_t *line,
    my_iostream_t *stream, char *c);

///
/// @brief Raise the end of the stream
///
/// @param line_edit The line_edit struct, to keep the eof bool.
/// @param line The line vector, a char * vector. Not used here.
/// @param stream The stream from which the char was read. Not used here.
/// @param c A pointer to the char which raised the end of the stream. Not used
/// here.
/// @return int
///
int sh_keybind_eof(struct sh_line_edit *line_edit, my_vec_t *line,
    my_iostream_t *stream, char *c);

///
/// @brief Raise the end of the command
///
/// @param line_edit The line_edit struct. Not used here
/// @param line The line vector, a char * vector. A newline is pushed to this
/// vector.
/// @param stream The stream from which the char was read. Not used here.
/// @param c A pointer to the char which raised the end of the stream. Not used
/// here.
/// @return int
///
int sh_keybind_send_cmd(struct sh_line_edit *line_edit, my_vec_t *line,
    my_iostream_t *stream, char *c);

///
/// @brief Start an escape sequence.
///
/// @param line_edit The line_edit struct. Send to the next keybind.
/// @param line The line vector, a char * vector. A newline is pushed to this
/// vector. Send to the next keybind.
/// @param stream The stream from which the char was read. Send to the next
/// keybind to read the next char from the sequence.
/// @param c A pointer to the char which raised the end of the stream. Send to
/// the next keybind. here.
/// @return int
///
int sh_keybind_escape(struct sh_line_edit *line_edit, my_vec_t *line,
    my_iostream_t *stream, char *c);

///
/// @brief Set the cursor at the beginning of the line
///
/// @param line_edit The line_edit struct, to keep track of the cursor.
/// @param line The line vector, a char * vector. Not used here.
/// @param stream The stream from which the char was read. Not used here.
/// @param c  A pointer to the char which raised this call. Not used here.
/// @return int
///
int sh_keybind_line_start(struct sh_line_edit *line_edit, my_vec_t *line,
    my_iostream_t *stream, char *c);

///
/// @brief Set the cursor at the end of the line.
///
/// @param line_edit The line_edit struct, to keep track of the cursor.
/// @param line The line vector, a char * vector. Not used here.
/// @param stream The stream from which the char was read. Not used here.
/// @param c  A pointer to the char which raised this call. Not used here.
/// @return int
///
int sh_keybind_line_end(struct sh_line_edit *line_edit, my_vec_t *line,
    my_iostream_t *stream, char *c);

///
/// @brief Clear the characters before the cursor and set the cursor position
/// at the beginning of the line.
///
/// @param line_edit The line_edit struct, to keep track of the cursor.
/// @param line The line vector, a char * vector. Will be part cleared.
/// @param stream The stream from which the char was read. Not used here.
/// @param c A pointer to the char which raised this call. Not used here.
/// @return int
///
int sh_keybind_line_kill_before_cursor(struct sh_line_edit *line_edit,
    my_vec_t *line, my_iostream_t *stream, char *c);

///
/// @brief Clear the characters after the cursor.
///
/// @param line_edit The line_edit struct, to keep track of the cursor.
/// @param line The line vector, a char * vector. Will be part cleared.
/// @param stream The stream from which the char was read. Not used here.
/// @param c A pointer to the char which raised this call. Not used here.
/// @return int
///
int sh_keybind_line_kill_after_cursor(struct sh_line_edit *line_edit,
    my_vec_t *line, my_iostream_t *stream, char *c);

///
/// @brief Clear the line and set the cursor position at the beginning of the
/// line
///
/// @param line_edit The line_edit struct, to keep track of the cursor.
/// @param line The line vector, a char * vector. Will be cleared.
/// @param stream The stream from which the char was read. Not used here.
/// @param c A pointer to the char which raised this call. Not used here.
/// @return int
///
int sh_keybind_line_kill(struct sh_line_edit *line_edit, my_vec_t *line,
    my_iostream_t *stream, char *c);

///
/// @brief Clear all the screen except the current line
///
/// @param line_edit The line_edit struct.
/// @param line The line vector, a char * vector.
/// @param stream The stream from which the char was read. Not used here.
/// @param c A pointer to the char which raised this call. Not used here.
/// @return int
///
int sh_keybind_clear_screen(struct sh_line_edit *line_edit, my_vec_t *line,
    my_iostream_t *stream, char *c);

///
/// @brief Delete the first word found after the cursor.
///
/// @param line_edit The line_edit struct.
/// @param line The line vector, a char * vector.
/// @param stream The stream from which the char was read. Not used here.
/// @param c A pointer to the char which raised this call. Not used here.
/// @return int
///
int sh_keybind_delete_next_word(struct sh_line_edit *line_edit, my_vec_t *line,
    my_iostream_t *stream, char *c);

///
/// @brief Delete the first word found before the cursor.
///
/// @param line_edit The line_edit struct.
/// @param line The line vector, a char * vector.
/// @param stream The stream from which the char was read. Not used here.
/// @param c A pointer to the char which raised this call. Not used here.
/// @return int
///
int sh_keybind_delete_backward_word(struct sh_line_edit *line_edit,
    my_vec_t *line, my_iostream_t *stream, char *c);

///
/// @brief Move the cursor to the beginning of the last word.
///
/// @param line_edit The line_edit struct.
/// @param line The line vector, a char * vector.
/// @param stream The stream from which the char was read. Not used here.
/// @param c A pointer to the char which raised this call. Not used here.
/// @return int
///
int sh_keybind_backward_word(struct sh_line_edit *line_edit, my_vec_t *line,
    my_iostream_t *stream, char *c);

///
/// @brief Move the cursor to the end of the next word.
///
/// @param line_edit The line_edit struct.
/// @param line The line vector, a char * vector.
/// @param stream The stream from which the char was read. Not used here.
/// @param c A pointer to the char which raised this call. Not used here.
/// @return int
///
int sh_keybind_forward_word(struct sh_line_edit *line_edit, my_vec_t *line,
    my_iostream_t *stream, char *c);

///
/// @brief Capitalize the first word seen after the cursor (start at the cursor
/// position) and move the cursor at the end of this word
///
/// @param line_edit The line_edit struct.
/// @param line The line vector, a char * vector.
/// @param stream The stream from which the char was read. Not used here.
/// @param c A pointer to the char which raised this call. Not used here.
/// @return int
///
int sh_keybind_capitalize_word(struct sh_line_edit *line_edit, my_vec_t *line,
    my_iostream_t *stream, char *c);

///
/// @brief Set the first word seen after the cursor in upcases(start at the
/// cursor position) and move the cursor at the end of this word
///
/// @param line_edit The line_edit struct.
/// @param line The line vector, a char * vector.
/// @param stream The stream from which the char was read. Not used here.
/// @param c A pointer to the char which raised this call. Not used here.
/// @return int
///
int sh_keybind_upcase_word(struct sh_line_edit *line_edit, my_vec_t *line,
    my_iostream_t *stream, char *c);

///
/// @brief Set the first word seen after the cursor in downcases(start at the
/// cursor position) and move the cursor at the end of this word
///
/// @param line_edit The line_edit struct.
/// @param line The line vector, a char * vector.
/// @param stream The stream from which the char was read. Not used here.
/// @param c A pointer to the char which raised this call. Not used here.
/// @return int
///
int sh_keybind_downcase_word(struct sh_line_edit *line_edit, my_vec_t *line,
    my_iostream_t *stream, char *c);

///
/// @brief Complete the current word the cursor is on.
///
/// @param line_edit The line_edit struct.
/// @param line The line vector, a char * vector.
/// @param stream The stream from which the char was read. Not used here.
/// @param c A pointer to the char which raised this call. Not used here.
/// @return int
///
int sh_keybind_complete(struct sh_line_edit *line_edit, my_vec_t *line,
    my_iostream_t *stream, char *c);

///
/// @brief Complete the current word the cursor is on if the program run in a
/// tty, else just print the char @c c.
///
/// @param line_edit The line_edit struct.
/// @param line The line vector, a char * vector.
/// @param stream The stream from which the char was read. Not used here.
/// @param c A pointer to the char which raised this call. Not used here.
/// @return int
///
int sh_keybind_tty_complete(struct sh_line_edit *line_edit, my_vec_t *line,
    my_iostream_t *stream, char *c);

///
/// @brief Does nothing, used for undefined keybinds.
///
/// @param line_edit The line_edit struct. Not used here.
/// @param line The line vector, a char * vector. Not used here.
/// @param stream The stream from which the char was read. Not used here.
/// @param c A pointer to the char which raised this call. Not used
/// here.
/// @return int
///
int sh_keybind_empty(struct sh_line_edit *line_edit, my_vec_t *line,
    my_iostream_t *stream, char *c);

///
/// @brief Keybinds for arrows
///
/// @param line_edit The line_edit struct.
/// @param line The line vector, a char * vector.
/// @param stream The stream from which the char was read.
/// @param c A pointer to the char which raised this call. A = up, B = down, D
/// = Left, C = Right
/// @return int
///
int sh_keybind_arrow(struct sh_line_edit *line_edit, my_vec_t *line,
    my_iostream_t *stream, char *c);

#endif /* !KEYBINDS_H_ */
