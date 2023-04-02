/*
** EPITECH PROJECT, 2021
** my_fetch_flag_value.c
** File description:
** Optflags fetch flag value functions
*/

#include "my_optflags.h"
#include "my_string.h"
#include "my_linked_list.h"

#include <stddef.h>
#include <stdlib.h>

static void this_push_data(optflags_t *opt, node_t **list, size_t index)
{
    size_t data_size = 0;
    char *empty_str = NULL;

    if (!opt->values[index]) {
        empty_str = my_create_empty_string();
        if (!empty_str)
            return;
        my_push_head(list, empty_str, sizeof(char));
        free(empty_str);
    } else {
        data_size = (my_strlen(opt->values[index]) + 1) * sizeof(char);
        my_push_head(list, opt->values[index], data_size);
    }
}

node_t *my_fetchall_flag_values(optflags_t *opt, char *flag)
{
    node_t *list = my_create_linked_list();

    if (!list)
        return NULL;
    for (size_t i = 0; i < opt->nb_flags; i++)
        if (!my_strcmp(opt->flags[i], flag))
            this_push_data(opt, &list, i);
    my_revlist(&list);
    my_shift(&list);
    return list;
}

char *my_fetch_first_flag_value(optflags_t *opt, char *flag)
{
    for (size_t i = 0; i < opt->nb_flags; i++)
        if (!my_strcmp(opt->flags[i], flag))
            return opt->values[i];
    return NULL;
}
