/*
** EPITECH PROJECT, 2021
** my_revint.c
** File description:
** Reverse an int value
*/

int my_revint(int value)
{
    int res = 0;

    while (value) {
        res *= 10;
        res += value % 10;
        value /= 10;
    }
    return res;
}
