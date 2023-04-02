/*
** EPITECH PROJECT, 2021
** my_count_flags_occurrences.c
** File description:
** Optflags flags occurrences counter
*/

#include "my_optflags.h"
#include "my_string.h"

#include <stddef.h>
#include <stdbool.h>

size_t my_count_flags_occurrences(optflags_t *opt, char *flag)
{
    size_t count = 0;

    for (size_t i = 0; i < opt->nb_flags; i++)
        if (!my_strcmp(opt->flags[i], flag))
            count += 1;
    return count;
}
