##
## EPITECH PROJECT, 2020
## Visual Studio Live Share (Workspace)
## File description:
## Makefile
##

DIR		=		src/

SRC     =       $(DIR)main.c \

OBJ     =       $(SRC:.c=.o)

NAME    =       103cipher

CFLAGS  =       -Wall -Wshadow -Wextra -I./include -g

all:            $(NAME)

$(NAME):        $(OBJ)
				make re -C lib/my/
				cc $(OBJ) -o $(NAME) $(CFLAGS) -L./lib/ -lmy -lm

tests_run:
				# make re -C Tests/
				unit_tests

clean:
				rm -f $(OBJ)
				make clean -C lib/my/

fclean:         clean
				rm -f $(NAME)
				# make fclean -C Tests/
				make fclean -C lib/my/

re:             fclean all