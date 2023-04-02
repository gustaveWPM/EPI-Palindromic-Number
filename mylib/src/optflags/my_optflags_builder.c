/*
** EPITECH PROJECT, 2021
** my_optflags_builder.c
** File description:
** Builds a optflags struct, helping to manage flags
*/

#include "vocab.h"
#include "my_optflags.h"
#include "my_string.h"
#include "my_iostring.h"

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

static void this_memset(void **ptr, size_t max)
{
    for (size_t offset = 0; offset <= max; offset++)
        *(ptr + offset) = NULL;
}

static optflags_t *initialize_opt_struct(
    int argc, char **argv, bool strict_mode, bool verbose
)
{
    optflags_t *opt = malloc(sizeof(optflags_t));

    if (!opt)
        return NULL;
    set_opt_infos(opt, strict_mode, verbose);
    opt->nb_flags = count_flags(argc, argv);
    opt->flags = malloc((opt->nb_flags + 1) * sizeof(char *));
    if (!opt->flags) {
        free(opt);
        return NULL;
    }
    this_memset((void **) opt->flags, opt->nb_flags);
    opt->values = malloc((opt->nb_flags + 1) * sizeof(char *));
    if (!opt->values) {
        my_optflags_destroy(&opt);
        return NULL;
    }
    this_memset((void **) opt->values, opt->nb_flags);
    return opt;
}

static bool unexpected_token(char **argv, int i, optflags_t *opt)
{
    bool unexpected_token = false;

    if (!my_isflag(argv[i]) && i > 0 && !my_isflag(argv[i - 1])) {
        opt->infos.wrong_tokens = true;
        unexpected_token = true;
    } else
        return false;
    if (unexpected_token && opt->infos.verbose) {
        if (opt->infos.strict_mode)
            my_puterr((char *) OPTFLAGS_MSG.ERR_UNEXPECTED_TOKEN);
        else
            my_puterr((char *) OPTFLAGS_MSG.WARN_UNEXPECTED_TOKEN);
        my_puterr(argv[i]);
        my_puterr("\n");
    }
    if (!opt->infos.strict_mode)
        opt->infos.wrong_tokens = false;
    return unexpected_token;
}

static bool fill_opt_struct(int argc, char **argv, optflags_t *opt)
{
    size_t flag_index = 0;
    size_t value_index = 0;

    for (int i = 1; i < argc; i++) {
        if (unexpected_token(argv, i, opt))
            continue;
        if (my_isflag(argv[i])) {
            opt->flags[flag_index] = my_strdup(argv[i]);
            flag_index += 1;
        }
        if (i + 1 < argc && my_isflag(argv[i]) && !my_isflag(argv[i + 1])) {
            opt->values[value_index] = my_strdup(argv[i + 1]);
            value_index += 1;
        }
        if (i + 1 < argc && my_isflag(argv[i]) && my_isflag(argv[i + 1])) {
            opt->values[value_index] = NULL;
            value_index += 1;
        }
    }
    return !opt->infos.wrong_tokens;
}

optflags_t *my_optflags_builder(
    int argc, char **argv, bool strict_mode, bool verbose
)
{
    optflags_t *opt = NULL;

    if (argc <= 1)
        return NULL;
    opt = initialize_opt_struct(argc, argv, strict_mode, verbose);
    if (!opt)
        return NULL;
    if (!fill_opt_struct(argc, argv, opt))
        my_optflags_destroy(&opt);
    if (my_unknown_flags(opt) && strict_mode)
        my_optflags_destroy(&opt);
    if (my_incompatible_flags(opt))
        my_optflags_destroy(&opt);
    if (!my_flags_precedences(opt))
        my_optflags_destroy(&opt);
    if (!my_uniq_flags(opt))
        my_optflags_destroy(&opt);
    if (!my_req_flags_values(opt))
        my_optflags_destroy(&opt);
    return opt;
}
