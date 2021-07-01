##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## desc
##

SRC		=		./rush3.c	\
				./stumper.c

NAME	=	rush3

CFLAGS	+=	-Wall -Wextra -Werror -I./include/ -L./lib/ -lmy

OBJ	=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):		$(OBJ)
				gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
				rm -f $(OBJ)

fclean:	clean
				rm -f $(NAME)

re:			fclean all

.PHONY:	all	clean	fclean re
