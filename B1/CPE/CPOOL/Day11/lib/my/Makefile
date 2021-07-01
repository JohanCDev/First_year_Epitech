##
## EPITECH PROJECT, 2020
## makefile
## File description:
## desc
##

SRC	=	$(shell find -type f -name "*.c")

NAME	=	libmy.a

OBJ	= 	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	mkdir ../../include/
	cp my.h ../../include/
	cp mylist.h ../../include/

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re: fclean all
