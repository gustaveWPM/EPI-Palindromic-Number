/*
** EPITECH PROJECT, 2021
** my_uniq_flags.c
** File description:
** Optflags uniq flags management
*/

#include "my_optflags.h"
#include "my_string.h"
#include "my_iostring.h"
#include "my_iochar.h"
#include "vocab.h"

#include <stdbool.h>

static void error(optflags_t *opt, char *flag)
{
    if (!opt->infos.verbose)
        return;
    my_puterr(OPTFLAGS_MSG.ERR_UNIQ_FLAG);
    my_puterr(flag);
    my_putchar_err('\n');
}

static bool is_uniq(optflags_t *opt, char *flag)
{
    size_t count = my_count_flags_occurrences(opt, flag);

    if (count > 1) {
        error(opt, flag);
        return false;
    }
    return true;
}

bool my_uniq_flags(optflags_t *opt)
{
    bool uniq_flags = true;

    if (!opt)
        return false;
    for (size_t i = 0; OPTFLAGS.UNIQ_FLAGS[i]; i++) {
        if (!is_uniq(opt, OPTFLAGS.UNIQ_FLAGS[i]))
            uniq_flags = false;
        if (!uniq_flags && !opt->infos.verbose)
            break;
    }
    return uniq_flags;
}
