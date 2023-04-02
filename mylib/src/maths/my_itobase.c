/*
** EPITECH PROJECT, 2021
** my_itobase.c
** File description:
** Converts an int into a str with the given base (min: base2, max: base16)
*/

#include "my_maths_consts.h"
#include "my_string.h"

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

static char *this_create_zero_str(void)
{
    char *zero_str = malloc(2 * sizeof(char));

    if (!zero_str)
        return NULL;
    zero_str[0] = '0';
    zero_str[1] = '\0';
    return zero_str;
}

static char *this_allocate(int memo_value, uint8_t base)
{
    size_t memsize = 0;
    char *to_base = NULL;
    const size_t PADDING_QUICKFIX = 10;

    while (memo_value) {
        memo_value /= base;
        memsize += 1;
    }
    to_base = malloc((memsize + PADDING_QUICKFIX) * sizeof(char));
    if (!to_base)
        return NULL;
    to_base[memsize - 1] = '\0';
    return to_base;
}

char *my_itobase(unsigned int value, uint8_t base)
{
    size_t i = 0;
    char *to_base = NULL;

    if (value == 0)
        return (this_create_zero_str());
    if (base < 2 || base > 16)
        return NULL;
    to_base = this_allocate(value, base);
    if (!to_base)
        return NULL;
    while (value) {
        to_base[i] = MATHS_CONSTS.BASE[value % base];
        value /= base;
        i += 1;
    }
    to_base[i] = '\0';
    my_revstr(to_base);
    return to_base;
}
