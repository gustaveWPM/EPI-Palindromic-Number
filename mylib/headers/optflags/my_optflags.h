/*
** EPITECH PROJECT, 2021
** my_optflags.h
** File description:
** my_optflags config and structs
*/

#ifndef MY_OPTFLAGS_CONFIG_H
    #define MY_OPTFLAGS_CONFIG_H
    #include <stddef.h>
    static const struct {
        char FLAG_PREFIX;
        char *KNOWN_FLAGS[7];
        char *UNIQ_FLAGS[7];
        char *REQ_VALUE_FLAGS[6];
        char *INCOMPATIBLE_FLAGS[2][3];
        char *FLAGS_PRECEDENCES[1][1];
    } OPTFLAGS = {
        '-',
        {
            "-h", "-n", "-p", "-b", "-imin", "-imax", NULL
        },
        {
            "-h", "-n", "-p", "-b", "-imin", "-imax", NULL
        },
        {
            "-n", "-p", "-b", "-imin", "-imax", NULL
        },
        {
            {"-n", "-p", NULL},
            {NULL, NULL, NULL}
        },
        {
            {NULL}
        },
    };
#endif

#ifndef MY_OPTFLAGS_STRUCTS_H
    #define MY_OPTFLAGS_STRUCTS_H
    #include <stddef.h>
    #include <stdbool.h>

    typedef struct optflags_infos_s {
        bool verbose;
        bool strict_mode;
        bool wrong_tokens;
    } optflags_infos_t;

    typedef struct optflags_s {
        char **flags;
        char **values;
        size_t nb_flags;
        optflags_infos_t infos;
    } optflags_t;
#endif

#ifndef MY_OPTFLAGS_PROTOTYPES_H
    #define MY_OPTFLAGS_PROTOTYPES_H
    #include "my_linked_list.h"
    #include <stddef.h>
    #include <stdbool.h>
    optflags_t *my_optflags_builder(
        int argc, char **argv, bool strict_mode, bool verbose
    );
    void set_opt_infos(optflags_t *opt, bool strict_mode, bool verbose);
    void my_optflags_destroy(optflags_t **opt);

    bool my_incompatible_flags(optflags_t *opt);
    size_t count_flags(int argc, char **argv);
    size_t my_count_flags_occurrences(optflags_t *opt, char *flag);
    bool my_isflag(char *str);

    void display_tassoc(optflags_t *opt);
    void display_values(optflags_t *opt);
    void display_flags(optflags_t *opt);

    bool my_flags_precedences(optflags_t *opt);
    bool my_unknown_flags(optflags_t *opt);
    bool my_uniq_flags(optflags_t *opt);
    bool my_includes_flag(optflags_t *opt, char *flag);
    bool my_req_flags_values(optflags_t *opt);

    node_t *my_fetchall_flag_values(optflags_t *opt, char *flag);
    char *my_fetch_first_flag_value(optflags_t *opt, char *flag);
#endif
