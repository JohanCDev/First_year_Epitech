##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

DIR		=		sources/

SRC     =       $(DIR)main2.c \

OBJ     =       $(SRC:.c=.o)

NAME    =       a.out

CFLAGS  =       -Wall -Wshadow -Wextra -I/include

all:            $(NAME)

$(NAME):        $(OBJ)
				make -C lib/my/
				cc $(OBJ) -o $(NAME) $(CFLAGS) -L./lib/ -lmy -lm

clean:
				rm -f $(OBJ)
				make clean -C lib/my/

fclean:         clean
				rm -f $(NAME)
				make fclean -C lib/my

re:             fclean all