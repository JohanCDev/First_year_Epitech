##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

DIR		=		src/

SRC     =       $(DIR)main.c		       \
				$(DIR)initialize.c         \
				$(DIR)initialize_ncurses.c \
				$(DIR)movements.c          \
				$(DIR)do_game.c            \
				$(DIR)end_game.c    	   \
				$(DIR)helper_position.c    \
				$(DIR)check_lost_game.c    \
				$(DIR)helper_map.c         \
				$(DIR)helper.c             \

OBJ     =       $(SRC:.c=.o)

CC		=		gcc

NAME    =       my_sokoban

CFLAGS  =       -Wall -Wshadow -Wextra -I./include -I./lib/my -g

all:            $(NAME)

$(NAME):        $(OBJ)
				make re -C lib/my/
				$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) -L./lib/my -lmy -lncurses

clean:
				rm -f $(OBJ)
				make clean -C lib/my/

fclean:         clean
				rm -f $(NAME)
				make fclean -C lib/my/

re:             fclean all