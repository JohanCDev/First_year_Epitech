##
## EPITECH PROJECT, 2020
## makefile
## File description:
## desc
##

SRC	=	$(shell find -type f -name "*.c")

NAME	=	libmyprintf.a

OBJ	= 	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re: fclean all
