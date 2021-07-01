##
## EPITECH PROJECT, 2021
## Duo-7
## File description:
## Makefile
##

SRC_DIR		=	src/

INIT_DIR	=	initialize_and_check/

SRC			=	$(shell find ./src -name "*.c") \

SRC_T 		=	$(shell find ./lib/my -name "*.c") \
				$(SRC_DIR)$(INIT_DIR)check_args.c \
				$(SRC_DIR)$(INIT_DIR)initialize_structure.c \
				$(SRC_DIR)free_all.c \

TEST_FILES 	=	$(shell find ./tests -name "*.c") \
				$(shell find ./lib/tests -name "*.c") \

NAME		=	calendar

TEST_N		=	unit_tests

OBJ			=	$(SRC:.c=.o)

OBJTEST		=	$(SRC_T:.c=.o)

CFLAGS		=	-I./lib/my -I./include -W -Wall -Wextra -Wshadow

T_FLAGS		=	-I./lib/my -I./include -lcriterion --coverage

CC			=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
			$(MAKE) -C ./lib/my/
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -L./lib/my -lmy

tests_run:
			$(CC) -o $(TEST_N) $(TEST_FILES) $(SRC_T) $(T_FLAGS)
			./unit_tests --verbose
			gcovr --exclude-throw-branches --exclude-unreachable-branches -e lib/tests/ -e tests/ -e $(SRC_DIR)main.c -b

clean:
			@find -type f -name '*.o' -delete
			@find -type f -name '*.gcda' -delete
			@find -type f -name '*.gcno' -delete
			@find -type f -name 'vgcore.*' -delete

fclean:		clean
			rm -f $(NAME)
			rm -f $(TEST_N)
			make fclean -C ./lib/my
		

re:			fclean all

debug: 		CFLAGS += -g
debug: 		re

.PHONY: 	all clean fclean re tests_run debug