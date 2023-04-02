/*
** EPITECH PROJECT, 2021
** char_togglecase.c
** File description:
** Downcase/upcase a character
*/

#include "my_char.h"
#include "ascii_consts.h"

void my_char_upcase(char *c)
{
    if (!my_is_lowerchar(*c))
        return;
    *c -= ASCII_CONSTS.DOWNCASE_ASCII_DELTA;
}

void my_char_downcase(char *c)
{
    if (!my_is_upperchar(*c))
        return;
    *c += ASCII_CONSTS.DOWNCASE_ASCII_DELTA;
}

void my_char_togglecase(char *c)
{
    if (my_is_upperchar(*c)) {
        my_char_downcase(c);
        return;
    }
    my_char_upcase(c);
}
