/*
** EPITECH PROJECT, 2021
** is_palindrome.c
** File description:
** Returns true if palindrome, otherwise false
*/

#include "my_string.h"
#include "my_itobase.h"

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

bool is_palindrome(int nb, uint8_t base)
{
    char *rpz = my_itobase(nb, base);
    char *reversed_rpz = NULL;
    bool is_pal = false;

    if (!rpz)
        return false;
    if (my_basetoi(rpz, base) == -1) {
        free(rpz);
        return false;
    }
    reversed_rpz = my_create_revstr(rpz);
    if (!reversed_rpz) {
        free(rpz);
        return false;
    }
    if (!my_strcmp(rpz, reversed_rpz))
        is_pal = true;
    free(reversed_rpz);
    free(rpz);
    return is_pal;
}
