/*
** EPITECH PROJECT, 2021
** my_putnbr.c
** File description:
** Puts a nbr
*/

#include "my_iochar.h"

#include <stdint.h>
#include <unistd.h>

void my_dputnbr_rev(uint8_t fileno, long long nbr)
{
    unsigned int mod = 0;

    if (nbr < 0) {
        my_dputchar(fileno, '-');
        nbr *= -1;
    }
    if (nbr <= 9)
        my_dputchar(fileno, nbr + '0');
    if (nbr > 9) {
        mod = nbr % 10;
        my_dputchar(fileno, mod + '0');
        my_dputnbr_rev(fileno, nbr / 10);
    }
}

void my_dputnbr(uint8_t fileno, long long nbr)
{
    unsigned int mod = 0;

    if (nbr < 0) {
        my_dputchar(fileno, '-');
        nbr *= -1;
    }
    if (nbr <= 9)
        my_dputchar(fileno, nbr + '0');
    if (nbr > 9) {
        mod = nbr % 10;
        my_dputnbr(fileno, nbr / 10);
        my_dputchar(fileno, mod + '0');
    }
}

void my_putnbr_rev(long long nbr)
{
    my_dputnbr_rev(STDOUT_FILENO, nbr);
}

void my_putnbr(long long nbr)
{
    my_dputnbr(STDOUT_FILENO, nbr);
}
