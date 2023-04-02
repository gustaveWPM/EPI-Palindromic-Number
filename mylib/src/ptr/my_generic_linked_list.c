/*
** EPITECH PROJECT, 2021
** my_generic_linked_list.c
** File description:
** Generic linked list functions
*/

#include "my_linked_list.h"
#include "my_safe_free.h"

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

node_t *my_create_linked_list(void)
{
    node_t *new_list = malloc(sizeof(node_t));

    if (!new_list)
        return NULL;
    new_list->data = NULL;
    new_list->next = NULL;
    return new_list;
}

bool my_linked_list_destroyer(node_t **list)
{
    node_t *cur_node = *list;
    node_t *memo = NULL;

    if (!cur_node)
        return false;
    while (cur_node) {
        memo = cur_node;
        cur_node = cur_node->next;
        free(memo->data);
        free(memo);
    }
    *list = NULL;
    return true;
}

void my_revlist(node_t **list)
{
    node_t *prev = NULL;
    node_t *current = *list;
    node_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *list = prev;
}

size_t my_linked_list_len(node_t *list)
{
    node_t *cur_node = list;
    size_t len = 0;

    while (cur_node) {
        len += 1;
        cur_node = cur_node->next;
    }
    return len;
}
