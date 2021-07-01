/*
** EPITECH PROJECT, 2021
** linkedl
** File description:
** test_linked_lists
*/

#include "../my/my.h"
#include "../my/linked_list.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void);

Test(new_linked_list, test_new_linked_list)
{
    linked_list_t *list = new_linked_list();

    cr_assert_eq(list->size, 0);
    cr_assert_null(list->first);
    cr_assert_null(list->last);
}

Test(new_node, test_new_node_null)
{
    node_t *node = new_node(NULL);

    cr_assert_null(node);
}

Test(new_node, test_new_node_valid)
{
    node_t *node = new_node(my_strdup("Johan"));

    cr_assert_str_eq(node->data, "Johan");
    cr_assert_null(node->prev);
    cr_assert_null(node->next);
}

Test(insert_first_in_list, test_insert_at_first)
{
    linked_list_t *list = new_linked_list();
    node_t *node = new_node(my_strdup("Johan"));
    insert_first_in_list(node, list);

    cr_assert_str_eq(list->first->data, "Johan");
}

Test(insert_first_in_list, test_insert_at_first_two)
{
    linked_list_t *list = new_linked_list();
    node_t *node = new_node(my_strdup("Johan"));
    insert_first_in_list(node, list);
    node = new_node(my_strdup("Toto"));
    insert_first_in_list(node, list);

    cr_assert_str_eq(list->first->data, "Toto");
    cr_assert_str_eq(list->first->next->data, "Johan");
}

Test(insert_first_in_list, test_insert_at_first_node_null)
{
    linked_list_t *list = new_linked_list();
    node_t *node = NULL;
    insert_first_in_list(node, list);

    cr_assert_null(insert_first_in_list(node, list));
}

Test(insert_first_in_list, test_insert_at_first_list_null)
{
    linked_list_t *list = NULL;
    node_t *node = new_node(my_strdup("Johan"));
    insert_first_in_list(node, list);

    cr_assert_null(insert_first_in_list(node, list));
}

Test(insert_last_in_list, test_insert_at_last)
{
    linked_list_t *list = new_linked_list();
    node_t *node = new_node(my_strdup("Johan"));
    insert_last_in_list(node, list);

    cr_assert_str_eq(list->first->data, "Johan");
}

Test(insert_last_in_list, test_insert_at_last_two)
{
    linked_list_t *list = new_linked_list();
    node_t *node = new_node(my_strdup("Johan"));
    insert_last_in_list(node, list);
    node = new_node(my_strdup("Toto"));
    insert_last_in_list(node, list);

    cr_assert_str_eq(list->first->data, "Johan");
    cr_assert_str_eq(list->first->next->data, "Toto");
}

Test(insert_last_in_list, test_insert_at_last_node_null)
{
    linked_list_t *list = new_linked_list();
    node_t *node = NULL;
    insert_last_in_list(node, list);

    cr_assert_null(insert_first_in_list(node, list));
}

Test(insert_last_in_list, test_insert_at_last_list_null)
{
    linked_list_t *list = NULL;
    node_t *node = new_node(my_strdup("Johan"));
    insert_last_in_list(node, list);

    cr_assert_null(insert_first_in_list(node, list));
}

Test(swap_nodes, test_swap_nodes)
{
    linked_list_t *list = new_linked_list();
    node_t *node = new_node(my_strdup("Johan"));
    node_t *node2 = new_node(my_strdup("Toto"));
    insert_last_in_list(node, list);
    insert_last_in_list(node2, list);
    swap_nodes(list->first, list->first->next);

    cr_assert_str_eq(list->first->data, "Toto");
    cr_assert_str_eq(list->first->next->data, "Johan");
}

Test(swap_nodes, test_swap_nodes_null)
{
    linked_list_t *list = new_linked_list();
    node_t *node = new_node(my_strdup("Johan"));
    node_t *node2 = new_node(my_strdup("Toto"));
    insert_last_in_list(node, list);
    insert_last_in_list(node2, list);
    swap_nodes(node, NULL);

    cr_assert_str_eq(list->first->data, "Johan");
    cr_assert_str_eq(list->first->next->data, "Toto");
}

Test(swap_nodes, test_swap_nodes_null_two)
{
    linked_list_t *list = new_linked_list();
    node_t *node = new_node(my_strdup("Johan"));
    node_t *node2 = new_node(my_strdup("Toto"));
    insert_last_in_list(node, list);
    insert_last_in_list(node2, list);
    swap_nodes(NULL, node2);

    cr_assert_str_eq(list->first->data, "Johan");
    cr_assert_str_eq(list->first->next->data, "Toto");
}

Test(bubble_sort_list, test_less_than_two)
{
    linked_list_t *list = new_linked_list();
    node_t *node = new_node(my_strdup("Toto"));
    insert_last_in_list(node, list);
    bubble_sort_list(list, (void *)(void *)&my_strcmp);

    cr_assert_str_eq(list->first->data, "Toto");
}

Test(bubble_sort_list, test_two)
{
    linked_list_t *list = new_linked_list();
    node_t *node = new_node(my_strdup("Toto"));
    node_t *node2 = new_node(my_strdup("Johan"));
    insert_last_in_list(node, list);
    insert_last_in_list(node2, list);
    bubble_sort_list(list, (void *)(void *)&my_strcmp);

    cr_assert_str_eq(list->first->data, "Johan");
    cr_assert_str_eq(list->first->next->data, "Toto");
}

Test(bubble_sort_list, test_more)
{
    linked_list_t *list = new_linked_list();
    node_t *node = new_node(my_strdup("Fifi"));
    node_t *node2 = new_node(my_strdup("Donald"));
    node_t *node3 = new_node(my_strdup("Loulou"));
    node_t *node4 = new_node(my_strdup("Riri"));
    insert_last_in_list(node, list);
    insert_last_in_list(node2, list);
    insert_last_in_list(node3, list);
    insert_last_in_list(node4, list);
    bubble_sort_list(list, (void *)(void *)&my_strcmp);

    cr_assert_str_eq(list->first->data, "Donald");
    cr_assert_str_eq(list->first->next->data, "Fifi");
    cr_assert_str_eq(list->first->next->next->data, "Loulou");
    cr_assert_str_eq(list->first->next->next->next->data, "Riri");
}

Test(delete_node, test_delete_node_correct)
{
    linked_list_t *list = new_linked_list();
    node_t *node = new_node(my_strdup("Fifi"));
    insert_first_in_list(node, list);

    delete_node(node, list);
    node = NULL;
    cr_assert_null(node);
}

Test(delete_node, test_delete_first_node_correct)
{
    linked_list_t *list = new_linked_list();
    node_t *node = new_node(my_strdup("Fifi"));
    node_t *node2 = new_node(my_strdup("Riri"));
    insert_first_in_list(node, list);
    insert_first_in_list(node2, list);

    delete_node(node2, list);
    node = NULL;
    cr_assert_null(node);
}

Test(delete_node, test_delete_last_node_correct)
{
    linked_list_t *list = new_linked_list();
    node_t *node = new_node(my_strdup("Fifi"));
    node_t *node2 = new_node(my_strdup("Riri"));
    insert_first_in_list(node, list);
    insert_first_in_list(node2, list);

    delete_node(node, list);
    node = NULL;
    cr_assert_null(node);
}

Test(delete_node, test_delete_middle_node)
{
    linked_list_t *list = new_linked_list();
    node_t *node = new_node(my_strdup("Fifi"));
    node_t *node2 = new_node(my_strdup("Riri"));
    node_t *node3 = new_node(my_strdup("Loulou"));
    insert_first_in_list(node, list);
    insert_first_in_list(node2, list);
    insert_first_in_list(node3, list);

    delete_node(node2, list);
    node = NULL;
    cr_assert_null(node);
}

Test(free_data, test_free_data)
{
    char *str = NULL;
    char *str2 = my_strdup("HEEEEEEEEEEY");

    free_data(str);
    free_data(str2);
    str2 = NULL;
    cr_assert_null(str);
    cr_assert_null(str2);
}

Test(delete_node, test_delete_node_one_is_null)
{
    linked_list_t *list = new_linked_list();
    node_t *node = new_node(my_strdup("Fifi"));
    insert_first_in_list(node, list);

    int res1 = delete_node(NULL, NULL);
    int res2 = delete_node(node, NULL);
    int res3 = delete_node(NULL, list);
    cr_assert_eq(res1, -1);
    cr_assert_eq(res2, -1);
    cr_assert_eq(res3, -1);
}

Test(delete_list, test_delete_list)
{
    linked_list_t *list = new_linked_list();
    node_t *node = new_node(my_strdup("Fifi"));
    insert_first_in_list(node, list);
    node_t *node2 = new_node(my_strdup("Fifi"));
    insert_first_in_list(node2, list);
    node_t *node3 = new_node(my_strdup("Fifi"));
    insert_first_in_list(node3, list);

    delete_list(list);
    list = NULL;
    cr_assert_null(list);
}

Test(get_size_list, test_size_list)
{
    linked_list_t *list = new_linked_list();
    linked_list_t *list_null = NULL;
    node_t *node = new_node(my_strdup("Fifi"));
    insert_first_in_list(node, list);
    node_t *node2 = new_node(my_strdup("Fifi"));
    insert_first_in_list(node2, list);
    node_t *node3 = new_node(my_strdup("Fifi"));
    insert_first_in_list(node3, list);

    cr_assert_eq(get_size_list(list), 3);
    cr_assert_eq(get_size_list(list_null), -1);
}

Test(print_list_int, test_print_list_int_null)
{
    linked_list_t *list = new_linked_list();
    int ret = print_list_int(NULL);
    int ret2 = print_list_int(list);

    cr_assert_eq(ret, -1);
    cr_assert_eq(ret2, -1);
}

Test(print_list_int, test_print_list_int)
{
    linked_list_t *list = new_linked_list();
    node_t *node = new_node(my_intdup(10));
    insert_first_in_list(node, list);
    node_t *node2 = new_node(my_intdup(9));
    insert_first_in_list(node2, list);
    node_t *node3 = new_node(my_intdup(8));
    insert_first_in_list(node3, list);

    int ret = print_list_int(list);
    cr_assert_eq(ret, 0);
}

Test(print_list_int, test_print_list_int_error)
{
    linked_list_t *list = new_linked_list();
    node_t *node = new_node(my_intdup(10));
    insert_first_in_list(node, list);
    list->first->data = NULL;

    int ret = print_list_int(list);
    cr_assert_eq(ret, -1);
}

Test(print_list_str, test_print_list_str_null)
{
    linked_list_t *list = new_linked_list();
    int ret = print_list_str(NULL);
    int ret2 = print_list_str(list);

    cr_assert_eq(ret, -1);
    cr_assert_eq(ret2, -1);
}

Test(print_list_str, test_print_str_int)
{
    linked_list_t *list = new_linked_list();
    node_t *node = new_node(my_strdup("Hey"));
    insert_first_in_list(node, list);
    node_t *node2 = new_node(my_strdup("Poulet"));
    insert_first_in_list(node2, list);
    node_t *node3 = new_node(my_strdup("Riz"));
    insert_first_in_list(node3, list);

    int ret = print_list_str(list);
    cr_assert_eq(ret, 0);
}

Test(print_list_str, test_print_list_str_error)
{
    linked_list_t *list = new_linked_list();
    node_t *node = new_node(my_strdup("One"));
    insert_first_in_list(node, list);
    list->first->data = NULL;

    int ret = print_list_str(list);
    cr_assert_eq(ret, -1);
}