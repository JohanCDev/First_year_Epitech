##
## EPITECH PROJECT, 2020
##my_radar
## File description:
## Make file for screensaver
##Makfile

SRC	=	test.c

NAME	=	unit_tests

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I ../include -W -Wall -Wextra -Wshadow --coverage

LFLAGS	=	-lcriterion -lgcov

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LFLAGS) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
