/*
** EPITECH PROJECT, 2021
** my_generic_linked_list_includes.c
** File description:
** Generic linked list includes functions
*/

#include "my_linked_list.h"

#include <stdbool.h>

bool my_includes_nb(node_t *list, long long nb_lld)
{
    return (my_fetch_nb_index(list, nb_lld) != -1);
}

bool my_includes_str(node_t *list, char *str)
{
    return (my_fetch_str_index(list, str) != -1);
}

bool my_is_empty_list(node_t *list)
{
    if (!list)
        return true;
    if (!list->data && !list->next)
        return true;
    return false;
}
