/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** User input tokenization
*/

#ifndef __SHELL_INPUT__
#define __SHELL_INPUT__

#include <assert.h>
#include <libmy/collections/vec.h>
#include <stdbool.h>
#include <sys/types.h>

#include "context.h"
#include "error.h"

#define SH_INHIBITOR '\\'

typedef enum sh_token_type {
    SH_TOKEN_SINGLE_STR = 1 << 0,
    SH_TOKEN_DOUBLE_STR = 1 << 1,
    SH_TOKEN_UNQUOTED_STR = 1 << 2,
    SH_TOKEN_ESCAPED_NAME = 1 << 3,
    SH_TOKEN_PIPE = 1 << 4,
    SH_TOKEN_PIPE_PIPE = 1 << 5,
    SH_TOKEN_SEMICOLON = 1 << 6,
    SH_TOKEN_LT = 1 << 7,
    SH_TOKEN_LT_LT = 1 << 8,
    SH_TOKEN_GT = 1 << 9,
    SH_TOKEN_GT_GT = 1 << 10,
    SH_TOKEN_AND = 1 << 11,
    SH_TOKEN_AND_AND = 1 << 12,
    SH_TOKEN_TYPE_COUNT = 1 << 13,
} sh_token_type_t;

/// All the types of tokens used in redirections (execpt pipe)
#define SH_REDIRECT_TOKENS \
    (SH_TOKEN_LT | SH_TOKEN_LT_LT | SH_TOKEN_GT | SH_TOKEN_GT_GT)

#define SH_UNQUOTED_TOKENS (SH_TOKEN_UNQUOTED_STR | SH_TOKEN_ESCAPED_NAME)

#define SH_EXPANSION_TOKENS (SH_TOKEN_DOUBLE_STR | SH_UNQUOTED_TOKENS)

#define SH_STRING_TOKENS \
    (SH_TOKEN_SINGLE_STR | SH_TOKEN_DOUBLE_STR | SH_UNQUOTED_TOKENS)

typedef struct sh_token {
    sh_token_type_t type;
    /// Allocated string representation of this token, only present when
    /// @c type is any in @c SH_STRING_TOKENS.
    char *str;
} sh_token_t;

typedef struct sh_token_stream {
    /// The current line buffer.
    /// Element type: char
    my_vec_t line_buf;
    /// Current tokens buffer.
    /// Element type: sh_token_t;
    my_vec_t tokens;
    size_t line_pos;
} sh_token_stream_t;

void sh_token_stream_init(sh_token_stream_t *stream);
void sh_token_stream_reset(sh_token_stream_t *stream);
void sh_token_stream_drop(sh_token_stream_t *stream);

/// @returns 0 on success, 1 on token error, or -1 on EOL.
int sh_token_parse(
    sh_token_stream_t *stream, sh_ctx_t *ctx, sh_token_t *token);

ssize_t sh_token_stream_push(
    sh_token_stream_t *stream, sh_ctx_t *ctx, size_t token_count);

SH_INLINE ssize_t sh_token_stream_next(
    sh_token_stream_t *stream, sh_ctx_t *ctx, size_t token_count)
{
    sh_token_stream_reset(stream);
    return sh_token_stream_push(stream, ctx, token_count);
}

SH_INLINE bool sh_token_stream_is_eol(sh_token_stream_t const *stream)
{
    assert(stream != NULL);
    return stream->line_pos >= stream->line_buf.length;
}

void sh_drop_token(void *token);

/// Returns the string representation of a token.
///
/// If the token is a string its value is set to @c NULL.
///
/// @returns An allocated string, or @c NULL if allocation failed.
char *sh_token_to_str(sh_token_t *token);

/// Converts the given token to a string token.
///
/// @returns Whether allocation (if needed) succeded.
bool sh_token_into_str(sh_token_t *token);

/// @returns The corresponding string token type for the given token type.
SH_INLINE sh_token_type_t sh_token_type_to_str(sh_token_type_t type)
{
    if (type & SH_STRING_TOKENS)
        return type;
    return SH_TOKEN_SINGLE_STR;
}

/// Is @c c an argument separator character?
///
/// @param c The character to check
///
/// @returns Whether the given character is an argument separator.
SH_INLINE bool sh_is_arg_sep(char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}

SH_INLINE bool sh_is_token_char(char c)
{
    return c == '"' || c == '\'' || c == '|' || c == ';' || c == '<'
        || c == '>' || c == '&';
}

SH_INLINE bool sh_is_arg_quote(char c)
{
    return c == '"' || c == '\'';
}

SH_INLINE bool sh_is_arg_inhibitable(char c)
{
    return (sh_is_arg_quote(c) || sh_is_arg_sep(c));
}

/// Checks if the type of the first token in @c tokens matches @b any of the
/// types given in @c token_types.
///
/// @param token_count The number of tokens in @c tokens.
/// @param tokens An array of tokens of minimum size @c token_size, must be a
/// valid pointer.
/// @param token_types The token types to match, multiple types can be
/// bitwise-or'd.
///
/// @returns Whether the next token's type matches one in @c token_types.
/// returns @c false of token_count == 0.
SH_INLINE bool sh_token_match(
    size_t token_count, sh_token_t const tokens[], sh_token_type_t token_types)
{
    return token_count > 0 && (tokens[0].type & token_types);
}

/// Checks if the type of the first token in @c tokens matches @b none of the
/// types given in @c token_types.
///
/// @param token_count The number of tokens in @c tokens.
/// @param tokens An array of tokens of minimum size @c token_size, must be a
/// valid pointer.
/// @param token_types The token types to match, multiple types can be
/// bitwise-or'd.
///
/// @returns Whether the next token's type matches none in @c token_types.
/// returns @c false of token_count == 0.
SH_INLINE bool sh_token_match_except(
    size_t token_count, sh_token_t const tokens[], sh_token_type_t token_types)
{
    return token_count > 0 && !(tokens[0].type & token_types);
}

/// Removes the next token from the @c tokens pointer if its type matches any
/// in @c token_types.
///
/// Decrements the value of @c token_count and increments the value
/// of @c tokens if the token is consumed.
///
/// @param token_count A pointer to the number of tokens in the value
/// of @c tokens, must be a valid pointer.
/// @param tokens A pointer to an array of tokens of minimum size
/// of @c token_size, must be a valid pointer.
/// @param token_types The token types to match, multiple types can be
/// bitwise-or'd.
///
/// @returns Whether the token has been consumed.
bool sh_token_consume(
    size_t *token_count, sh_token_t **tokens, sh_token_type_t token_types);

/// Removes all @b consecutive tokens from the @c tokens pointer if their types
/// matches any in @c token_types.
///
/// Decrements the value of @c token_count and increments the value
/// of @c tokens for each token consumed.
///
/// @param token_count A pointer to the number of tokens in the value
/// of @c tokens, must be a valid pointer.
/// @param tokens A pointer to an array of tokens of minimum size
/// of @c token_size, must be a valid pointer.
/// @param token_types The token types to match, multiple types can be
/// bitwise-or'd.
///
/// @returns Whether there are remaining tokens in @c tokens.
SH_INLINE bool sh_token_consume_while(
    size_t *token_count, sh_token_t **tokens, sh_token_type_t token_types)
{
    while (sh_token_consume(token_count, tokens, token_types))
        ;
    return *token_count > 0;
}

/// Removes the next token from the @c tokens pointer if its type @b doesn't
/// match in @c token_types.
///
/// Decrements the value of @c token_count and increments the value
/// of @c tokens if the token is consumed.
///
/// @param token_count A pointer to the number of tokens in the value
/// of @c tokens, must be a valid pointer.
/// @param tokens A pointer to an array of tokens of minimum size
/// of @c token_size, must be a valid pointer.
/// @param token_types The token types to match, multiple types can be
/// bitwise-or'd.
///
/// @returns Whether the token has been consumed.
bool sh_token_consume_except(
    size_t *token_count, sh_token_t **tokens, sh_token_type_t token_types);

/// Removes all @b consecutive tokens from the @c tokens pointer if their types
/// @b doesn't match any in @c token_types.
///
/// Decrements the value of @c token_count and increments the value
/// of @c tokens for each token consumed.
///
/// @param token_count A pointer to the number of tokens in the value
/// of @c tokens, must be a valid pointer.
/// @param tokens A pointer to an array of tokens of minimum size
/// of @c token_size, must be a valid pointer.
/// @param token_types The token types to match, multiple types can be
/// bitwise-or'd.
///
/// @returns Whether there are remaining tokens in @c tokens.
SH_INLINE bool sh_token_consume_until(
    size_t *token_count, sh_token_t **tokens, sh_token_type_t token_types)
{
    while (sh_token_consume_except(token_count, tokens, token_types))
        ;
    return *token_count > 0;
}

/// Fetches the offset of the next token whose type matches any
/// in @c token_types.
///
/// @param token_count The number of tokens in @c tokens.
/// @param tokens An array of tokens of minimum size @c token_size, must be a
/// valid pointer.
/// @param token_types The token types to match, multiple types can be
/// bitwise-or'd.
///
/// @returns The offset of the next matching token, or @c token_count if not
/// found.
size_t sh_token_find(size_t token_count, sh_token_t const tokens[],
    sh_token_type_t token_types);

/// Removes @c to_advance tokens from the value of @c tokens.
///
/// Decrements the value of @c token_count and increments the value
/// of @c tokens by @c to_advance.
///
/// @param token_count A pointer to the number of tokens in the value
/// of @c tokens, must be a valid pointer.
/// @param tokens A pointer to an array of tokens of minimum size
/// of @c token_size, must be a valid pointer.
/// @param to_advance The number of token to consume, must be lower or equal
/// to @c token_count
SH_INLINE void sh_token_advance(
    size_t *token_count, sh_token_t **tokens, size_t to_advance)
{
    assert(to_advance <= *token_count);
    *token_count -= to_advance;
    *tokens += to_advance;
}

/// @returns 0 on success, 1 on token error, or -1 on EOL.
int sh_token_quoted_string(
    sh_token_stream_t *stream, sh_token_t *token, char term);
/// @returns 0 on success, 1 on token error, or -1 on EOL.
int sh_token_unquoted_string(sh_token_stream_t *stream, sh_token_t *token);

#define SH_STREAM_LINE(stream)           ((char *)(stream)->line_buf.data)
#define SH_STREAM_OFFSET(stream, offset) (SH_STREAM_LINE((stream)) + (offset))
#define SH_STREAM_CURRENT(stream, offset) \
    (SH_STREAM_OFFSET((stream), (stream)->line_pos) + (offset))
#define SH_STREAM_CURRENT_LEN(stream) \
    ((stream)->line_buf.length - (stream)->line_pos)

#endif // !defined(__SHELL_INPUT__)
