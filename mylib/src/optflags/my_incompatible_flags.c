/*
** EPITECH PROJECT, 2021
** my_incompatible_flags.c
** File description:
** Manage incompatible flags
*/

#include "my_linked_list.h"
#include "my_optflags.h"
#include "my_iostring.h"
#include "my_iochar.h"
#include "my_string.h"
#include "vocab.h"

#include <stdbool.h>

static void error(
    char *flag_a, char *flag_b, optflags_t *opt, node_t **handled_flags
)
{
    size_t data_size = 0;

    if (handled_flags) {
        if (my_includes_str(*handled_flags, flag_a))
            return;
        if (my_includes_str(*handled_flags, flag_b))
            return;
    }
    if (opt->infos.verbose) {
        my_puterr(OPTFLAGS_MSG.ERR_INCOMPATIBLE_FLAGS);
        my_puterr(flag_a);
        my_puterr(", ");
        my_puterr(flag_b);
        my_putchar_err('\n');
        data_size = (my_strlen(flag_a) + 1) * sizeof(char);
        my_push_head(handled_flags, flag_a, data_size);
        data_size = (my_strlen(flag_b) + 1) * sizeof(char);
        my_push_head(handled_flags, flag_b, data_size);
    }
}

bool my_incompatible_flags(optflags_t *opt)
{
    size_t row = 0;
    char *flag_a = NULL;
    char *flag_b = NULL;
    node_t *handled_flags = NULL;
    bool incompatible_flags = false;

    for (row = 0; OPTFLAGS.INCOMPATIBLE_FLAGS[row][0]; row++) {
        flag_a = OPTFLAGS.INCOMPATIBLE_FLAGS[row][0];
        flag_b = OPTFLAGS.INCOMPATIBLE_FLAGS[row][1];
        if (my_includes_flag(opt, flag_a) && my_includes_flag(opt, flag_b)) {
            error(flag_a, flag_b, opt, &handled_flags);
            incompatible_flags = true;
        }
        if (incompatible_flags && !opt->infos.verbose)
            break;
    }
    my_linked_list_destroyer(&handled_flags);
    return incompatible_flags;
}
