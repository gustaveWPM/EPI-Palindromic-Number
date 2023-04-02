##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## MyProject Makefile
##

#=======================
# * ... Paths, filenames
#=======================

NAME				=	palindrome
LIB					=	libmy.a

#=======================
# * ... Flags
#=======================

MAKEFLAGS			=	--silent
LDFLAGS				=	-L./mylib/ -lmy
CFLAGS				=	-Wall -Wextra -Ofast

# * ... Project headers
CPPFLAGS			=	-I./project/headers

# * ... Lib Headers
CPPFLAGS			+=	-I./mylib/headers/							\
						-I./mylib/headers/ascii/					\
						-I./mylib/headers/maths/					\
						-I./mylib/headers/optflags/					\
						-I./mylib/headers/ptr/						\
						-I./mylib/headers/two_dims_arrays/

# * ... Lib modules
CPPFLAGS			+=	-I./mylib/headers/ascii/modules/			\
						-I./mylib/headers/maths/modules/			\
						-I./mylib/headers/ptr/modules/				\
						-I./mylib/headers/two_dims_arrays/modules/

# * ... Project entry point
SRC					=	project/edge_case_error_handling.c			\
						project/inject_values_internals.c			\
						project/inject_values.c						\
						project/main.c								\
						project/entry_point.c						\
						project/msg.c								\
						project/run.c								\
						project/terminate.c

# * ... Project algorithm and internals
SRC					+=	project/algo/compute_palindrome.c			\
						project/algo/is_palindrome.c				\
						project/algo/n_procedure.c					\
						project/algo/p_baseten_opti.c				\
						project/algo/p_procedure.c

OBJ					=	$(SRC:.c=.o)

RM_OBJ				=	@rm -f $(OBJ)

CC					=	gcc

#=======================
# * ... Recipes
#=======================

.PHONY: all clean fclean re tests_run $(LIB)

$(NAME):	$(OBJ) $(LIB)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

$(LIB):
			make -C mylib/

tests_run:
			make -C tests/ tests_run

all:	$(NAME)

clean:
			$(RM_OBJ)
			make -C mylib/ fclean
			make -C tests/ fclean

fclean:		clean
			@rm -f $(NAME)

re: 		fclean all
