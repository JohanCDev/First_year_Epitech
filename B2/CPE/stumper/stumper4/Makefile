##
## EPITECH PROJECT, 2020
##my_radar
## File description:
## Make file for screensaver
##Makfile

SRC	=	src/main.c \
		src/assign_values.c \
		src/fight.c \
		src/open_and_read_file.c \
		src/pokemon.c \
		src/helpers.c \
		src/show_pokemon.c \
		src/free.c

NAME	=	pokemon

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
