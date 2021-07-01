##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile lib
##

SRC	=	$(shell find -type f -name "*.c")

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-Wall -Wshadow -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
