/*
** EPITECH PROJECT, 2021
** linkedl
** File description:
** print
*/

#include "../my.h"
#include "../binary_tree.h"

void print_tree_int(node_tree_t *tree)
{
    if (tree == NULL)
        return;
    print_tree_int(tree->left);
    my_printf("%d\n", *(int *)tree->data);
    print_tree_int(tree->right);
}

void print_tree_str(node_tree_t *tree)
{
    if (tree == NULL)
        return;
    print_tree_str(tree->left);
    my_printf("%s\n", (char *)tree->data);
    print_tree_str(tree->right);
}