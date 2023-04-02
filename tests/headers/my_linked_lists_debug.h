/*
** EPITECH PROJECT, 2021
** my_linked_lists_debug.h
** File description:
** My linked lists debug functions header
*/

#ifndef MY_LINKED_LISTS_DEBUG_H
    #define MY_LINKED_LISTS_DEBUG_H
    #include "my_linked_list.h"

    void print_list(node_t *node, void (*fun_ptr) (void *));
    void print_float(void *f);
    void print_int(void *d);
    void print_str(void *d);
#endif
