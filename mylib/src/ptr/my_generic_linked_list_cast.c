/*
** EPITECH PROJECT, 2021
** my_generic_linked_list_cast.c
** File description:
** Generic linked list count functions
*/

#include "my_two_dims_arrays.h"
#include "my_linked_list.h"
#include "my_string.h"

#include <stddef.h>
#include <stdlib.h>

char **str_linked_list_to_two_dims_array(node_t *tokenized_file)
{
    size_t list_len = my_linked_list_len(tokenized_file);
    size_t memsize = (list_len + 1) * sizeof(char *);
    node_t *cur_node = tokenized_file;
    char **two_dims_array = NULL;

    two_dims_array = malloc(memsize);
    if (!two_dims_array)
        return NULL;
    for (size_t i = 0; i < list_len; i++) {
        if (!cur_node || !cur_node->data)
            break;
        two_dims_array[i] = my_strdup((char *) cur_node->data);
        if (!two_dims_array[i]) {
            my_two_dims_array_destroyer((void **) two_dims_array);
            return NULL;
        }
        cur_node = cur_node->next;
    }
    two_dims_array[list_len] = NULL;
    return two_dims_array;
}
