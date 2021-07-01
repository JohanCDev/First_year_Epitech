##
## EPITECH PROJECT, 2020
## makefile
## File description:
## desc
##

SRC		=	$(shell find -type f -name "*.c")

NAME	=	libmy.a

CFLAGS	= 	-Wall -Wshadow -Wextra

OBJ		= 	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re: fclean all
