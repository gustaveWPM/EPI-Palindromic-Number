/*
** EPITECH PROJECT, 2021
** my_pow.c
** File description:
** Power function: my_pow(2, 3) <=> 2³ -> 8
*/

float my_pow(float value, int pow)
{
    float tmp = 0.0f;

    if (pow == 0)
        return 1;
    tmp = my_pow(value, pow / 2);
    if (pow % 2 == 0)
        return tmp * tmp;
    else {
        if (pow > 0)
            return value * tmp * tmp;
        else
            return (tmp * tmp) / value;
    }
}
