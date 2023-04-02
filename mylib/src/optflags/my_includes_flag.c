/*
** EPITECH PROJECT, 2021
** my_includes_flag.c
** File description:
** Returns true if the flag is in opt, otherwise false
*/

#include "my_optflags.h"
#include "my_string.h"

#include <stddef.h>
#include <stdbool.h>

bool my_includes_flag(optflags_t *opt, char *flag)
{
    if (!opt || !flag)
        return false;
    for (size_t i = 0; i < opt->nb_flags; i++)
        if (!my_strcmp(flag, opt->flags[i]))
            return true;
    return false;
}
