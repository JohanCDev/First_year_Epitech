##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

DIR		=		src/

SRC     =       $(DIR)commands/rotate.c \
				$(DIR)commands/push_and_pop.c \
				$(DIR)commands/commands.c \
				$(DIR)sort.c \
				$(DIR)main.c \

OBJ     =       $(SRC:.c=.o)

NAME    =       push_swap

CFLAGS  =       -Wall -Wshadow -Wextra -I./include

all:            $(NAME)

$(NAME):        $(OBJ)
				make re -C lib/my/
				cc $(OBJ) -o $(NAME) $(CFLAGS) -L./lib/ -lmy

clean:
				rm -f $(OBJ)
				make clean -C lib/my/

fclean:         clean
				rm -f $(NAME)
				make fclean -C lib/my/

re:             fclean all