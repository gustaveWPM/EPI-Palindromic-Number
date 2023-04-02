/*
** EPITECH PROJECT, 2021
** my_linked_lists_debug.c
** File description:
** Debug functions for my linked lists
*/

#include "my_linked_list.h"

#include <stdio.h>
#include <unistd.h>

void print_int(void *d)
{
    int i = *(int *) d;

    dprintf(STDOUT_FILENO, "%d ", i);
}

void print_float(void *d)
{
    float f = *(float *) d;

    dprintf(STDOUT_FILENO, "%.1f ", f);
}

void print_str(void *d)
{
    dprintf(STDOUT_FILENO, "%s", (char *) d);
}

void print_list(node_t *node, void (*fun_ptr) (void *))
{
    while (node) {
        (*fun_ptr) (node->data);
        node = node->next;
    }
}
