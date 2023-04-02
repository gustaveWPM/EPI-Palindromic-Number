/*
** EPITECH PROJECT, 2021
** my_generic_linked_list_fetchall.c
** File description:
** Generic linked list fetchall functions
*/

#include "my_linked_list.h"
#include "my_string.h"

#include <stddef.h>

static bool append_nb_index(
    long long i, node_t **indexes, long long nb_lld, long long data_lld
)
{
    if (nb_lld == data_lld)
        if (!my_push_head(indexes, (void *) &i, sizeof(long long)))
            return false;
    return true;
}

static bool append_str_index(
    long long i, node_t **indexes, char *str, void *data
)
{
    if (!my_strcmp(str, (char *) data))
        if (!my_push_head(indexes, (void *) &i, sizeof(long long)))
            return false;
    return true;
}

node_t *my_fetchall_str_index(node_t *list, char *str)
{
    node_t *cur_node = list;
    node_t *indexes = NULL;
    long long i = 0;

    for (i = 0; cur_node; i++) {
        if (!append_str_index(i, &indexes, str, cur_node->data)) {
            my_linked_list_destroyer(&indexes);
            return NULL;
        }
        cur_node = cur_node->next;
    }
    my_revlist(&indexes);
    return indexes;
}

node_t *my_fetchall_nb_index(node_t *list, long long nb_lld)
{
    node_t *cur_node = list;
    node_t *indexes = NULL;
    long long i = 0;
    long long data_lld = 0;

    for (i = 0; cur_node; i++) {
        data_lld = *(long long *) cur_node->data;
        if (!append_nb_index(i, &indexes, nb_lld, data_lld)) {
            my_linked_list_destroyer(&indexes);
            return NULL;
        }
        cur_node = cur_node->next;
    }
    my_revlist(&indexes);
    return indexes;
}
