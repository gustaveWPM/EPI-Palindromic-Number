/*
** EPITECH PROJECT, 2021
** my_itobase.c
** File description:
** Converts an int into a str with the given base (min: base2, max: base16)
*/

#include "my_string.h"
#include "my_char.h"
#include "my_maths_consts.h"
#include "ascii_consts.h"

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

static bool cant_process(int8_t base, char *value, char *cur_base)
{
    if (!my_strchars(value, cur_base))
        return true;
    if (base < 2 || base > 16)
        return true;
    return false;
}

static int process_my_basetoi(
    int8_t base, char *cur_base, char *value, size_t length
)
{
    long long res = 0;
    long long power = 1;

    if (cant_process(base, value, cur_base))
        return -1;
    my_revstr(value);
    for (size_t i = 0; i < length; i++) {
        if (res > INT_MAX)
            return -1;
        if (my_is_digitchar(value[i]))
            res += (value[i] - ASCII_CONSTS.CTOI_DELTA) * power;
        if (my_is_alphachar(value[i]))
            res += (value[i] - MATHS_CONSTS.HEXALPHATOI_DELTA) * power;
        power = power * base;
    }
    return (int) res;
}

int my_basetoi(char *number, int8_t base)
{
    size_t length = my_strlen(number);
    int res = 0;
    char *value = my_strdup(number);
    char *cur_base = NULL;

    if (!value)
        return -1;
    cur_base = my_strndup(MATHS_CONSTS.BASE, base);
    if (!cur_base) {
        free(value);
        return -1;
    }
    my_str_uppercase(value);
    res = process_my_basetoi(base, cur_base, value, length);
    free(value);
    free(cur_base);
    return res;
}
