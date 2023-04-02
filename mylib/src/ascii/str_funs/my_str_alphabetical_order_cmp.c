/*
** EPITECH PROJECT, 2021
** str_alphabetical_order_cmp.c
** File description:
** {Deprecated: use my_strcmp} Compares two strings alphabetical order
*/

#include "my_string.h"
#include "my_safe_free.h"

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

static bool failed_to_dup(char *downcase_str_a, char *downcase_str_b)
{
    if (!downcase_str_a || !downcase_str_b) {
        if (downcase_str_a)
            MY_SAFE_FREE(downcase_str_a);
        if (downcase_str_b)
            MY_SAFE_FREE(downcase_str_b);
        return true;
    }
    return false;
}

static void downcase_strings(char *downcase_str_a, char *downcase_str_b)
{
    my_str_downcase(downcase_str_a);
    my_str_downcase(downcase_str_b);
}

static bool this_cmp(char *downcase_str_a, char *downcase_str_b, size_t *count)
{
    unsigned int i = 0;

    while (downcase_str_a[i] && downcase_str_b[i]) {
        if (downcase_str_a[i] > downcase_str_b[i])
            return true;
        if (downcase_str_a[i] < downcase_str_b[i])
            return false;
        if (downcase_str_a[i] == downcase_str_b[i])
            *count += 1;
        i += 1;
    }
    return false;
}

static void get_shortest_and_longest_str(
    char *str_a, char *str_b, char **shortest_str, char **longest_str
)
{
    if (my_strlen(str_a) > my_strlen(str_b)) {
        *shortest_str = str_b;
        *longest_str = str_a;
    } else {
        *shortest_str = str_a;
        *longest_str = str_b;
    }
}

bool str_alphabetical_order_cmp(char *str_a, char *str_b)
{
    char *downcase_str_a = my_strdup(str_a);
    char *downcase_str_b = my_strdup(str_b);
    char *shortest_str = NULL;
    char *longest_str = NULL;
    bool str_b_precedes_str_a = false;
    size_t count = 0;

    if (failed_to_dup(downcase_str_a, downcase_str_b))
        return false;
    downcase_strings(downcase_str_a, downcase_str_b);
    str_b_precedes_str_a = this_cmp(downcase_str_a, downcase_str_b, &count);
    MY_SAFE_FREE(downcase_str_a);
    MY_SAFE_FREE(downcase_str_b);
    get_shortest_and_longest_str(str_a, str_b, &shortest_str, &longest_str);
    if (count == my_strlen(shortest_str))
        if (my_strlen(longest_str) > my_strlen(shortest_str))
            return (my_strcmp(longest_str, str_a) == 0);
    return str_b_precedes_str_a;
}
