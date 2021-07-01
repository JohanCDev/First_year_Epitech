

##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

DIR		=		src/

SRC     =       $(DIR)main.c				\
				$(DIR)search_errors.c		\
				$(DIR)game.c				\
				$(DIR)helper.c				\

OBJ     =       $(SRC:.c=.o)

CC		=		gcc

NAME    =       gameoflife

CFLAGS  =       -Wall -Wshadow -Wextra -I./include -I./lib/my -g

all:            $(NAME)

$(NAME):        $(OBJ)
				make re -C lib/my/
				$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) -L./lib/my -lmy

clean:
				rm -f $(OBJ)
				make clean -C lib/my/

fclean:         clean
				rm -f $(NAME)
				make fclean -C lib/my/

re:             fclean all