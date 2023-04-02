##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## MyLib Makefile
##

#=======================
# * ... Flags
#=======================

MAKEFLAGS			=	--silent
TESTS_LDLIBS		=	--coverage -lcriterion
CFLAGS				=	-Wall -Wextra -O3

# * ... Headers
CPPFLAGS			=	-I../mylib/headers/							\
						-I../mylib/headers/ascii/					\
						-I../mylib/headers/maths/					\
						-I../mylib/headers/optflags/				\
						-I../mylib/headers/ptr/						\
						-I../mylib/headers/two_dims_arrays/

# * ... Headers modules
CPPFLAGS			+=	-I../mylib/headers/ascii/modules/			\
						-I../mylib/headers/maths/modules/			\
						-I../mylib/headers/ptr/modules/				\
						-I../mylib/headers/two_dims_arrays/modules/

# * ... Unit tests headers
CPPFLAGS			+=	-I./headers/

# * ... Project headers
CPPFLAGS			+=	-I../project/headers

#=======================
# * ... Paths, filenames
#=======================

PROJECT_SRC_PATH		=	../project
PROJECT_ALGO_SRC_PATH	=	../project/algo

LIB_PATH				=	../mylib
MY_LIB_PATH				=	$(LIB_PATH)/src

LIB_BINARY_DEST			=	$(DEST)/libmy.a
UNIT_TESTS_FILE			=	unit_tests

#=======================
# * ... Tests Paths
#=======================

TESTS_PATH			=	.
ASCII_TESTS_PATH	=	$(TESTS_PATH)/test_ascii
MATHS_TESTS_PATH	=	$(TESTS_PATH)/test_maths
OPTFLAGS_TESTS_PATH	=	$(TESTS_PATH)/test_optflags
PTR_TESTS_PATH		=	$(TESTS_PATH)/test_ptr
PROJECT_TESTS_PATH	=	$(TESTS_PATH)/test_project

#=======================
# * ... Config
#=======================

CC					=	gcc
DEST				=	../
UNIT_TESTS_DEST		=	$(TESTS_PATH)/$(UNIT_TESTS_FILE)
LDFLAGS				=	-lmy --coverage -lcriterion -L../

#=======================
# * ... Lib Paths
#=======================

TWO_DIMS_ARRAYS_FUNS_PATH	=	$(MY_LIB_PATH)/two_dims_arrays
ASCII_FUNS_PATH				=	$(MY_LIB_PATH)/ascii
MATHS_FUNS_PATH				=	$(MY_LIB_PATH)/maths
OPTFLAGS_FUNS_PATH			=	$(MY_LIB_PATH)/optflags
PTR_FUNS_PATH				=	$(MY_LIB_PATH)/ptr

CHAR_FUNS_PATH				=	$(ASCII_FUNS_PATH)/char_funs
IOCHAR_FUNS_PATH			=	$(ASCII_FUNS_PATH)/iochar_funs
IOSTR_FUNS_PATH				=	$(ASCII_FUNS_PATH)/iostr_funs
STR_FUNS_PATH				=	$(ASCII_FUNS_PATH)/str_funs
STRTYPES_FUNS_PATH			=	$(ASCII_FUNS_PATH)/strtypes_funs

#=======================
# * ... Lib SRC
#=======================

#-----------------------
# * ... ASCII
#-----------------------
# * ... CHAR FUNS
#-----------------------
LIB_SRC				=	$(CHAR_FUNS_PATH)/my_char_in_str.c			\
						$(CHAR_FUNS_PATH)/my_char_togglecase.c		\
						$(CHAR_FUNS_PATH)/my_is_alphachar.c			\
						$(CHAR_FUNS_PATH)/my_is_alphanum_char.c		\
						$(CHAR_FUNS_PATH)/my_is_digitchar.c			\
						$(CHAR_FUNS_PATH)/my_is_lowerchar.c			\
						$(CHAR_FUNS_PATH)/my_is_printablechar.c		\
						$(CHAR_FUNS_PATH)/my_is_upperchar.c

#-----------------------
# * ... STRTYPES FUNS
#-----------------------
LIB_SRC				+=	$(STRTYPES_FUNS_PATH)/my_isalpha.c			\
						$(STRTYPES_FUNS_PATH)/my_isalphanum.c		\
						$(STRTYPES_FUNS_PATH)/my_isdigit.c			\
						$(STRTYPES_FUNS_PATH)/my_islower.c			\
						$(STRTYPES_FUNS_PATH)/my_isprintable.c		\
						$(STRTYPES_FUNS_PATH)/my_isupper.c			\
						$(STRTYPES_FUNS_PATH)/utils.c

#-----------------------
# * ... IOCHAR FUNS
#-----------------------
LIB_SRC				+=	$(IOCHAR_FUNS_PATH)/my_putchar.c

#-----------------------
# * ... IOSTR FUNS
#-----------------------
LIB_SRC				+=	$(IOSTR_FUNS_PATH)/my_getline.c				\
						$(IOSTR_FUNS_PATH)/my_putnbr.c				\
						$(IOSTR_FUNS_PATH)/my_putstr.c				\
						$(IOSTR_FUNS_PATH)/my_tokenize_file.c

#-----------------------
# * ... STR FUNS
#-----------------------
LIB_SRC				+=	$(STR_FUNS_PATH)/my_atol.c							\
						$(STR_FUNS_PATH)/my_is_empty_str.c					\
						$(STR_FUNS_PATH)/my_revstr.c						\
						$(STR_FUNS_PATH)/my_str_alphabetical_order_cmp.c	\
						$(STR_FUNS_PATH)/my_str_togglecase.c				\
						$(STR_FUNS_PATH)/my_str_capitalize.c				\
						$(STR_FUNS_PATH)/my_str_sanitize.c					\
						$(STR_FUNS_PATH)/my_strcmp.c						\
						$(STR_FUNS_PATH)/my_strcat.c						\
						$(STR_FUNS_PATH)/my_strchars.c						\
						$(STR_FUNS_PATH)/my_strcpy.c						\
						$(STR_FUNS_PATH)/my_strdup.c						\
						$(STR_FUNS_PATH)/my_strlen.c						\
						$(STR_FUNS_PATH)/my_strsplit.c						\
						$(STR_FUNS_PATH)/my_tokenizer.c						\
						$(STR_FUNS_PATH)/my_tr.c

#-----------------------
# * ... MATHS FUNS
#-----------------------
LIB_SRC				+=	$(MATHS_FUNS_PATH)/my_abs.c					\
						$(MATHS_FUNS_PATH)/my_basetoi.c				\
						$(MATHS_FUNS_PATH)/my_factorial.c			\
						$(MATHS_FUNS_PATH)/my_itobase.c				\
						$(MATHS_FUNS_PATH)/my_pow.c					\
						$(MATHS_FUNS_PATH)/my_revint.c				\
						$(MATHS_FUNS_PATH)/my_sqrt.c

#-----------------------
# * ... OPTFLAGS FUNS
#-----------------------
LIB_SRC				+=	$(OPTFLAGS_FUNS_PATH)/my_count_flags_occurrences.c		\
						$(OPTFLAGS_FUNS_PATH)/my_fetch_flag_value.c				\
						$(OPTFLAGS_FUNS_PATH)/my_flags_precedences.c			\
						$(OPTFLAGS_FUNS_PATH)/my_optflags_builder.c				\
						$(OPTFLAGS_FUNS_PATH)/my_optflags_destroy.c				\
						$(OPTFLAGS_FUNS_PATH)/my_includes_flag.c				\
						$(OPTFLAGS_FUNS_PATH)/my_incompatible_flags.c			\
						$(OPTFLAGS_FUNS_PATH)/my_req_flags_values.c				\
						$(OPTFLAGS_FUNS_PATH)/my_uniq_flags.c					\
						$(OPTFLAGS_FUNS_PATH)/my_unknown_flags.c				\
						$(OPTFLAGS_FUNS_PATH)/my_optflags_utils.c

#-----------------------
# * ... PTR FUNS
#-----------------------
LIB_SRC				+=	$(PTR_FUNS_PATH)/my_generic_linked_list_cast.c		\
						$(PTR_FUNS_PATH)/my_generic_linked_list_count.c		\
						$(PTR_FUNS_PATH)/my_generic_linked_list_del.c		\
						$(PTR_FUNS_PATH)/my_generic_linked_list_fetch.c		\
						$(PTR_FUNS_PATH)/my_generic_linked_list_fetchall.c	\
						$(PTR_FUNS_PATH)/my_generic_linked_list_includes.c	\
						$(PTR_FUNS_PATH)/my_generic_linked_list_popshift.c	\
						$(PTR_FUNS_PATH)/my_generic_linked_list_push.c		\
						$(PTR_FUNS_PATH)/my_generic_linked_list.c			\
						$(PTR_FUNS_PATH)/my_swap.c

#-----------------------
# * ... 2D ARRAYS FUNS
#-----------------------
LIB_SRC				+=	$(TWO_DIMS_ARRAYS_FUNS_PATH)/my_two_dims_arrays_flatten.c	\
						$(TWO_DIMS_ARRAYS_FUNS_PATH)/my_two_dims_arrays.c

#=======================
# * ... Tests SRC
#=======================

#-----------------------
# * ... Append Lib SRC
#-----------------------
TESTS_SRC			=	$(LIB_SRC)

#-----------------------
# * ... Listeners
#-----------------------
TESTS_SRC			+=	$(TESTS_PATH)/listeners/my_criterion_listener.c

#-----------------------
# * ... Debug
#-----------------------
TESTS_SRC			+=	$(TESTS_PATH)/debug/my_linked_lists_debug.c		\
						$(TESTS_PATH)/debug/my_optflags_debug.c

#-----------------------
# * ... ASCII Tests
#-----------------------

TESTS_SRC			+=	$(ASCII_TESTS_PATH)/char_funs.c			\
						$(ASCII_TESTS_PATH)/iochar_funs.c		\
						$(ASCII_TESTS_PATH)/iostr_funs.c		\
						$(ASCII_TESTS_PATH)/str_funs.c			\
						$(ASCII_TESTS_PATH)/strtypes_funs.c

#-----------------------
# * ... MATHS Tests
#-----------------------
TESTS_SRC			+=	$(MATHS_TESTS_PATH)/maths_funs.c

#-----------------------
# * ... OPTFLAGS Tests
#-----------------------

TESTS_SRC			+=	$(OPTFLAGS_TESTS_PATH)/optflags_funs.c

#-----------------------
# * ... PTR Tests
#-----------------------
TESTS_SRC			+=	$(PTR_TESTS_PATH)/my_linked_lists_funs.c	\
						$(PTR_TESTS_PATH)/my_swap_funs.c

#-----------------------
# * ... Project Tests
#-----------------------
TESTS_SRC			+=	$(PROJECT_TESTS_PATH)/error_management.c	\
						$(PROJECT_TESTS_PATH)/nflag_iminmax.c		\
						$(PROJECT_TESTS_PATH)/nflag.c				\
						$(PROJECT_TESTS_PATH)/pflag_iminmax.c		\
						$(PROJECT_TESTS_PATH)/pflag.c				\
						$(PROJECT_TESTS_PATH)/requirement.c

#=======================
# * ... Project SRC
#=======================

PROJECT_SRC			=	$(PROJECT_SRC_PATH)/edge_case_error_handling.c	\
						$(PROJECT_SRC_PATH)/inject_values_internals.c	\
						$(PROJECT_SRC_PATH)/inject_values.c				\
						$(PROJECT_SRC_PATH)/entry_point.c				\
						$(PROJECT_SRC_PATH)/msg.c						\
						$(PROJECT_SRC_PATH)/run.c						\
						$(PROJECT_SRC_PATH)/terminate.c

#-----------------------
# * ... Algo
#-----------------------

PROJECT_SRC			+=	$(PROJECT_ALGO_SRC_PATH)/compute_palindrome.c	\
						$(PROJECT_ALGO_SRC_PATH)/is_palindrome.c		\
						$(PROJECT_ALGO_SRC_PATH)/n_procedure.c			\
						$(PROJECT_ALGO_SRC_PATH)/p_baseten_opti.c		\
						$(PROJECT_ALGO_SRC_PATH)/p_procedure.c

#-----------------------
# * ... Requirement
#-----------------------

PROJECT_SRC			+=	../requirement.c

#=======================
# * ... OBJs
#=======================
PROJECT_OBJ			=	$(PROJECT_SRC:.c=.o)
LIB_OBJ				=	$(LIB_SRC:.c=.o)

OBJ					=	$(PROJECT_OBJ) + $(LIB_OBJ)

RM_OBJ				=	@rm -f $(OBJ)
RM_LIB				=	@rm -f $(LIB_BINARY_DEST)

#=======================
# * ... Unit test cleans
#=======================
GCNO_GARBAGE		=	"*.gcno"
GCDA_GARBAGE		=	"*.gcda"

RM_TESTS_FILES		=	@rm -f $(UNIT_TESTS_DEST) \
						&& find . \( -name $(GCNO_GARBAGE) -o -name $(GCDA_GARBAGE) \) -type f -delete

#=======================
# * ... Recipes
#=======================
.PHONY: all tests_run clean fclean re $(UNIT_TESTS_DEST)

all:	$(LIB_OBJ)
	ar rc $(LIB_BINARY_DEST) $(LIB_OBJ)

$(UNIT_TESTS_DEST):
			$(RM_TESTS_FILES)
			@$(CC) -o $(UNIT_TESTS_DEST) $(TESTS_SRC) $(PROJECT_SRC) $(LDFLAGS) $(CPPFLAGS)

tests_run:	all $(UNIT_TESTS_DEST)
			@./$(UNIT_TESTS_DEST)

clean:
			$(RM_OBJ)
			$(RM_TESTS_FILES)

fclean:		clean
			@rm -f $(LIB_BINARY_DEST)

re: 		fclean all
