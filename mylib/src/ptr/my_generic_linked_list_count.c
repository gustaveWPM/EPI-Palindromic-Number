/*
** EPITECH PROJECT, 2021
** my_generic_linked_list_count.c
** File description:
** Generic linked list count functions
*/

#include "my_linked_list.h"

#include <stddef.h>

long long my_count_nb(node_t *list, long long nb_lld)
{
    node_t *fetchall_res = my_fetchall_nb_index(list, nb_lld);
    size_t count = -1;

    if (!fetchall_res)
        return -1;
    count = my_linked_list_len(fetchall_res);
    my_linked_list_destroyer(&fetchall_res);
    return count;
}

long long my_count_str(node_t *list, char *str)
{
    node_t *fetchall_res = my_fetchall_str_index(list, str);
    size_t count = -1;

    if (!fetchall_res)
        return -1;
    count = my_linked_list_len(fetchall_res);
    my_linked_list_destroyer(&fetchall_res);
    return count;
}
