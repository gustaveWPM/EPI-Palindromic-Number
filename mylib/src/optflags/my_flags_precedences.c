/*
** EPITECH PROJECT, 2021
** my_flags_precedences.c
** File description:
** Returns true if flags precedences is OK
*/

#include "my_optflags.h"
#include "my_iostring.h"
#include "my_string.h"
#include "my_iochar.h"
#include "vocab.h"

#include <stddef.h>
#include <stdbool.h>

static void error(optflags_t *opt, char *flag_a, char *flag_b)
{
    if (!opt->infos.verbose)
        return;
    my_puterr(OPTFLAGS_MSG.ERR_FLAGS_PRECEDENCE);
    my_puterr(flag_a);
    my_puterr(" SHOULD PRECEDE ");
    my_puterr(flag_b);
    my_putchar_err('\n');
}

static bool handler(char *flag_a, char *flag_b, optflags_t *opt, size_t index)
{
    if (index + 1 >= opt->nb_flags) {
        error(opt, flag_a, flag_b);
        return false;
    }
    if (my_strcmp(flag_b, opt->flags[index + 1])) {
        error(opt, flag_a, flag_b);
        return false;
    }
    return true;
}

static bool precedence_ok(optflags_t *opt, size_t index)
{
    char *flag_a = NULL;
    char *flag_b = NULL;
    bool try = false;

    for (size_t row = 0; OPTFLAGS.FLAGS_PRECEDENCES[row][0]; row++) {
        flag_a = OPTFLAGS.FLAGS_PRECEDENCES[row][0];
        flag_b = OPTFLAGS.FLAGS_PRECEDENCES[row][1];
        if (!my_strcmp(flag_a, opt->flags[index])) {
            try = true;
            break;
        }
    }
    if (try && !handler(flag_a, flag_b, opt, index))
        return false;
    return true;
}

bool my_flags_precedences(optflags_t *opt)
{
    bool precedences_ok = true;

    if (!opt)
        return false;
    for (size_t i = 0; i < opt->nb_flags; i++) {
        if (!precedence_ok(opt, i))
            precedences_ok = false;
        if (!precedences_ok && !opt->infos.verbose)
            break;
    }
    return precedences_ok;
}
