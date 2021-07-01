##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC     =		main.c \

OBJ     =       $(SRC:.c=.o)

NAME    =       anagram

CFLAGS  =       -Wall -Wshadow -Wextra -I./include

GCC		=		cc

RM 		=		rm

all:            $(NAME)

$(NAME):        $(OBJ)
				$(GCC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
				$(RM) -f $(OBJ)

fclean:         clean
				$(RM) -f $(NAME)

re:             fclean all