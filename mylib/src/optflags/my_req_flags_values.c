/*
** EPITECH PROJECT, 2021
** my_req_flags_values.c
** File description:
** Verifies flags/values matches
*/

#include "my_optflags.h"
#include "my_string.h"
#include "my_iostring.h"
#include "my_iochar.h"
#include "vocab.h"

#include <stdbool.h>

static bool has_value(optflags_t *opt, size_t flag_index)
{
    return opt->values[flag_index];
}

static bool is_a_reqvalue_flag(char *flag)
{
    for (size_t i = 0; OPTFLAGS.REQ_VALUE_FLAGS[i]; i++)
        if (!my_strcmp(flag, OPTFLAGS.REQ_VALUE_FLAGS[i]))
            return true;
    return false;
}

static void error(optflags_t *opt, char *flag)
{
    if (!opt->infos.verbose)
        return;
    my_puterr(OPTFLAGS_MSG.ERR_REQ_VALUE_FLAG);
    my_puterr(flag);
    my_putchar_err('\n');
}

bool my_req_flags_values(optflags_t *opt)
{
    bool req_ok = true;

    if (!opt)
        return false;
    for (size_t i = 0; i < opt->nb_flags; i++) {
        if (is_a_reqvalue_flag(opt->flags[i]) && !has_value(opt, i)) {
            req_ok = false;
            error(opt, opt->flags[i]);
        }
        if (!req_ok && !opt->infos.verbose)
            break;
    }
    return req_ok;
}
