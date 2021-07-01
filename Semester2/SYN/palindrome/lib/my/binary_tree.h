/*
** EPITECH PROJECT, 2021
** linkedl
** File description:
** linked_list
*/

#ifndef __BINARY_TREE__
#define __BINARY_TREE__

//-----NEEDED-INCLUDE------
//-----MACROS--------------
//-----STRUCTURES-----

typedef struct s_node_tree {
    struct s_node_tree *left;
    void *data;
    struct s_node_tree *right;
} node_tree_t;

//-----PROTOTYPES----------
///Insert a leaf on the tree at it's place
///@param data Data to insert
///@param leaf Address of the pointer to the main tree
///@param cmp Function pointer of comparaison
///@return -1 if an error occur or 0 if it's ok
int insert_leaf(void *data, node_tree_t **leaf, int (*cmp)(void *, void *));

///Delete a tree (set tree to NULL after the call)
///@param tree Pointer to the tree
void delete_tree(node_tree_t *tree);

///Print all data of a tree of strings
///@param tree Pointer to the tree
void print_tree_str(node_tree_t *tree);

///Print all data of a tree of int
///@param tree Pointer to the tree
void print_tree_int(node_tree_t *tree);

///Copy a tree into an other
///@param tree Tree to copy
///@return The new tree or NULL if tree is NULL
node_tree_t *copy_tree(node_tree_t *tree, void *(*cpy)(void *));

///Find the leaf containing the data_ref
///@param tree Address of the pointer to the main tree
///@param data_ref Data to find
///@param cmp Function pointer of comparaison
///@return NULL if no data is in the tree or the leaf with the data
node_tree_t *find_in_tree(node_tree_t **tree, void *data_ref, \
int (*cmp)(void *, void *));

#endif