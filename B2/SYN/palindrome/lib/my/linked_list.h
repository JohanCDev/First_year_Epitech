/*
** EPITECH PROJECT, 2021
** linkedl
** File description:
** linked_list
*/

#ifndef __LINKED_LIST__
#define __LINKED_LIST__

//-----NEEDED-INCLUDE------
//-----MACROS--------------
//-----STRUCTURES-----

typedef struct s_node {
    void *data;
    struct s_node *next;
    struct s_node *prev;
} node_t;

typedef struct s_linked_list {
    node_t *first;
    node_t *last;
    int size;
} linked_list_t;

//-----PROTOTYPES----------

/// Print the list of str
/// @param list pointer to the list
int print_list_str(linked_list_t *list);
/// Print the list of int
/// @param list pointer to the list
int print_list_int(linked_list_t *list);
///Get the size of a linked list
///@param list Pointer to the list to count
///@return -1 if failed, otherwise size of the list
int get_size_list(linked_list_t *list);

///Swap two nodes
///@param node1 first node to swap
///@param node2 second node to swap
void swap_nodes(node_t *node1, node_t *node2);

///Use a function to compare data in two nodes and will swap the two if 
///it is needed
///@param current_node The actual node in the sorting function
///@param cmp Pointer to the comparaison function
void compare_for_swap(node_t *current_node, int (*cmp)(void *, void *));

///Sort a linked list with bubble sort algorithm
///@param list linked list to sort
///@param cmp Coparaison function that will be used
void bubble_sort_list(linked_list_t *list, int (*cmp)(void *, void *));

///Insert a node at the last position in a linked_list
///@param node_to_add Node that will be added
///@param list List where it will be added
node_t *insert_first_in_list(node_t *node_to_add, linked_list_t *list);

///Insert a node at the first position in a linked_list
///@param node_to_add Node that will be added
///@param list List where it will be added
node_t *insert_last_in_list(node_t *node_to_add, linked_list_t *list);

///Create a linked_list
///@returns the linked list created
linked_list_t *new_linked_list(void);

///Create a node
///@param data The data to insert in the node
///@returns The node created
node_t *new_node(void *data);

///Free the data in the node
///@param data Data to be freed
void free_data(void *data);

///Delete a node
///@param node_to_delete Node to delete
///@param list Linked list from which the node will be deleted
int delete_node(node_t *node_to_delete, linked_list_t *list);

///Delete a list (Don't forget to set list to NULL after)
///@param list Linked list to remove and free
void delete_list(linked_list_t *list);

#endif

//If you want to print data in linked list (void *) that is an int
//You need to use a kind of my_intdup
//To print it simply use my_printf("%d\n", *(int *)node->data)