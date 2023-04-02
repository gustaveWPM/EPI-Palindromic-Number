/*
** EPITECH PROJECT, 2021
** my_generic_linked_list_fetch.c
** File description:
** Generic linked list fetch functions
*/

#include "my_linked_list.h"
#include "my_string.h"

#include <stddef.h>

long long my_fetch_nb_index(node_t *list, long long nb_lld)
{
    node_t *cur_node = list;
    long long i = 0;
    long long data_lld = 0;

    for (i = 0; cur_node; i++) {
        data_lld = *(long long *) cur_node->data;
        if (nb_lld == data_lld)
            return i;
        cur_node = cur_node->next;
    }
    return -1;
}

long long my_fetch_str_index(node_t *list, char *str)
{
    node_t *cur_node = list;
    long long i = 0;

    for (i = 0; cur_node; i++) {
        if (!my_strcmp(str, (char *) cur_node->data))
            return i;
        cur_node = cur_node->next;
    }
    return -1;
}
