/*
** EPITECH PROJECT, 2021
** my_generic_linked_list_popshift.c
** File description:
** Generic linked list push functions
*/

#include "my_linked_list.h"

#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

static bool my_push_after(
    node_t *previous_node, void *new_data, size_t data_size
)
{
    node_t *new_node = NULL;

    if (!previous_node)
        return false;
    new_node = malloc(sizeof(node_t));
    if (!new_node)
        return false;
    new_node->data = malloc(data_size);
    if (!new_node->data) {
        free(new_node);
        return false;
    }
    for (size_t i = 0; i < data_size; i++)
        *(char *) (new_node->data + i) = *(char *) (new_data + i);
    new_node->next = previous_node->next;
    previous_node->next = new_node;
    return true;
}

bool my_push_at(node_t **list, void *new_data, size_t data_size, size_t index)
{
    node_t *cur_node = *list;

    if (index == 0)
        return my_push_head(list, new_data, data_size);
    for (size_t i = 0; cur_node && (i < index - 1); i++)
        cur_node = cur_node->next;
    if (!cur_node)
        return my_push_back(list, new_data, data_size);
    return my_push_after(cur_node, new_data, data_size);
}

bool my_push_back(node_t **list, void *new_data, size_t data_size)
{
    node_t *last = *list;
    node_t *new_node = my_create_linked_list();

    if (!new_node)
        return false;
    new_node->data = malloc(data_size);
    if (!new_node->data) {
        free(new_node);
        return false;
    }
    for (size_t i = 0; i < data_size; i++)
        *(char *) (new_node->data + i) = *(char *) (new_data + i);
    new_node->next = NULL;
    if (*list == NULL) {
        *list = new_node;
        return true;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return true;
}

bool my_push_head(node_t **list, void *new_data, size_t data_size)
{
    node_t *new_node = my_create_linked_list();

    if (!new_node)
        return false;
    new_node->data = malloc(data_size);
    if (!new_node->data) {
        free(new_node);
        return false;
    }
    new_node->next = *list;
    for (size_t i = 0; i < data_size; i++)
        *(char *) (new_node->data + i) = *(char *) (new_data + i);
    *list = new_node;
    return true;
}
