/*
** EPITECH PROJECT, 2021
** linkedl
** File description:
** binary_tree
*/

#include "../binary_tree.h"
#include "../my.h"
#include <stdlib.h>

int insert_leaf(void *data, node_tree_t **leaf, int (*cmp)(void *, void *))
{
    if (*leaf == NULL) {
        *leaf = malloc(sizeof(node_tree_t));
        if (leaf == NULL)
            return (my_put_error("Error malloc", -1));
        (*leaf)->data = data;
        (*leaf)->left = NULL;
        (*leaf)->right = NULL;
        return 0;
    }
    if (cmp(data, (*leaf)->data) > 0)
        insert_leaf(data, &(*leaf)->right, cmp);
    else if (cmp(data, (*leaf)->data) < 0)
        insert_leaf(data, &(*leaf)->left, cmp);
    else
        my_free(data);
    return 0;
}

node_tree_t *copy_tree(node_tree_t *tree, void *(*cpy)(void *))
{
    node_tree_t *new_tree = NULL;

    if (tree == NULL)
        return NULL;
    new_tree = (node_tree_t *)malloc(sizeof(node_tree_t));
    if (new_tree == NULL)
        return my_put_error_ret_ptr("Error malloc", NULL);
    new_tree->left = copy_tree(tree->left, cpy);
    new_tree->right = copy_tree(tree->right, cpy);
    new_tree->data = cpy(tree->data);
    return new_tree;
}

void delete_tree(node_tree_t *tree)
{
    if (tree == NULL)
        return;
    delete_tree(tree->left);
    delete_tree(tree->right);
    my_free((void *)tree->data);
    my_free((void *)tree);
}

node_tree_t *find_in_tree(node_tree_t **tree, void *data_ref, \
int (*cmp)(void *, void *))
{
    if (*tree == NULL)
        return NULL;
    if (cmp((*tree)->data, data_ref) == 0) {
        return (*tree);
    } else if (cmp(data_ref, (*tree)->data) > 0) {
        return find_in_tree(&(*tree)->right, data_ref, cmp);
    } else {
        return find_in_tree(&(*tree)->left, data_ref, cmp);
    }
}