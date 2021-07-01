##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

DIR		=		infin_op/

SRC     =       eval_expr.c \
				main.c \
				$(DIR)infin_add.c \
				$(DIR)infin_sub.c \
				$(DIR)infin_div.c \
				$(DIR)infin_mult.c \
				$(DIR)infin_mod.c \

OBJ     =       $(SRC:.c=.o)

NAME    =       calc

CFLAGS  =       -Wall -Wshadow -Wextra -I/include

all:            $(NAME)

$(NAME):        $(OBJ)
				make re -C lib/my/
				cc $(OBJ) -o $(NAME) $(CFLAGS) -L./lib/ -lmy

tests_run:
				make re -C Tests/
				unit_tests

clean:
				rm -f $(OBJ)

fclean:         clean
				rm -f $(NAME)
				make fclean -C Tests/
				rm -f *.gcda
				rm -f *.gcno

re:             fclean all