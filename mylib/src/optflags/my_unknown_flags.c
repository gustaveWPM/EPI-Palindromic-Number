/*
** EPITECH PROJECT, 2021
** my_unknown_flags.c
** File description:
** Manage unknown flags
*/

#include "my_optflags.h"
#include "my_two_dims_arrays.h"
#include "my_string.h"
#include "my_iostring.h"
#include "my_iochar.h"
#include "vocab.h"
#include "my_linked_list.h"

#include <stdbool.h>

static bool my_known_flag(char *flag)
{
    for (size_t i = 0; OPTFLAGS.KNOWN_FLAGS[i]; i++)
        if (!my_strcmp(OPTFLAGS.KNOWN_FLAGS[i], flag))
            return true;
    return false;
}

static void error(bool strict_mode, bool verbose, char *flag, node_t **h_flags)
{
    size_t data_size = 0;

    if (!verbose)
        return;
    if (h_flags)
        if (my_includes_str(*h_flags, flag))
            return;
    if (strict_mode)
        my_puterr(OPTFLAGS_MSG.ERR_UNKNOWN_FLAG);
    else
        my_puterr(OPTFLAGS_MSG.WARN_UNKNOWN_FLAG);
    my_puterr(flag);
    my_putchar_err('\n');
    data_size = (my_strlen(flag) + 1) * sizeof(char);
    my_push_head(h_flags, flag, data_size);
}

bool my_unknown_flags(optflags_t *opt)
{
    bool unknown_flags = false;
    bool strict_mode = false;
    bool verbose = false;
    node_t *handled_flags = NULL;

    if (!opt)
        return true;
    strict_mode = opt->infos.strict_mode;
    verbose = opt->infos.verbose;
    for (size_t i = 0; opt->flags[i]; i++) {
        if (!my_known_flag(opt->flags[i])) {
            unknown_flags = true;
            error(strict_mode, verbose, opt->flags[i], &handled_flags);
        }
        if (unknown_flags && !verbose)
            break;
    }
    if (!strict_mode)
        unknown_flags = false;
    my_linked_list_destroyer(&handled_flags);
    return unknown_flags;
}
