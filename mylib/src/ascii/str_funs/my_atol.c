/*
** EPITECH PROJECT, 2021
** my_atol.c
** File description:
** Takes a string like "1234" and returns a long like `1234`
*/

#include "my_math_parity.h"
#include "ascii_consts.h"

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

static int8_t sign_multiplicator(uint8_t minus)
{
    if (MY_ISODD_U(minus))
        return -1;
    return 1;
}

static int64_t retrieve_number(const char *str, uint16_t index, uint8_t minus)
{
    int64_t nbr = 0;

    while ((str[index] >= '0' && str[index] <= '9') && str[index] != '\0') {
        nbr += (str[index] - ASCII_CONSTS.CTOI_DELTA);
        if (str[index + 1] >= '0' && str[index + 1] <= '9')
            nbr *= 10;
        index += 1;
    }
    nbr *= sign_multiplicator(minus);
    return nbr;
}

int64_t my_atol(char *str)
{
    size_t index = 0;
    uint8_t minus = 0;

    while (!(str[index] >= '0' && str[index] <= '9') && str[index] != '\0') {
        if (str[index] == '-')
            minus += 1;
        index += 1;
    }
    if (str[index] == '\0')
        return 0;
    return (retrieve_number(str, index, minus));
}
