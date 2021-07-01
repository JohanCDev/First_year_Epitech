##
## EPITECH PROJECT, 2020
##my_radar
## File description:
## Make file for screensaver
##Makfile

SRC	=	src/main.c \
		src/get_map.c \
		src/get_properties.c \
		src/sandpile.c \

NAME	=	sandpile

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I include -W -Wall -Wextra -Wshadow

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -lm

tests_run:
		make -C ./lib/my -I include/
		make -C tests
		./tests/unit_tests

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)
		make fclean -C ./tests
re:		fclean all
