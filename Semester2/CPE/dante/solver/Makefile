##
## EPITECH PROJECT, 2021
## B-CPE-200-NAN-2-1-dante-johan.chrillesen
## File description:
## Makefile
##

SRC		=		main.c \
		  		count.c \
		  		read.c \
		  		my_str_to_wordtab.c \

OBJ      =		$(SRC:.c=.o) \

NAME     =		solver

CFLAGS  =		-Wall -Wshadow -Wextra -I./../include

all:			$(NAME)

$(NAME):		$(OBJ)
				cc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
				rm -f $(OBJ)

fclean:	clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			$(NAME)