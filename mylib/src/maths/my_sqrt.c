/*
** EPITECH PROJECT, 2021
** my_sqrt.c
** File description:
** Sqrt
*/

int my_sqrt_i(int x)
{
    int start = 1;
    int end = x;
    int mid = 0;

    if (x < 0)
        return -1;
    if (x == 0 || x == 1)
        return x;
    while (start <= end) {
        mid = (start + end) / 2;
        if (mid * mid == x)
            return mid;
        if (mid <= x / mid)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}
