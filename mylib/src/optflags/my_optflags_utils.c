/*
** EPITECH PROJECT, 2021
** my_optflags_utils.c
** File description:
** Optflags utilitary functions
*/

#include "my_optflags.h"

#include <stdbool.h>
#include <stddef.h>

void set_opt_infos(optflags_t *opt, bool strict_mode, bool verbose)
{
    if (!opt)
        return;
    opt->infos.strict_mode = strict_mode;
    opt->infos.verbose = verbose;
    opt->infos.wrong_tokens = false;
}

bool my_isflag(char *str)
{
    return (str[0] == OPTFLAGS.FLAG_PREFIX && str[1] != '\0');
}

size_t count_flags(int argc, char **argv)
{
    size_t count = 0;

    for (int i = 1; i < argc; i++)
        if (my_isflag(argv[i]))
            count += 1;
    return count;
}
