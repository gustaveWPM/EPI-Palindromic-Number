/*
** EPITECH PROJECT, 2021
** my_generic_linked_list_del.c
** File description:
** Generic linked list del functions
*/

#include "my_linked_list.h"

#include <stdlib.h>

bool my_delete_at(node_t **list, size_t index)
{
    node_t *cur_node = *list;
    node_t *node_to_delete = NULL;

    if (my_is_empty_list(*list))
        return false;
    if (index == 0) {
        my_shift(list);
        return true;
    }
    for (size_t i = 0; i < index - 1; i++) {
        if (cur_node->next == NULL)
            return false;
        cur_node = cur_node->next;
    }
    node_to_delete = cur_node->next;
    cur_node->next = node_to_delete->next;
    free(node_to_delete);
    return true;
}

bool my_delete_first_str(node_t **list, char *str)
{
    long long index = my_fetch_str_index(*list, str);

    if (index == -1)
        return false;
    my_delete_at(list, index);
    return true;
}

bool my_delete_all_str(node_t **list, char *str)
{
    long long index = my_fetch_str_index(*list, str);

    if (index == -1)
        return false;
    while (index != -1) {
        my_delete_at(list, index);
        index = my_fetch_str_index(*list, str);
    }
    return true;
}

bool my_delete_first_nb(node_t **list, long long nb_lld)
{
    long long index = my_fetch_nb_index(*list, nb_lld);

    if (index == -1)
        return false;
    my_delete_at(list, index);
    return true;
}

bool my_delete_all_nb(node_t **list, long long nb_lld)
{
    long long index = my_fetch_nb_index(*list, nb_lld);

    if (index == -1)
        return false;
    while (index != -1) {
        my_delete_at(list, index);
        index = my_fetch_nb_index(*list, nb_lld);
    }
    return true;
}
