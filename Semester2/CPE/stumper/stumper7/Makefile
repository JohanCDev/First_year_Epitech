##
## EPITECH PROJECT, 2021
## Duo-7
## File description:
## Makefile
##

SRC	=	src/main.c				\
		src/display.c			\
		src/get_cmd.c			\
		src/get_input.c			\
		src/my_frees.c			\
		src/check_args.c		\
		src/tool_fonctions.c	\
		src/db_management.c		\
		src/sort_management.c		\
		src/sort_films.c		\
		src/swap_func.c		\

NAME	=	mydb

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I include -W -Wall -Wextra -Wshadow

CC	=	gcc

SRC_T 	=		src/get_cmd.c				\
				src/tool_fonctions.c		\
				tests/tests.c				\

TEST_N	=	unit_tests

T_FLAGS	=	-lcriterion --coverage

all:	$(NAME)

$(NAME):	$(OBJ)
		$(MAKE) -C ./lib/my/
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -L./lib/my -lmy -lm

tests_run:
		$(MAKE) -C ./lib/my
		gcc -o $(TEST_N) $(SRC_T) $(CFLAGS) $(T_FLAGS)
		./unit_tests
		gcovr --exclude tests/
		gcovr --exclude tests/ --branches

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)
		# make fclean -C ./tests
re:		fclean all

debug	: CFLAGS += -g
debug	: re

.PHONY: all clean fclean re tests_run debug