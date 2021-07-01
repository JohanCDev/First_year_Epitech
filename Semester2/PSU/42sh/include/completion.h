/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** completion
*/

#ifndef COMPLETION_H_
#define COMPLETION_H_

#include <glob.h>
#include <libmy/collections/vec.h>
#include <stdbool.h>
#include <stddef.h>

struct sh_ctx;
struct sh_line_edit;

char *sh_get_path_end(char *path);
void sh_fill_completion_list(struct sh_ctx *ctx, glob_t *globbuf, char *word);
void sh_print_completion_list(
    struct sh_line_edit *line_edit, my_vec_t *line, bool apply);
char *sh_get_completion_entry(glob_t *globbuf, size_t index);

void sh_line_edit_fill_completion_list(struct sh_line_edit *line_edit,
    my_vec_t *line, glob_t *globbuf, bool apply_completion);
void sh_line_edit_apply_completion(struct sh_line_edit *line_edit,
    my_vec_t *line, glob_t *globbuf, char *word);

#endif /* !COMPLETION_H_ */
