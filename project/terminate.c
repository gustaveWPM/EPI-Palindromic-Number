/*
** EPITECH PROJECT, 2021
** terminate.c
** File description:
** Exit point
*/

#include "my_optflags.h"

void terminate(optflags_t *opt)
{
    my_optflags_destroy(&opt);
}
