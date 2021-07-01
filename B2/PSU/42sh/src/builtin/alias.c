/*
** EPITECH PROJECT, 2021
** 42sh
** File description:
** The alias builtin
*/

#include "builtin.h"
#include "command.h"

#include <libmy/ascii/ascii.h>
#include <libmy/memory/alloc.h>
#include <libmy/printf.h>
#include <stdlib.h>

static int sh_alias_entry_cmp(
    sh_alias_entry_t const *a, sh_alias_entry_t const *b)
{
    return my_memcmp(
        a->key.value, b->key.value, MY_MIN(a->key.length, b->key.length));
}

static int sh_print_aliases(sh_ctx_t *ctx)
{
    sh_alias_entry_t *entries = malloc(sizeof(*entries) * ctx->aliases.length);
    my_hash_map_iter_t iter;
    sh_alias_entry_t e;
    size_t count = 0;

    if (entries == NULL)
        return 1;
    my_hash_map_iter_init(&iter, &ctx->aliases);
    for (size_t i = 0; my_hash_map_iter_next(&iter); ++i)
        entries[count++] = (sh_alias_entry_t){
            *(sh_lstr_t *)iter.key, *(sh_alias_t *)iter.value};
    qsort(entries, count, sizeof(*entries),
        (my_comparator_t)&sh_alias_entry_cmp);
    for (size_t i = 0; i < count; ++i) {
        e = entries[i];
        my_printf(e.value.multi_word ? "%.*s\t(%.*s)\n" : "%.*s\t%.*s\n",
            e.key.length, e.key.value, e.value.length, e.value.value);
    }
    free(entries);
    return 0;
}

static bool sh_builtin_alias_set_value(
    sh_alias_t *value, size_t count, char const *values[])
{
    value->length = 0;
    for (size_t i = 0; i < count; ++i)
        value->length += my_strlen(values[i]) + 1;
    value->value = my_calloc(sizeof(*value->value), value->length);
    if (value->value == NULL)
        return false;
    for (size_t i = 0; i < count; ++i) {
        my_strcat(value->value, values[i]);
        if (i + 1 < count)
            my_strcat(value->value, " ");
    }
    value->multi_word = count > 1;
    return true;
}

static bool sh_builtin_alias_print_or_update_value(
    sh_ctx_t *ctx, size_t argc, char const *argv[], my_hash_map_entry_t *entry)
{
    sh_alias_t *v =
        (sh_alias_t *)my_hash_map_entry_value(&ctx->aliases, entry);

    if (argc == 2)
        return my_printf("%.*s\n", v->length, v->value) * 0;
    free(v->value);
    sh_builtin_alias_set_value(v, argc - 2, argv + 2);
    return 0;
}

int sh_builtin_alias(
    sh_ctx_t *ctx, int *should_exit, size_t argc, char const *argv[])
{
    sh_lstr_t key;
    sh_alias_t value;
    my_hash_map_entry_t *entry;

    if (argc < 2)
        return sh_print_aliases(ctx);
    key = SH_TO_LSTR(argv[1]);
    entry = my_hash_map_get_entry(&ctx->aliases, &key);
    if (entry != NULL)
        return sh_builtin_alias_print_or_update_value(ctx, argc, argv, entry);
    if (argc > 2) {
        key.value = my_strdup(key.value);
        sh_builtin_alias_set_value(&value, argc - 2, argv + 2);
        my_hash_map_insert(&ctx->aliases, &key, &value);
    }
    (void)should_exit;
    return 0;
}
