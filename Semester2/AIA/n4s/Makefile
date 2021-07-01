##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

DIR		=		src/

SRC     =       $(DIR)main.c \
				$(DIR)my_strtok.c \
				$(DIR)wheels.c \
				$(DIR)get_info_car.c \
				$(DIR)direction.c \
				$(DIR)speed.c \

OBJ     =       $(SRC:.c=.o)

NAME    =       ai

CC		=		gcc

CFLAGS  =       -Wall -Wshadow -Wextra -I./include -I./lib/my

SRC_T	=		$(DIR)main.c \
				tests/tests.c

TEST_BN	=		unit_tests

TFLAGS	=		-lcriterion --coverage -I./include/

all:            $(NAME)

$(NAME):        $(OBJ)
				make -C lib/my/
				$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) -L./lib/my -lmy

clean:
				rm -f $(OBJ)
				make clean -C lib/my/

fclean:         clean
				rm -f $(NAME)
				make fclean -C lib/my

re:             fclean all

tests_run:
	$(MAKE) -C lib/my
	gcc -o $(TEST_N) $(SRC_T) $(LIB) $(TFLAGS)
	./unit_tests
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

debug:			CFLAGS += -g
debug:			re

.PHONY: all clean fclean re tests_run debug