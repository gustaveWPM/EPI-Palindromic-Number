/*
** EPITECH PROJECT, 2021
** edge_case_error_handling.c
** File description:
** Verifies the len of each flag to add another int overflow detection
*/

#include "my_optflags.h"
#include "my_string.h"

#include "edge_cases_consts.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

static size_t str_begin_index(char *str)
{
    size_t begin_index = 0;

    for (size_t i = 0; str[i] == '0'; i++)
        str[i] = 'A';
    for (; str[begin_index] == 'A'; begin_index++);
    return begin_index;
}

static bool invalid_flag_value(optflags_t *opt, char *flag)
{
    size_t str_len = 0;
    size_t begin_index = 0;
    char *str_rpz = NULL;

    if (!my_includes_flag(opt, flag))
        return false;
    str_rpz = my_strdup(my_fetch_first_flag_value(opt, flag));
    if (!str_rpz)
        return false;
    if (str_rpz[0] == '0')
        begin_index = str_begin_index(str_rpz);
    str_len = my_strlen(&str_rpz[begin_index]);
    free(str_rpz);
    if (str_len > MAX_INT_STR_LEN)
        return true;
    return false;
}

bool one_more_error_handling(optflags_t *opt)
{
    if (invalid_flag_value(opt, "-n"))
        return true;
    if (invalid_flag_value(opt, "-p"))
        return true;
    if (invalid_flag_value(opt, "-b"))
        return true;
    if (invalid_flag_value(opt, "-imax"))
        return true;
    if (invalid_flag_value(opt, "-imin"))
        return true;
    return false;
}
