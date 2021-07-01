/*
** EPITECH PROJECT, 2021
** linkedl
** File description:
** test_linked_lists
*/

#include "../my/my.h"
#include "../my/binary_tree.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void);

Test(insert_leaf, test_insert_leaf)
{
    node_tree_t *tree = NULL;

    insert_leaf(my_intdup(10), &tree, (void *)(void *)&my_intcmp);
    insert_leaf(my_intdup(4), &tree, (void *)(void *)&my_intcmp);
    insert_leaf(my_intdup(12), &tree, (void *)(void *)&my_intcmp);
    insert_leaf(my_intdup(10), &tree, (void *)(void *)&my_intcmp);

    cr_assert_eq(*(int *)tree->data, 10);
    cr_assert_eq(*(int *)tree->left->data, 4);
    cr_assert_eq(*(int *)tree->right->data, 12);
}

Test(copy_tree, test_copy_tree)
{
    node_tree_t *tree = NULL;
    node_tree_t *new_tree = NULL;

    insert_leaf(my_intdup(10), &tree, (void *)(void *)&my_intcmp);
    insert_leaf(my_intdup(4), &tree, (void *)(void *)&my_intcmp);
    insert_leaf(my_intdup(12), &tree, (void *)(void *)&my_intcmp);
    insert_leaf(my_intdup(10), &tree, (void *)(void *)&my_intcmp);
    new_tree = copy_tree(tree, (void *)&my_intdup_ptr);

    cr_assert_eq(*(int *)tree->data, *(int *)new_tree->data);
    cr_assert_eq(*(int *)tree->left->data, *(int *)tree->left->data);
    cr_assert_eq(*(int *)tree->right->data, *(int *)tree->right->data);
}

Test(copy_tree, test_copy_tree_null)
{
    node_tree_t *tree = NULL;
    node_tree_t *new_tree = NULL;

    new_tree = copy_tree(tree, (void *)&my_intdup_ptr);

    cr_assert_null(tree);
    cr_assert_null(new_tree);
}

Test(delete_tree, test_delete_tree)
{
    node_tree_t *tree = NULL;

    insert_leaf(my_intdup(10), &tree, (void *)(void *)&my_intcmp);
    insert_leaf(my_intdup(4), &tree, (void *)(void *)&my_intcmp);
    insert_leaf(my_intdup(12), &tree, (void *)(void *)&my_intcmp);
    insert_leaf(my_intdup(10), &tree, (void *)(void *)&my_intcmp);

    delete_tree(tree);
    tree = NULL;
    cr_assert_null(tree);
}

Test(delete_tree, test_delete_tree_null)
{
    node_tree_t *tree = NULL;

    delete_tree(tree);
    cr_assert_null(tree);
}

Test(find_in_tree, test_find_in_tree)
{
    node_tree_t *tree = NULL;

    insert_leaf(my_intdup(10), &tree, (void *)(void *)&my_intcmp);
    insert_leaf(my_intdup(4), &tree, (void *)(void *)&my_intcmp);
    insert_leaf(my_intdup(12), &tree, (void *)(void *)&my_intcmp);
    insert_leaf(my_intdup(10), &tree, (void *)(void *)&my_intcmp);

    node_tree_t *result = find_in_tree(&tree, my_intdup(10), \
    (void *)(void *)&my_intcmp);
    node_tree_t *result2 = find_in_tree(&tree, my_intdup(12), \
    (void *)(void *)&my_intcmp);
    node_tree_t *result3 = find_in_tree(&tree, my_intdup(4), \
    (void *)(void *)&my_intcmp);

    cr_assert_eq(result->data, tree->data);
    cr_assert_eq(result3->data, tree->left->data);
    cr_assert_eq(result2->data, tree->right->data);
}

Test(find_in_tree, test_find_in_tree_null)
{
    node_tree_t *tree = NULL;

    node_tree_t *result = find_in_tree(&tree, my_intdup(4), \
    (void *)(void *)&my_intcmp);

    cr_assert_null(result);
}

Test(test_print_int, print_tree_int, .init = redirect_all_std)
{
    node_tree_t *tree = NULL;

    insert_leaf(my_intdup(10), &tree, (void *)(void *)&my_intcmp);
    insert_leaf(my_intdup(4), &tree, (void *)(void *)&my_intcmp);
    insert_leaf(my_intdup(12), &tree, (void *)(void *)&my_intcmp);
    insert_leaf(my_intdup(10), &tree, (void *)(void *)&my_intcmp);
    print_tree_int(tree);
    cr_assert_stdout_eq_str("4\n10\n12\n");
}

Test(test_print_str, print_tree_str, .init = redirect_all_std)
{
    node_tree_t *tree = NULL;

    insert_leaf(my_strdup("Allo"), &tree, (void *)(void *)&my_strcmp);
    insert_leaf(my_strdup("Biska"), &tree, (void *)(void *)&my_strcmp);
    insert_leaf(my_strdup("Aaron"), &tree, (void *)(void *)&my_strcmp);
    insert_leaf(my_strdup("Bhouri"), &tree, (void *)(void *)&my_strcmp);
    print_tree_str(tree);
    cr_assert_stdout_eq_str("Aaron\nAllo\nBhouri\nBiska\n");
}
