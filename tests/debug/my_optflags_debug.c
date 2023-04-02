/*
** EPITECH PROJECT, 2021
** my_optflags_debug.c
** File description:
** Optflags debug functions
*/

#include "my_optflags.h"
#include "my_iostring.h"
#include "my_iochar.h"

#include <stddef.h>

static void display_flag(optflags_t *opt, size_t index)
{
    my_puterr("Flag n°");
    my_putchar_err(index + '0');
    my_puterr(": ");
    my_puterr(opt->flags[index]);
    my_putchar_err('\n');
}

static void display_value(optflags_t *opt, size_t index)
{
    my_puterr("Value n°");
    my_putchar_err(index + '0');
    my_puterr(": ");
    if (opt->values[index])
        my_puterr(opt->values[index]);
    else
        my_puterr("NULL");
    my_putchar_err('\n');
}

void display_flags(optflags_t *opt)
{
    if (!opt)
        return;
    for (size_t i = 0; opt->flags[i]; i++)
        display_flag(opt, i);
}

void display_values(optflags_t *opt)
{
    if (!opt)
        return;
    for (size_t i = 0; opt->flags[i]; i++)
        display_value(opt, i);
}

void display_tassoc(optflags_t *opt)
{
    if (!opt)
        return;
    for (size_t i = 0; opt->flags[i]; i++) {
        display_flag(opt, i);
        display_value(opt, i);
    }
}
