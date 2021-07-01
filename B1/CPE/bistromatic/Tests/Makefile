##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile for unit_test
##

DIR		=		../infin_op/

SRC     =       $(DIR)infin_div.c \
				$(DIR)infin_sub.c \
				$(DIR)infin_add.c \
				$(DIR)infin_mul.c \
				$(DIR)infin_sub_needed.c \
				test_infin_add.c \
				test_infin_sub.c \
				test_infin_mod.c \
				test_infin_div.c \
				test_infin_mul.c \
				test_eval_expr.c \

OBJ     =       $(SRC:.c=.o)

NAME    =       unit_tests

CFLAGS  =       -Wall -Werror -Wshadow -Wextra -I ../include/ --coverage -lcriterion

all:            $(NAME)

$(NAME):        $(OBJ)
				cc $(OBJ) -o $(NAME) $(CFLAGS) -L../lib/ -lmy

clean:
				rm -f $(OBJ)

fclean:         clean
				rm -f $(NAME)
				rm -f *.gcda
				rm -f *.gcno
				rm -f .c.gcov

re:             fclean all

.PHONY: all clean fclean re