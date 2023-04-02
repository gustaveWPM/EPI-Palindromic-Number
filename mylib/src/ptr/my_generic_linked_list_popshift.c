/*
** EPITECH PROJECT, 2021
** my_generic_linked_list_popshift.c
** File description:
** Generic linked list pop and shift functions
*/

#include "my_linked_list.h"
#include "my_safe_free.h"

#include <stdbool.h>
#include <stddef.h>

bool my_pop(node_t **list)
{
    node_t *cur_node = *list;

    if (my_is_empty_list(*list))
        return false;
    if ((*list)->next == NULL) {
        my_linked_list_destroyer(list);
        return true;
    }
    while (cur_node->next->next != NULL)
        cur_node = cur_node->next;
    if (cur_node->next->data)
        free(cur_node->next->data);
    free(cur_node->next);
    cur_node->next = NULL;
    return true;
}

bool my_shift(node_t **list)
{
    node_t *next_node = NULL;

    if (*list == NULL)
        return false;
    next_node = (*list)->next;
    MY_SAFE_FREE(*list);
    *list = next_node;
    return true;
}
