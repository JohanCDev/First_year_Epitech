##
## EPITECH PROJECT, 2020
## makefile
## File description:
## desc
##

SRC		=	$(shell find -type f -name "*.c")

NAME	=	libmy.a

OBJ		= 	$(SRC:.c=.o)

CC		= 	gcc

CFLAGS	=	-Wall -Wshadow -Wextra -I../../include

RM		=	rm

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) rc $(NAME) $(OBJ)

clean:
	$(RM) -rf $(OBJ)

fclean:		clean
	$(RM) -rf $(NAME)

re: fclean all
