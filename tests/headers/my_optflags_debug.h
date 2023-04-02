/*
** EPITECH PROJECT, 2021
** my_optflags_debug.h
** File description:
** My opt flags debug functions
*/

#ifndef MY_OPTFLAGS_DEBUG_H
    #define MY_OPTFLAGS_DEBUG_H
    #include "my_linked_list.h"

    void print_list(node_t *node, void (*fun_ptr) (void *));
    void print_float(void *f);
    void print_int(void *d);
#endif
