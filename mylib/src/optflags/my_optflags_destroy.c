/*
** EPITECH PROJECT, 2021
** my_optflags_destroy.c
** File description:
** Optflags destroy functions
*/

#include "my_optflags.h"

#include <stddef.h>
#include <stdlib.h>

static void destroy_optflags(optflags_t *opt)
{
    if (!opt->flags)
        return;
    for (size_t i = 0; i < opt->nb_flags; i++)
        if (opt->flags[i])
            free(opt->flags[i]);
    free(opt->flags);
}

static void destroy_optvalues(optflags_t *opt)
{
    if (!opt->values)
        return;
    for (size_t i = 0; i < opt->nb_flags; i++)
        if (opt->values[i])
            free(opt->values[i]);
    free(opt->values);
}

void my_optflags_destroy(optflags_t **opt)
{
    if (*opt == NULL)
        return;
    destroy_optflags(*opt);
    destroy_optvalues(*opt);
    free(*opt);
    *opt = NULL;
}
