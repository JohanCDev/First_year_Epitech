##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

DIR		=		infin_op/

SRC     =       main.c \

OBJ     =       $(SRC:.c=.o)

NAME    =       my_ls

CFLAGS  =       -Wall -Wshadow -Wextra -I/include

all:            $(NAME)

$(NAME):        $(OBJ)
				make re -C lib/my/
				make re -C lib/myprintf/
				cc $(OBJ) -o $(NAME) $(CFLAGS) -L./lib/ -lmy -lmyprintf

tests_run:
				# make re -C Tests/
				unit_tests

clean:
				rm -f $(OBJ)
				make clean -C lib/my/
				make clean -C lib/myprintf/

fclean:         clean
				rm -f $(NAME)
				# make fclean -C Tests/
				make fclean -C lib/my/
				make fclean -C lib/myprintf/

re:             fclean all